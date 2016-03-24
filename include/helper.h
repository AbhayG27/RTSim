#pragma once
#include <common.h>
TYPE min(TYPE arr[], int size)
{
	int i = 0;
	TYPE ret = arr[i];
	for (i = 0; i < size; i++)
		if (arr[i] < ret)
			ret = arr[i];
	return ret;
}
TYPE max(TYPE arr[], int size)
{
	int i = 0;
	TYPE ret = arr[i];
	for (i = 0; i < size; i++)
		if (arr[i] < ret)
			ret = arr[i];
	return ret;
}