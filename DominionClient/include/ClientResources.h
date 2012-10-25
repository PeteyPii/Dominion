#pragma once

#define NUMBER_OF_CARDS 32

#include <SFML/Graphics.hpp>

class ClientResources
{
public:
	static ClientResources *resources;

	sf::Image cardImages[NUMBER_OF_CARDS + 1];
	sf::Font deutschFont;

	ClientResources();
	~ClientResources();

	void loadResources();
};

