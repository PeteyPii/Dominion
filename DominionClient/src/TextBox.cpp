#include "TextBox.h"

#include "DominionApp.h"

sf::Color TextBox::backgroundColour = sf::Color(24, 24, 24, 100);
sf::Color TextBox::outlineColour = sf::Color::White;
float TextBox::normalOutlineThickness = 2.0f;
float TextBox::highlightedOutlineThickness = 4.0f;
sf::Texture *TextBox::cornerTexture = 0;
sf::Vector2f TextBox::cornerOriginOffset = sf::Vector2f(8.0f, 8.0f);

TextBox::TextBox(sf::Vector2f position, sf::Vector2f size, std::string text, sf::Font *font, unsigned int fontSize)
{
	if(cornerTexture == 0)
	{
		cornerTexture = &DominionApp::dominionApp->resources.textBoxCorner;
	}

	background.setFillColor(backgroundColour);
	background.setOutlineColor(outlineColour);
	background.setOutlineThickness(normalOutlineThickness);
	background.setPosition(position);
	background.setSize(size);

	if(font != 0)
		this->text.setFont(*font);

	this->text.setString(text);
	this->text.setCharacterSize(fontSize);

	topLeftCorner.setTexture(*cornerTexture);
	topRightCorner.setTexture(*cornerTexture);
	bottomLeftCorner.setTexture(*cornerTexture);
	bottomRightCorner.setTexture(*cornerTexture);

	topLeftCorner.setOrigin(cornerOriginOffset);
	topRightCorner.setOrigin(cornerOriginOffset);
	bottomLeftCorner.setOrigin(cornerOriginOffset);
	bottomRightCorner.setOrigin(cornerOriginOffset);

	topLeftCorner.setScale(1.0f, 1.0f);
	topRightCorner.setScale(-1.0f, 1.0f);
	bottomLeftCorner.setScale(1.0f, -1.0f);
	bottomRightCorner.setScale(-1.0f, -1.0f);

	updateDimensions();
}
TextBox::~TextBox()
{

}
bool TextBox::updateAndGetClicked(sf::Vector2f mousePosition, bool isLeftDown)
{
	if(background.getGlobalBounds().contains(mousePosition.x, mousePosition.y))	// Mouse is over the clicking area
	{
		if(wasClicked)
		{
			if(!isLeftDown)	// Clicked and released inside the clicking area
			{
				wasHovered = true;
				wasClicked = false;

				return true;
			}
		}
		else
		{
			if(isLeftDown)	// Clicked in the clicking area
			{
				wasClicked = true;
			}
		}

		background.setOutlineThickness(highlightedOutlineThickness);
		wasHovered = true;
	}
	else	// Mouse is not over the clicking area
	{
		wasClicked = false;
		wasHovered = false;
		background.setOutlineThickness(normalOutlineThickness);
	}

	return false;
}
void TextBox::updateDimensions()
{
	// Set positions of the corner sprites and the text
	topLeftCorner.setPosition(background.getPosition());
	topRightCorner.setPosition(background.getPosition().x + background.getSize().x, background.getPosition().y);
	bottomLeftCorner.setPosition(background.getPosition().x, background.getPosition().y + background.getSize().y);
	bottomRightCorner.setPosition(background.getPosition() + background.getSize());

	text.setPosition(background.getPosition().x + 0.015f * background.getSize().x, background.getPosition().y + 0.45f * background.getSize().y - 0.55f * text.getGlobalBounds().height);
}
void TextBox::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(background);
	target.draw(text);
	target.draw(topLeftCorner);
	target.draw(topRightCorner);
	target.draw(bottomLeftCorner);
	target.draw(bottomRightCorner);
}
