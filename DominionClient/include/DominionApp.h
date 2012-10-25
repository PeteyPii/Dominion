#pragma once

#include "GameplayState.h"
#include "InstructionsState.h"
#include "MainMenuState.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class DominionApp
{
public:
	static DominionApp *dominionApp;

	MainMenuState mainMenuState;
	GameplayState gameplayState;
	InstructionsState instructionsState;

	sf::Window window;

	DominionApp();
	~DominionApp();

	void begin();
};
