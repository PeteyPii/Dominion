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
	ClickableText seeInstructionsText;
	ClickableText exitText;

	bool leftButtonDown;

	MainMenuState();
	~MainMenuState();

	virtual void runTextOnly();

	virtual void step();
	virtual void draw();
	virtual void eventMouseMoved(sf::Event mouseEvent);
	virtual void eventMouseButtonPressed(sf::Event mouseEvent);
	virtual void eventMouseButtonReleased(sf::Event mouseEvent);
	virtual void eventKeyPressed(sf::Event keyEvent);

	void updateButtons(sf::Vector2f mousePosition, bool isLeftButtonPressed);
	void connectToServer();
	void seeInstructions();
	void exit();
};
