#pragma once

#include "ClientResources.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class ConnectToAServerState;
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
	ConnectToAServerState *connectToAServerState;
	GameplayState *gameplayState;
	InstructionsState *instructionsState;

	State *currentState;

	sf::RenderWindow *window;

	bool keepRunning;

	DominionApp();
	~DominionApp();

	void begin();
	void stop();
};
