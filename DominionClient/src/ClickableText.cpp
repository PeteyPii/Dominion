#include "ClickableText.h"

using namespace std;

sf::Color ClickableText::normalColour = sf::Color::White;
sf::Color ClickableText::hoverColour = sf::Color(160, 255, 160);
sf::Color ClickableText::clickedColour = sf::Color(80, 160, 80);

ClickableText::ClickableText(string text, sf::Vector2f position, unsigned int fontSize, sf::Font *font, float borderSize)
{
	this->text.setString(text);
	this->text.setPosition(position);
	this->text.setCharacterSize(fontSize);

	if(font != 0)
		this->text.setFont(*font);

	this->borderSize = borderSize;
	updateBoundingBox();
}
ClickableText::~ClickableText()
{

}
/*bool ClickableText::updateAndGetClicked(sf::Vector2f mousePosition, bool isLeftDown)
{
	if(boundingBox.contains(mousePosition.x, mousePosition.y))	// Mouse is over the clicking area
	{
		if(wasClicked)
		{
			if(!isLeftDown)	// Clicked and released inside the clicking area
			{
				wasHovered = true;
				wasClicked = false;
				text.setColor(hovorColour);

				return true;
			}
		}
		else
		{
			if(isLeftDown)	// Clicked in the clicking area
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
	else	// Mouse is not over the clicking area
	{
		wasClicked = false;
		wasHovered = false;
		text.setColor(normalColour);
	}

	return false;
}*/
void ClickableText::unhovered()
{
	text.setColor(normalColour);
}
void ClickableText::hovered()
{
	text.setColor(hoverColour);
}
void ClickableText::clicked()
{
	text.setColor(clickedColour);
}
void ClickableText::updateBoundingBox()
{
	rect = text.getGlobalBounds();

	rect.left += borderSize;
	rect.top += borderSize;
	rect.width -= borderSize;
	rect.height -= borderSize;
}
void ClickableText::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(text);
}
