#pragma once
template<class b_type>
class buffer
{
	int size;
	b_type *myBuf;
	int STORE_LATENCY, LOAD_LATENCY;
public:
	buffer()
	{

	}
	buffer(int sz, int sl, int ll)
	{
		myBuf = (b_type*)malloc(sizeof(b_type)*sz);
		size = sz;
		STORE_LATENCY = sl;
		LOAD_LATENCY = ll;
	}
	void init(int sz, int sl, int ll)
	{
		myBuf = (b_type*)malloc(sizeof(b_type)*sz);
		size = sz;
		STORE_LATENCY = sl;
		LOAD_LATENCY = ll;
	}
	int store()
	{
		return STORE_LATENCY;
	}
	int load()
	{
		return LOAD_LATENCY;
	}
	~buffer()
	{
		free(myBuf);
	}
};