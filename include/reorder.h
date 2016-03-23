#pragma once
#define N_FLAGS 10
template<class A,class B>
class reorder
{
public:
	buffer<A> left;
	buffer<B> right;
	buffer<int> flags[N_FLAGS];
	reorder(int a,int b, int c)
	{
		left.init(a,b,c);
		right.init(a, b, c);
	}
	int getReadyEntry()
	{
		return 0;
	}
};