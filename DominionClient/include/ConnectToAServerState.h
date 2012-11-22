#pragma once

#include "ClickableText.h"
#include "State.h"
#include "TextBox.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class DominionApp;

class ConnectToAServerState : public State
{
public:
	DominionApp *app;

	sf::Sprite background;
	sf::Text titleText;
	ClickableText connectText;
	ClickableText backText;
	TextBox playerNameTextBox;

	bool leftButtonDown;

	ConnectToAServerState();
	~ConnectToAServerState();

	void step();
	void draw();
	void eventMouseMoved(sf::Event mouseEvent);
	void eventMouseButtonPressed(sf::Event mouseEvent);
	void eventMouseButtonReleased(sf::Event mouseEvent);
	void eventTextEntered(sf::Event textEvent);

	void updateButtonsAndTextBoxes(sf::Vector2f mousePosition, bool isLeftButtonPressed);
	void connect();
	void back();
};
