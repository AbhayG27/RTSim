#include <PCU.h>
PCU::PCU()
{
}

PCU::~PCU()
{
}

int PCU::precompute(ray r, precomputedRay& pr)
{
	for (int i = 0; i < 7; i++)
	{
		pr.precomp[i].dat[0] = r.dir.dot(planeNorms[i]);
		pr.precomp[i].dat[1] = r.orig.dot(planeNorms[i]);
	}
	return RAY_PRECOMPUTE_LATENCY;
}

int PCU::precompute(ray r[], precomputedRay pr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		precompute(r[i], pr[i]);
	}
	return RAY_PRECOMPUTE_LATENCY;
}
