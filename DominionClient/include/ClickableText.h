#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>

class ClickableText
{
public:
	static sf::Color normalColour;
	static sf::Color hovorColour;
	static sf::Color clickedColour;

	sf::Text text;
	float borderSize;

	ClickableText();
	ClickableText(std::string text, sf::Vector2f position, unsigned int fontSize, sf::Font &font, float borderSize);
	~ClickableText();

	bool updateAndGetClicked(sf::Vector2f mousePosition, bool isLeftDown);
	void updateBoundingBox();

private:
	bool wasClicked;
	bool wasHovered;
	sf::FloatRect boundingBox;

	bool isMouseInside(sf::Vector2f mousePosition);
};
