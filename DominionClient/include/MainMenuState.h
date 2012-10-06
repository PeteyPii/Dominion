#pragma once

#include "State.h"
#include <iostream>

class MainMenuState : public State
{
public:
	MainMenuState();
	~MainMenuState();

	void runState();
};
