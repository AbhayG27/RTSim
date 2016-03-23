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
	lat+=myDram.write(addr, 1, block);
	return lat;
}

int memcntrl::readLittle(mem_addr_t addr, int size, void* buf)
{
	return 0;// return appropriate latency
}

int memcntrl::readBig(mem_addr_t addr, int size, void* buf)
{
	return 0;// return appropriate latency
}

int memcntrl::writeLittle(mem_addr_t addr, int size, void* buf)
{
	return 0;// return appropriate latency
}

int memcntrl::writeBig(mem_addr_t addr, int size, void* buf)
{
	return 0;// return appropriate latency
}