#pragma once
#include <map>
#include <mem.h>
#define CACHE_SIZE 1024 //8kb cache
#define CACHE_NUM_WAYS 1
typedef unsigned long cache_tag_t;
typedef unsigned long cache_index_t;
#define CACHE_READ_LATENCY 1
#define CACHE_WRITE_LATENCY 1
#define CLEAN 0
#define DIRTY 1
using namespace std;
struct cache_data_t{
	cache_index_t index;
	mem_block_t block;
	short status;
};
class cache
{
	map<cache_tag_t,cache_data_t> cacheFile;
public:
	cache();
	int exists(mem_addr_t);
	int get(mem_addr_t, mem_block_t &);
	int put(mem_addr_t, mem_block_t);
	~cache();
};
