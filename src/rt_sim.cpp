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
	mem_addr_t ad = 10;
	myMem.writeLittle(TREE_START_OFFSET_LOC, sizeof(mem_addr_t), &ad);
	myMem.writeLittle(TREE_LEAF_START_OFFSET_LOC, sizeof(mem_addr_t), &ad);
	myMem.writeLittle(TRIANGLE_START_OFFSET_LOC, sizeof(mem_addr_t), &ad);
	myMem.writeLittle(RAY_START_OFFSET_LOC, sizeof(mem_addr_t), &ad);
	myMem.writeLittle(SCRATCH_START_OFFSET_LOC, sizeof(mem_addr_t), &ad);
	//mem_word_t temp,w = 'a';
	buffer<ray> rays(RAY_BUF_SIZE, 1, 1, 1);
	buffer<precomputedRay> precomputedRays(RAY_BUF_SIZE, 1, 1, 1);
	reorder<precomputedRay, boundingVol> preComBounVolReorder(RAY_BUF_SIZE, 1, 1, 1);
	reorder<ray, triangle> preComTriReorder(RAY_BUF_SIZE, 1, 1, 1);
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
	mem_addr_t rayOff = rayStartOff,treeOff=treeStartOff;
	ray tray;
	precomputedRay tpray;
	treeNode tTNode;
	bool bviInt;
	//The main loop
	while (rayOff < scratchStartOff)//for every ray
	{
		myMem.readLittle(rayOff, sizeof(ray), &tray);
		pcu.precompute(tray, tpray);
		myMem.readLittle(treeOff, sizeof(treeNode), &tTNode);
		bvi.intersect(tpray, tTNode.bVol, bviInt);
		if (bviInt)
		{
			//go further down the tree
			if (1)//tTNode.isLeaf == 1)
			{
				//test intersection with triangles

			}
			else
			{

				treeOff = tTNode.children;//go to children, tests with only one child
			}
		}
		else
		{
			//ray misses the tree
		}
		rayOff +=sizeof(ray);//random
	}
	cout << "total cycles taken: " << cycles << endl;
	system("pause");
	return 0;
}