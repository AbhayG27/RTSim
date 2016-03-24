#include "memcntrl.h"
memcntrl::memcntrl(string name)
{
	myDram.open(name);
}

memcntrl::~memcntrl()
{
}

int memcntrl::read(mem_addr_t addr, mem_word_t& word)
{
	mem_block_t block;
	int lat=myDram.read(addr, 1, &block);
	word = block.words[0];
	return lat;
}

int memcntrl::write(mem_addr_t addr, mem_word_t word)
{
	mem_block_t block;
	int lat = myDram.read(addr, 1, &block);
	block.words[0]=word;
	lat+=myDram.write(addr, 1, &block);
	return lat;
}

int memcntrl::readLittle(mem_addr_t addr, int size, void* buf)
{
	mem_word_t temp;
	mem_word_t * tbuf = (mem_word_t*)buf;
	unsigned long cycles = 0;
	int count = size / sizeof(mem_word_t);
	for (int i = 0; i < count; i++)
	{
		cycles += this->read(addr + i, temp);
		tbuf[i]= temp;
		//*tbuf = *tbuf << i*sizeof(mem_word_t);
	}
	return cycles;
}

int memcntrl::readBig(mem_addr_t addr, int size, void* buf)
{
	mem_word_t temp;
	mem_word_t * tbuf = (mem_word_t*)buf;
	unsigned long cycles = 0;
	int count = size / sizeof(mem_word_t);
	for (int i = 0; i < count; i++)
	{
		cycles += this->read(addr + i, temp);
		tbuf[count - i - 1] = temp;
		//*tbuf = *tbuf << (count - i - 1)*sizeof(mem_word_t);
	}
	return cycles;
}

int memcntrl::writeLittle(mem_addr_t addr, int size, void* buf)
{
	mem_word_t temp;
	mem_word_t * tbuf = (mem_word_t*)buf;
	unsigned long cycles = 0;
	int count = size / sizeof(mem_word_t);
	for (int i = 0; i < count; i++)
	{
		temp = tbuf[i];
		cycles += this->write(addr + i, temp);
		//*tbuf = *tbuf << (count - i - 1)*sizeof(mem_word_t);
	}
	return cycles;
}

int memcntrl::writeBig(mem_addr_t addr, int size, void* buf)
{
	mem_word_t temp;
	mem_word_t * tbuf = (mem_word_t*)buf;
	unsigned long cycles = 0;
	int count = size / sizeof(mem_word_t);
	for (int i = 0; i < count; i++)
	{
		temp = tbuf[count - i - 1];
		cycles += this->write(addr + i, temp);
		//*tbuf = *tbuf << (count - i - 1)*sizeof(mem_word_t);
	}
	return cycles;
}