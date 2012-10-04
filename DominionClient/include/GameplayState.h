#pragma once

#include "State.h"

class GameplayState : public State
{
public:
	GameplayState();
	~GameplayState();

	void runState();
};
