#include <BVI.h>
BVI::BVI()
{
}

BVI::~BVI()
{
}
int BVI::intersect(const precomputedRay r,const boundingVol b, bool& result)
{
	return RAY_BVI_INTERSECT_LATENCY;
}
int BVI::intersect(const precomputedRay r[],const boundingVol b[], bool result[], const int size)
{
	return RAY_BVI_INTERSECT_LATENCY;
}