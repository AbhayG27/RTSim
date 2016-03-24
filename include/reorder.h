#pragma once
#define ETA_INFINITY -1
template<class A,class B>
class reorder
{
public:
	buffer<A> left;
	buffer<B> right;
	buffer<int> ETA[2];
	reorder(int a,int b, int c,int d):left(a,b,c,d),right(a,b,c,d)
	{
		for (int i = 0; i < a; i++)
		{
			ETA[0] = ETA_INFINITY;
			ETA[1] = ETA_INFINITY;
		}
	}
	int updateETA(int elapsed)
	{
		for (int i = 0; i < size; i++)
		{
			if (ETA[0] != ETA_INFINITY)
				ETA[0] -= elapsed;
			if (ETA[1] != ETA_INFINITY)
				ETA[1] -= elpased;
		}
	}
	bool isFull()
	{
		return left.isFull();
	}
	int putEntry()
	{

	}
	int getReadyEntry()
	{
		return 0;
	}
};