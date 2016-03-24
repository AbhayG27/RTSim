#pragma once
template<class b_type>
class buffer
{
	int size;
	b_type *myBuf;
	int rpos, wpos,safe;
	int STORE_LATENCY, LOAD_LATENCY;
public:
	buffer()
	{
		rpos = -1; wpos = -1;
	}
	buffer(int sz, int sl, int ll,int margin)
	{
		myBuf = (b_type*)malloc(sizeof(b_type)*sz);
		size = sz;
		STORE_LATENCY = sl;
		LOAD_LATENCY = ll;
		safe = safe;
		rpos = -1; wpos = -1;
	}
	int read(b_type& dat)
	{
		dat=myBuf[rpos++%N]
		return LOAD_LATENCY;
	}
	int write(b_type dat)
	{
		myBuf[wpos++%N] = dat;
		return STORE_LATENCY;
	}
	bool isFull()
	{
		if (wpos - rpos < size)
			return false;
		else
			return true;
	}
	bool isEmpty()
	{
		if (rpos == -1 && wpos == -1)
			return false;
	}
	bool almostFull()
	{
		if (wpos-rpos-safe<size)
			return true;
		else
			return false;
	}
	~buffer()
	{
		free(myBuf);
	}
};