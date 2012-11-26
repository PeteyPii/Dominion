#pragma once

#include "ClickableButton.h"
#include "State.h"
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <string>

class DominionApp;

class GameplayState : public State
{
private:
	enum GameStage
	{
		CONNECTING = 0,
		LOBBY
	};

public:
	DominionApp *app;

	std::string playerName, ipAddressString, port;
	unsigned short portNumber;
	sf::IpAddress ipAddress;
	sf::TcpSocket socket;

	sf::Sprite background;
	sf::Text unableToConnectText;
	ClickableButton exitButton;

	GameStage stage;
	bool leftButtonDown;

	GameplayState();
	~GameplayState();

	virtual void runTextOnly();

	virtual void step();
	virtual void draw();
	virtual void eventMouseMoved(sf::Event mouseEvent);
	virtual void eventMouseButtonPressed(sf::Event mouseEvent);
	virtual void eventMouseButtonReleased(sf::Event mouseEvent);
	virtual void eventKeyPressed(sf::Event keyEvent);
	
	void setConnectionDetails(std::string playerName, std::string ipAddressString, std::string port);
	void updateClickables(sf::Vector2f mousePosition, bool isLeftButtonPressed);
	void backToMainMenu();
};
