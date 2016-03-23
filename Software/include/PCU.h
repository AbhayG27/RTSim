#pragma once
#include <entities.h>
#define RAY_PRECOMPUTE_LATENCY 10
class PCU
{
public:
	PCU();
	~PCU();
	int precompute(ray r,precomputedRay& pr);
	int precompute(ray r[], precomputedRay pr[],int size);
private:

};
