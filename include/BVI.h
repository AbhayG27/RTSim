#pragma once
#define RAY_BVI_INTERSECT_LATENCY 10
#include <entities.h>
class BVI
{
public:
	BVI();
	~BVI();

	int intersect( precomputedRay r,  boundingVol b, bool& result);
	int intersect( precomputedRay r[],  boundingVol b[], bool result[], int size);
private:
};