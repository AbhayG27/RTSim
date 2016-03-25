#pragma once
//Currently implementing a circular buffer
#include <vector>
using namespace std;
template<class b_type>
class buffer
{
	int size;
	vector<b_type> myBuf;
	int safe;
	int STORE_LATENCY, LOAD_LATENCY;
public:
	buffer()
	{

	}
	buffer(int sz, int sl, int ll,int margin):myBuf(sz)
	{
		size = sz;
		STORE_LATENCY = sl;
		LOAD_LATENCY = ll;
		safe = safe;
	}
	int get(b_type& dat)
	{
		dat=myBuf.get(0);
		myBuf.pop_top();
		return LOAD_LATENCY;
	}
	int put(b_type dat)
	{
		myBuf.push_back(dat);
		return STORE_LATENCY;
	}
	bool isFull()
	{
		if (myBuf.size() == size)
			return true;
		else
			return false;
	}
	bool isEmpty()
	{
		if (myBuf.size()==0)
			return true;
		else
			return false;
	}
	bool almostFull()
	{
		if (myBuf.size()+safe==size)
			return true;
		else
			return false;
	}
	~buffer()
	{
		
	}
};