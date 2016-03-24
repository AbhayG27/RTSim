#include <BVI.h>
#include <helper.h>
#define epsilon 1e-7
BVI::BVI()
{
}

BVI::~BVI()
{
}
int BVI::intersect(precomputedRay r,boundingVol b, bool& result)
{
	TYPE tnear[7];
	TYPE tfar[7];
	result = false;
	for (int i = 0; i < 7; i++)
	{
		if (r.precomp[i].dat[0]>epsilon)
		{
			tnear[i] = (b.planeD[0].dat[0] - r.precomp[i].dat[1]) / r.precomp[i].dat[0];//the assignments in the following lines get interchanged 
			tfar[i] = (b.planeD[0].dat[1] - r.precomp[i].dat[1]) / r.precomp[i].dat[0];//depending upon the condition, please verify
		}
		else if (r.precomp[i].dat[0] < -epsilon)
		{
			tnear[i] = (b.planeD[0].dat[1] - r.precomp[i].dat[1]) / r.precomp[i].dat[0];
			tfar[i] = (b.planeD[0].dat[0] - r.precomp[i].dat[1]) / r.precomp[i].dat[0];
		}
		else
		{
			//have to verify
			result = false;
			return RAY_BVI_INTERSECT_LATENCY;
		}
	}
	if (min(tnear, 7) < max(tfar, 7))
		result = true;
	return RAY_BVI_INTERSECT_LATENCY;
}
int BVI::intersect(precomputedRay r[],boundingVol b[], bool result[], int size)
{
	for (int i = 0; i < size; i++)
	{
		intersect(r[i], b[i], result[i]);
	}
	return RAY_BVI_INTERSECT_LATENCY;
}