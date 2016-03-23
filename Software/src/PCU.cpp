#include <PCU.h>
PCU::PCU()
{
}

PCU::~PCU()
{
}

int PCU::precompute(ray r, precomputedRay& pr)
{
	return RAY_PRECOMPUTE_LATENCY;
}

int PCU::precompute(ray r[], precomputedRay pr[], int size)
{
	return RAY_PRECOMPUTE_LATENCY;
}
