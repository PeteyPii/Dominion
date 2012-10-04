#pragma once

#include "GameplayState.h"
#include "OptionsState.h"
#include "MainMenuState.h"

class DominionApp
{
public:
	static DominionApp *dominionApp;

	DominionApp();
	~DominionApp();

	void begin();
};
