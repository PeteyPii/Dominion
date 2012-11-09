#pragma once

#include "State.h"
#include <SFML/Graphics.hpp>

class DominionApp;

class MainMenuState : public State
{
public:
	DominionApp *app;

	sf::Sprite background;

	MainMenuState();
	~MainMenuState();

	void runTextOnly();

	void step();
	void draw();
};
