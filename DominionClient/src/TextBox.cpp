#include "TextBox.h"

#include "DominionApp.h"

sf::Texture *TextBox::cornerTexture = 0;
sf::Vector2f TextBox::cornerOriginOffset = sf::Vector2f(5.0f, 5.0f);

using namespace std;

TextBox::TextBox(string text, sf::Vector2f position, sf::Vector2f size, sf::Font *font, unsigned int fontSize, bool showCorners, sf::Color backgroundColour, sf::Color outlineColour, float normalOutlineThickness, float highlightedOutlineThickness)
{
	if(cornerTexture == 0)
	{
		cornerTexture = &DominionApp::dominionApp->resources.textBoxCorner;
	}

	isBoxSelected = false;

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

	this->showCorners = showCorners;
	this->backgroundColour = backgroundColour;
	this->outlineColour = outlineColour;
	this->normalOutlineThickness = normalOutlineThickness;
	this->highlightedOutlineThickness = highlightedOutlineThickness;
}
TextBox::~TextBox()
{

}
bool TextBox::isSelected() const
{
	return isBoxSelected;
}
void TextBox::select(bool val)
{
	if(val != isBoxSelected)
	{
		isBoxSelected = !isBoxSelected;

		if(val)
		{
			background.setOutlineThickness(highlightedOutlineThickness);
		}
		else
		{
			background.setOutlineThickness(normalOutlineThickness);
		}
	}
}
void TextBox::unhovered()
{
	if(!isSelected())
	{
		background.setOutlineThickness(normalOutlineThickness);
	}
}
void TextBox::hovered()
{
	background.setOutlineThickness(highlightedOutlineThickness);
}
void TextBox::clicked()
{
	select(true);
}
void TextBox::clickedOutside()
{
	select(false);
}
void TextBox::updateDimensions()
{
	// Set positions of the corner sprites and the text
	topLeftCorner.setPosition(background.getPosition());
	topRightCorner.setPosition(background.getPosition().x + background.getSize().x, background.getPosition().y);
	bottomLeftCorner.setPosition(background.getPosition().x, background.getPosition().y + background.getSize().y);
	bottomRightCorner.setPosition(background.getPosition() + background.getSize());

	text.setPosition(background.getPosition().x + 0.015f * background.getSize().x, background.getPosition().y + 0.5f * background.getSize().y - 0.5f * text.getGlobalBounds().height - 6);

	rect = background.getGlobalBounds();
}
void TextBox::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(background);
	target.draw(text);

	if(showCorners)
	{
		target.draw(topLeftCorner);
		target.draw(topRightCorner);
		target.draw(bottomLeftCorner);
		target.draw(bottomRightCorner);
	}
}
