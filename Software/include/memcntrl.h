#pragma once
#include "dram.h"
#include "cache.h"
class memcntrl
{
public:
	memcntrl(string name);
	~memcntrl();
	int read(mem_addr_t,mem_word_t&);
	int readLittle(mem_addr_t, int size, void*);//third argument can be of any type of the appropriate size
	int readBig(mem_addr_t, int size, void*);
	int write(mem_addr_t,mem_word_t);
	int writeLittle(mem_addr_t, int size, void*);
	int writeBig(mem_addr_t, int size, void*);
private:
	dram myDram; cache myCache;
};

