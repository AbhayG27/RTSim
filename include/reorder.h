#pragma once
#include <vector>
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
	reorder(int a,int b, int c,int d)
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