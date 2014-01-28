#pragma once

#include "GameplayState.h"
#include "InstructionsState.h"
#include "MainMenuState.h"

class DominionApp
{
public:
	static DominionApp *dominionApp;

	MainMenuState mainMenuState;
	GameplayState gameplayState;
	InstructionsState instructionsState;

	DominionApp();
	~DominionApp();

	void begin();
};
