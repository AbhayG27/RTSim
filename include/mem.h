#pragma once
#define BLOCK_SIZE 4
typedef unsigned long mem_addr_t;
typedef char mem_word_t;
struct mem_block_t
{
	mem_word_t words[BLOCK_SIZE];
};
#define MEM_SIZE 1024*1024*sizeof(mem_block_t) //64kb memory
#define OFFSET_SIZE sizeof(mem_block_t)

//Memory layout
#define TREE_START_OFFSET_LOC			0
#define TREE_LEAF_START_OFFSET_LOC		TREE_START_OFFSET_LOC+sizeof(mem_addr_t)
#define TRIANGLE_START_OFFSET_LOC		TREE_LEAF_START_OFFSET_LOC+sizeof(mem_addr_t)
#define RAY_START_OFFSET_LOC			TRIANGLE_START_OFFSET_LOC+sizeof(mem_addr_t)
#define SCRATCH_START_OFFSET_LOC		RAY_START_OFFSET_LOC+sizeof(mem_addr_t)
