#pragma once

#include "State.h"

class OptionsState : public State
{
public:
	OptionsState();
	~OptionsState();

	void runState();
};
