#pragma once

#include <SFML/System.hpp>

class PacketID
{
private:
	PacketID();
	~PacketID();

public:
	static const sf::Uint16 GAME_OVER;
	static const sf::Uint16 STANDARD_MESSAGE;
	static const sf::Uint16 CLEAR_SCREEN;
};

