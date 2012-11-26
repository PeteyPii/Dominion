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
	sf::Text playerNameText;
	sf::Text ipAddressText;
	sf::Text portNumberText;
	TextBox playerNameTextBox;
	TextBox ipAddressTextBox;
	TextBox portNumberTextBox;

	bool leftButtonDown;
	bool playerNameBoxClicked, ipAddressBoxClicked, portNumberBoxClicked;

	ConnectToAServerState();
	~ConnectToAServerState();

	virtual void step();
	virtual void draw();
	virtual void eventMouseMoved(sf::Event mouseEvent);
	virtual void eventMouseButtonPressed(sf::Event mouseEvent);
	virtual void eventMouseButtonReleased(sf::Event mouseEvent);
	virtual void eventKeyPressed(sf::Event keyEvent);
	virtual void eventTextEntered(sf::Event textEvent);

	void updateButtonsAndTextBoxes(sf::Vector2f mousePosition, bool isLeftButtonPressed);
	void connect();
	void back();
};
