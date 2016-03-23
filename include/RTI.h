#pragma once
#include <entities.h>
#define RAY_TRI_INTERSECT_LATENCY 10
class RTI
{
public:
	RTI();
	~RTI();
	int intersect(const ray r, const triangle b, bool& result);
	int intersect(const ray r[], const triangle b[], bool result[], const int size);
private:

};
