#pragma once

#include "ClickableText.h"
#include "State.h"
#include "TextBox.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class DominionApp;

class InstructionsState : public State
{
public:
	DominionApp *app;

	sf::Sprite background;
	sf::Text titleText;
	ClickableText backText;
	TextBox instructionsTextBox;

	bool leftButtonDown;

	InstructionsState();
	~InstructionsState();

	void runTextOnly();

	void step();
	void draw();
	virtual void eventMouseMoved(sf::Event mouseEvent);
	virtual void eventMouseButtonPressed(sf::Event mouseEvent);
	virtual void eventMouseButtonReleased(sf::Event mouseEvent);
	virtual void eventMouseWheelMoved(sf::Event mouseEvent);
	virtual void eventKeyPressed(sf::Event keyEvent);

	void updateButton(sf::Vector2f mousePosition, bool isLeftButtonPressed);
	void back();
};
