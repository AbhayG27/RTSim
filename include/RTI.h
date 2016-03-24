#pragma once
#include <entities.h>
#define RAY_TRI_INTERSECT_LATENCY 10
class RTI
{
public:
	RTI();
	~RTI();
	int intersect(ray r,  triangle b, TYPE t, bool& result);
	int intersect(ray r[],  triangle b[], TYPE t[], bool result[],int size);
private:

};
