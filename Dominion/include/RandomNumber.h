#pragma once

#include "mtrand.h"
#include <ctime>

class RandomNumber
{
public:
	static MTRand_int32 random;

	RandomNumber();
	~RandomNumber();
};
