#pragma once

#include "Clickable.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>

class ClickableText : public sf::Drawable, public Clickable
{
public:
	static sf::Color normalColour;
	static sf::Color hovorColour;
	static sf::Color clickedColour;

	sf::Text text;
	float borderSize;

	ClickableText(std::string text = "", sf::Vector2f position = sf::Vector2f(0.0f, 0.0f), unsigned int fontSize = 12, sf::Font *font = 0, float borderSize = 0.0);
	~ClickableText();

	bool updateAndGetClicked(sf::Vector2f mousePosition, bool isLeftDown);
	void updateBoundingBox();
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;

private:
	sf::FloatRect boundingBox;
};