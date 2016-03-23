#include "dram.h"
dram::dram()
{

}
dram::dram(string name) {
		file.open(name.c_str(), ios_base::in|ios_base::out);
}
int dram::open(string name)
{
	file.open(name.c_str(), ios_base::in | ios_base::out);
	return 0;
}
int dram::read(mem_addr_t from, int count, mem_block_t* buf)
{
	file.seekg(from);
	file.read((char*)buf, count*sizeof(mem_block_t));
	return DRAM_READ_LATENCY;
}
int dram::write(mem_addr_t from, int count, mem_block_t buf)
{
	file.seekg(from);
	file.write((char*)&buf, count*sizeof(mem_block_t));
	return DRAM_WRITE_LATENCY;
}
dram::~dram()
{
	file.close();
}

