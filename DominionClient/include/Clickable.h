#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Clickable
{
public:
	const sf::FloatRect *rect;

	Clickable(sf::FloatRect *rect = 0);
	~Clickable();

	virtual bool updateAndGetClicked(sf::Vector2f mousePosition, bool isLeftDown);
	void resetStates();

protected:
	bool wasClicked;
	bool wasHovered;
};

