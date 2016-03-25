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
	int STORE_LATENCY, LOAD_LATENCY,margin;
	vector<entry> eBuffer;
	reorder(int sz,int sl, int ll,int safe):eBuffer(sz)
	{
		for (int i = 0; i < eBuffer.size(); i++)
		{
			eBuffer.at(i).ETA[0] = ETA_INFINITY;
			eBuffer.at(i).ETA[1] = ETA_INFINITY;
		}
		STORE_LATENCY = sl;
		LOAD_LATENCY = ll;
		margin = safe;
	}
	int updateETA(int elapsed)
	{
		for (int i = 0; i < eBuffer.size(); i++)
		{
			eBuffer.at(i).ETA[0] -= elapsed ;
			eBuffer.at(i).ETA[1] -= elapsed;
		}
	}
	bool isFull()
	{
		if (eBuffer.size() == size)
			return true;
		else
			return false;
	}
	bool isEmpty()
	{
		if (eBuffer.size() == 0)
			return true;
		else
			return false;
	}
	int putEntry(A lef,B rig, int ETA1,int ETA2)
	{
		entry* temp=new entry;
		temp->left = lef;
		temp->right = rig;
		temp->ETA[0] = ETA1;
		temp->ETA[1] = ETA2;
		eBuffer.push_back(*temp);
		return STORE_LATENCY;
	}
	bool isAlmostFull()
	{
		if (eBuffer.size() + safe == size)
			return true;
		else
			return false;
	}
	int getReadyEntry(A lef,B rig)
	{
		entry * temp;
		for (int i = 0; i < eBuffer.size(); i++)
			if (eBuffer.at(i).ETA[0] == 0 && eBuffer.at(i).ETA[1] == 0)
			{
				lef = eBuffer.at(i).left;
				rig = eBuffer.at(i).right;
				temp = &ebuffer.at(i);
				delete temp;
				eBuffer.erase(eBuffer.begin() + i);
				break;
			}
		return 0;
	}
	~reorder()
	{

	}
};