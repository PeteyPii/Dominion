#pragma once

#include "ClientResources.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class GameplayState;
class InstructionsState;
class MainMenuState;
class State;

class DominionApp
{
public:
	static DominionApp *dominionApp;

	ClientResources resources;

	MainMenuState *mainMenuState;
	GameplayState *gameplayState;
	InstructionsState *instructionsState;

	State *currentState;

	sf::RenderWindow *window;

	DominionApp();
	~DominionApp();

	void begin();
};
