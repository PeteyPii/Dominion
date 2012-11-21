#pragma once

#include "ClickableText.h"
#include "State.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class DominionApp;

class MainMenuState : public State
{
public:
	DominionApp *app;

	sf::Sprite background;
	sf::Text titleText;
	ClickableText connectToServerText;
	ClickableText exitText;

	bool leftButtonDown;

	MainMenuState();
	~MainMenuState();

	void runTextOnly();

	void step();
	void draw();
	void eventMouseMoved(sf::Event mouseEvent);
	void eventMouseButtonPressed(sf::Event mouseEvent);
	void eventMouseButtonReleased(sf::Event mouseEvent);

	void updateButtons(sf::Vector2f mousePosition, bool isLeftButtonPressed);
	void connectToServer();
	void exit();
};
