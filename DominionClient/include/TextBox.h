#pragma once

#include "Clickable.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>

class TextBox : public sf::Drawable, public Clickable
{
public:
	static sf::Color backgroundColour;
	static sf::Color outlineColour;
	static float normalOutlineThickness;
	static float highlightedOutlineThickness;
	static sf::Texture *cornerTexture;
	static sf::Vector2f cornerOriginOffset;

	sf::RectangleShape background;
	sf::Text text;
	sf::Sprite topLeftCorner, topRightCorner, bottomLeftCorner, bottomRightCorner;

	TextBox(sf::Vector2f position = sf::Vector2f(0.0f, 0.0f), sf::Vector2f size = sf::Vector2f(0.0f, 0.0f), std::string text = "", sf::Font *font = 0, unsigned int fontSize = 12);
	~TextBox();

	bool updateAndGetClicked(sf::Vector2f mousePosition, bool isLeftDown);
	void updateDimensions();
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};
