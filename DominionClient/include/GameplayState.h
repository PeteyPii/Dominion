#pragma once

#include "State.h"
#include <iostream>

class GameplayState : public State
{
public:
	GameplayState();
	~GameplayState();

	void runState();
};
