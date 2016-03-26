#include "memcntrl.h"
#ifdef DEBUG
#include <assert.h>
#endif
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
	//cout << "reading:" << (int)block.words[0] << (int)block.words[1] << (int)block.words[2] << (int)block.words[3] << endl;
	return lat;
}

int memcntrl::write(mem_addr_t addr, mem_word_t word)
{
	mem_block_t block;
	int lat = myDram.read(addr, 1, &block);
	block.words[0]=word;
	//cout <<"reading before writing:"<<(int)block.words[0]<<(int)block.words[1]<<(int)block.words[2]<<(int)block.words[3]<<endl;
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
		cycles += read(addr + i, temp);
		tbuf[i]= temp;
		//cout << (int)temp << ":value r" << endl;
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
		cycles += read(addr + i, temp);
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
		cycles += write(addr + i, temp);
		//cout <<(int)temp<<":value"<<endl;
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
		cycles += write(addr + i, temp);
		//*tbuf = *tbuf << (count - i - 1)*sizeof(mem_word_t);
	}
	return cycles;
}
#ifdef DEBUG
namespace memCntrl
{
	int main()//memtest
	{
		unsigned long cycles = 0;
		memcntrl myMem("dram.txt");
		mem_addr_t ad = 10;
		myMem.writeLittle(0, sizeof(mem_addr_t), &ad);
		mem_addr_t treeStartOff = 0;
		cycles += myMem.readLittle(0, sizeof(mem_addr_t), &treeStartOff);
		assert(ad==treeStartOff);
		return 0;
	}
}
#endif