#pragma once
using namespace std;
#include <fstream>
#include "mem.h"
#define DRAM_READ_LATENCY 10
#define DRAM_WRITE_LATENCY 10
//Every function returns the latency of the operation
class dram {
	private:
		fstream file;
	public:
		dram();
		dram(string name);
		int open(string);
		int read(mem_addr_t from, int count, mem_block_t*);
		int write(mem_addr_t from, int count, mem_block_t*);
		~dram();
};
