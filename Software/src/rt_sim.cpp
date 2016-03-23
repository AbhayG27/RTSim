#include <iostream>
#include <memcntrl.h>
#include <entities.h>
#include <buffer.h>
#include <reorder.h>
#include <RTI.h>
#include <BVI.h>
#include <PCU.h>
#define RAY_BUF_SIZE 10
using namespace std;
unsigned long readAddrFromMem(memcntrl& myMem,mem_addr_t addr,mem_addr_t &val)//Have to replace with a neater way see: memcntrl readLittle readBig
{
	mem_word_t temp;
	unsigned long cycles = 0;
	int count = sizeof(mem_addr_t) / sizeof(mem_word_t);
	for (int i = 0; i < count; i++)
	{
		cycles += myMem.read(addr + i, temp);
		val |= temp;
		val = val << (count - i - 1)*sizeof(mem_word_t);
	}
	return cycles;
}
int main(int argc, char * argv[])
{
	unsigned long cycles=0;
	memcntrl myMem("dram.txt");
	//mem_word_t temp,w = 'a';
	buffer<ray> rays(RAY_BUF_SIZE, 1, 1);
	buffer<precomputedRay> precomputedRays(RAY_BUF_SIZE, 1, 1);
	reorder<precomputedRay, boundingVol> preComBounVolReorder(RAY_BUF_SIZE, 1, 1);
	reorder<ray, triangle> preComTriReorder(RAY_BUF_SIZE, 1, 1);
	BVI bvi;
	RTI rti;
	PCU pcu;
	mem_addr_t treeStartOff=0, leafStartOff=0, triangleStartOff=0, rayStartOff=0,scratchStartOff=0;
	cycles += readAddrFromMem(myMem, TREE_START_OFFSET_LOC, treeStartOff);
	cycles += readAddrFromMem(myMem, TREE_LEAF_START_OFFSET_LOC, leafStartOff);
	cycles += readAddrFromMem(myMem, TRIANGLE_START_OFFSET_LOC, triangleStartOff);
	cycles += readAddrFromMem(myMem, RAY_START_OFFSET_LOC, rayStartOff);
	cycles += readAddrFromMem(myMem, SCRATCH_START_OFFSET_LOC, scratchStartOff);
	cout << treeStartOff << endl << leafStartOff << endl << triangleStartOff << endl << rayStartOff << endl << scratchStartOff<<endl;
	mem_addr_t iter = rayStartOff;
	//The main loop
	while (iter < scratchStartOff)//for every ray
	{
		iter++;//random
	}
	/*mem_block_t a;
	strcpy_s(a.words, "Abh");
	dram dramOut("hello.txt");
	int latency=dramOut.write(0, 10, a);
	cout << "done" << endl;*/
	//myMem.write(0, w);
	cout << "total cycles taken: " << cycles << endl;
	system("pause");
	return 0;
}