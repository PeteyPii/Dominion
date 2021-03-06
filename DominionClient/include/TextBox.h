#pragma once

#include "Clickable.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>

class TextBox : public sf::Drawable, public Clickable
{
public:
	static sf::Texture *cornerTexture;
	static sf::Vector2f cornerOriginOffset;

	sf::RectangleShape background;
	sf::Text text;
	sf::Sprite topLeftCorner, topRightCorner, bottomLeftCorner, bottomRightCorner;
	sf::Color backgroundColour;
	sf::Color outlineColour;
	float normalOutlineThickness;
	float highlightedOutlineThickness;

	bool showCorners;
	
	TextBox(std::string text = "", 
		sf::Vector2f position = sf::Vector2f(0.0f, 0.0f), 
		sf::Vector2f size = sf::Vector2f(0.0f, 0.0f),
		sf::Font *font = 0, 
		unsigned int fontSize = 12, 
		bool showCorners = true, 
		sf::Color backgroundColour = sf::Color(24, 24, 24, 100),
		sf::Color outlineColour = sf::Color::White,
		float normalOutlineThickness = 2.0f,
		float highlightedOutlineThickness = 3.0f);
	~TextBox();

	bool isSelected() const;
	void select(bool val);
	virtual void unhovered();
	virtual void hovered();
	virtual void clicked();
	virtual void clickedOutside();
	void updateDimensions();
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;

protected:
	bool isBoxSelected;
	
};
