#pragma once

#include "singletonBase.h"
#include <time.h>

class randomFunction : public singletonBase<randomFunction>
{
public:
	randomFunction()
	{
		srand(GetTickCount());
	}
	~randomFunction()
	{

	}

	//GetInt
	inline int getInt(int num) { return rand() % num; }
	inline int getFromIntTo(int fromNum, int toNum) { return (rand() % (toNum - fromNum + 1) + fromNum); }
	inline float getFloat(float num) { return ((float)rand() / (float)RAND_MAX) * num; }
	inline float getFromFloatTo(float fromNum, float toNum) 
	{ 
		return ((float)rand() / (float)RAND_MAX) * toNum + fromNum; 
	}
};