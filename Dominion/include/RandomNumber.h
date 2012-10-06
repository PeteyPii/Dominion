#pragma once

#include "mtrand.h"

class RandomNumber
{
public:
	static MTRand_int32 random;

	RandomNumber();
	~RandomNumber();
};
