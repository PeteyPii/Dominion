#pragma once

#include "State.h"
#include <SFML/Network.hpp>
#include <string>

class GameplayState : public State
{
public:
	std::string name, ipAddressString, port;
	unsigned short portNumber;
	sf::IpAddress ipAddress;
	
	GameplayState();
	~GameplayState();

	void runTextOnly();
	
	void setConnectionDetails(std::string playerName, std::string ipAddressString, std::string port);
};
