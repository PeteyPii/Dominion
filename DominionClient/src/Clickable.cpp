#include "Clickable.h"

Clickable::Clickable(sf::FloatRect *rect)
{
	this->rect = rect;
}
Clickable::~Clickable()
{

}
bool Clickable::updateAndGetClicked(sf::Vector2f mousePosition, bool isLeftDown)
{
	if(rect->contains(mousePosition.x, mousePosition.y))	// Mouse is over the clicking area
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

		wasHovered = true;
	}
	else	// Mouse is not over the clicking area
	{
		wasClicked = false;
		wasHovered = false;
	}

	return false;
}

void Clickable::resetStates()
{
	wasClicked = false;
	wasHovered = false;
}
