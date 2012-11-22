#include "ClientResources.h"

ClientResources::ClientResources()
{

}
ClientResources::~ClientResources()
{

}
void ClientResources::loadResources()
{
	backgroundCastle.loadFromFile("resources/images/castle_background.jpg");
	textBoxCorner.loadFromFile("resources/images/cross.png");

	deutschFont.loadFromFile("resources/fonts/Deutsch.ttf");
}
