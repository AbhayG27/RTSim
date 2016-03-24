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
int main(int argc, char * argv[])
{
	unsigned long cycles=0;
	memcntrl myMem("dram.txt");
	/*char a = 0;
	for (int i = 0; i < pow(2, sizeof(mem_addr_t)*8); i++)
		myMem.writeLittle(i, 1, &a);*/
	mem_addr_t ad = 0;
	myMem.writeLittle(TREE_START_OFFSET_LOC, sizeof(mem_addr_t), &ad);
	myMem.writeLittle(TREE_LEAF_START_OFFSET_LOC, sizeof(mem_addr_t), &ad);
	myMem.writeLittle(TRIANGLE_START_OFFSET_LOC, sizeof(mem_addr_t), &ad);
	myMem.writeLittle(RAY_START_OFFSET_LOC, sizeof(mem_addr_t), &ad);
	myMem.writeLittle(SCRATCH_START_OFFSET_LOC, sizeof(mem_addr_t), &ad);
	//mem_word_t temp,w = 'a';
	buffer<ray> rays(RAY_BUF_SIZE, 1, 1);
	buffer<precomputedRay> precomputedRays(RAY_BUF_SIZE, 1, 1);
	reorder<precomputedRay, boundingVol> preComBounVolReorder(RAY_BUF_SIZE, 1, 1);
	reorder<ray, triangle> preComTriReorder(RAY_BUF_SIZE, 1, 1);
	BVI bvi;
	RTI rti;
	PCU pcu;
	mem_addr_t treeStartOff=0, leafStartOff=0, triangleStartOff=0, rayStartOff=0,scratchStartOff=0;
	cycles += myMem.readLittle(TREE_START_OFFSET_LOC,sizeof(mem_addr_t), &treeStartOff);
	cycles += myMem.readLittle(TREE_LEAF_START_OFFSET_LOC,sizeof(mem_addr_t), &leafStartOff);
	cycles += myMem.readLittle(TRIANGLE_START_OFFSET_LOC, sizeof(mem_addr_t), &triangleStartOff);
	cycles += myMem.readLittle(RAY_START_OFFSET_LOC, sizeof(mem_addr_t), &rayStartOff);
	cycles += myMem.readLittle(SCRATCH_START_OFFSET_LOC, sizeof(mem_addr_t), &scratchStartOff);
	cout << treeStartOff << endl << leafStartOff << endl << triangleStartOff << endl << rayStartOff << endl << scratchStartOff<<endl;
	mem_addr_t iter = rayStartOff;
	//The main loop
	while (iter < scratchStartOff)//for every ray
	{
		iter+=4;//random
	}
	/*mem_block_t a;
	strcpy_s(a.words, "Abh");
	dram dramOut("hello.txt");
	int latency=dramOut.write(0, 10, a);
	cout << "done" << endl;*/
	//myMem.write(0, w);
	//cout << "size of char" << sizeof(char);
	/*mem_word_t m=0;
	myMem.write(0, 65);
	myMem.write(1, m);
	myMem.write(2, m);
	myMem.write(3, m);*/
	/*dram myDram("hello1.txt");
	mem_block_t m;
	m.words[0] = 65;
	myDram.write(0,1,&m);
	myDram.read(0, 1, &m);
	cout << m.words[0] << endl;*/
	cout << "total cycles taken: " << cycles << endl;
	system("pause");
	return 0;
}