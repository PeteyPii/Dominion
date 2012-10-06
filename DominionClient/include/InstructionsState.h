#pragma once

#include "State.h"
#include <iostream>

class InstructionsState : public State
{
public:
	InstructionsState();
	~InstructionsState();

	void runState();
};
