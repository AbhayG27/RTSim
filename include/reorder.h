#pragma once
#include <vector>
using namespace std;
#define ETA_INFINITY -1
template<class A,class B>
class reorder
{
public:
	struct entry {
		A left;
		B right;
		int ETA[2];
	};
	vector<entry> eBuffer;
	reorder(int sz,int sl, int ll,int safe):eBuffer(sz)
	{

	}
	int updateETA(int elapsed)
	{

	}
	bool isFull()
	{
		return eBuffer.isFull();
	}
	bool isEmpty()
	{
		return eBuffer.isEmpty();
	}
	int putEntry(A lef,B rig, int ETA1,int ETA2)
	{
		//eBuffer.write
	}
	int getReadyEntry()
	{
		return 0;
	}
	~reorder()
	{

	}
};