#pragma once
#define RAY_BVI_INTERSECT_LATENCY 10
#include <entities.h>
class BVI
{
public:
	BVI();
	~BVI();

	int intersect(const precomputedRay r, const boundingVol b, bool& result);
	int intersect(const precomputedRay r[], const boundingVol b[], bool result[], const int size);
private:
};