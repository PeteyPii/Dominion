#pragma once

#define NUMBER_OF_CARDS 32

#include <SFML/Graphics.hpp>

class ClientResources
{
public:
	sf::Texture backgroundCastle;
	sf::Texture textBoxCorner;
	sf::Texture cards[NUMBER_OF_CARDS + 1];
	sf::Font deutschFont;

	ClientResources();
	~ClientResources();

	void loadResources();
};

