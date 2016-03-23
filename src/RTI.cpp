#include <RTI.h>
RTI::RTI()
{
}

RTI::~RTI()
{
}

int RTI::intersect(const ray r, const triangle b, bool& result)
{
	return RAY_TRI_INTERSECT_LATENCY;
}

int RTI::intersect(const ray r[], const triangle b[], bool result[], const int size)
{
	return RAY_TRI_INTERSECT_LATENCY;
}