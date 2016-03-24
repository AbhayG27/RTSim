#include <dram.h>
#include <iostream>
using namespace std;
dram::dram()
{

}
dram::dram(string name) {
		file.open(name.c_str(), std::fstream::in| std::fstream::out|std::fstream::binary);
}
int dram::open(string name)
{
	file.open(name.c_str(), std::fstream::in | std::fstream::out | std::fstream::binary);
	return 0;
}
int dram::read(mem_addr_t from, int count, mem_block_t* buf)
{
	file.seekg(from);
	file.read((char*)buf, count*sizeof(mem_block_t));
	return DRAM_READ_LATENCY;
}
int dram::write(mem_addr_t from, int count, mem_block_t* buf)
{
	file.seekg(from);
	//cout << "lowest level writing:" << (int)buf->words[0] << (int)buf->words[1] << (int)buf->words[2] << (int)buf->words[3] << endl;
	file.write((char*)buf, count*sizeof(mem_block_t));
	return DRAM_WRITE_LATENCY;
}
dram::~dram()
{
	file.close();
}

