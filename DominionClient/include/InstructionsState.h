#pragma once

#include "State.h"

class InstructionsState : public State
{
public:
	InstructionsState();
	~InstructionsState();

	void runState();
};
