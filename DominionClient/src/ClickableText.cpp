#include "ClickableText.h"

using namespace std;

sf::Color ClickableText::normalColour = sf::Color::White;
sf::Color ClickableText::hovorColour = sf::Color(160, 255, 160);
sf::Color ClickableText::clickedColour = sf::Color(80, 160, 80);

ClickableText::ClickableText()
{
	this->text.setString("");
	this->text.setPosition(sf::Vector2f(0, 0));
	this->text.setCharacterSize(12);
	this->borderSize = 0.0;
	updateBoundingBox();
}
ClickableText::ClickableText(string text, sf::Vector2f position, unsigned int fontSize, sf::Font &font, float borderSize)
{
	this->text.setString(text);
	this->text.setPosition(position);
	this->text.setCharacterSize(fontSize);
	this->text.setFont(font);
	this->borderSize = borderSize;
	updateBoundingBox();
}
ClickableText::~ClickableText()
{

}
bool ClickableText::updateAndGetClicked(sf::Vector2f mousePosition, bool isLeftDown)
{
	if(isMouseInside(mousePosition))
	{
		if(wasClicked)
		{
			if(!isLeftDown)
			{
				wasHovered = true;
				wasClicked = false;
				text.setColor(hovorColour);

				return true;
			}
		}
		else
		{
			if(isLeftDown)
			{
				wasClicked = true;
				text.setColor(clickedColour);
			}
			else
			{
				text.setColor(hovorColour);
			}
		}

		wasHovered = true;
	}
	else
	{
		wasClicked = false;
		wasHovered = false;
		text.setColor(normalColour);
	}

	return false;
}
void ClickableText::updateBoundingBox()
{
	boundingBox = text.getGlobalBounds();

	boundingBox.left += borderSize;
	boundingBox.top += borderSize;
	boundingBox.width -= borderSize;
	boundingBox.height -= borderSize;
}
bool ClickableText::isMouseInside(sf::Vector2f mousePosition)
{
	return boundingBox.contains(mousePosition.x, mousePosition.y);
}
