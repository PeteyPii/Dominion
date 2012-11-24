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

	cards[0].loadFromFile("resources/images/adventurer.jpg");
	cards[1].loadFromFile("resources/images/bureaucrat.jpg");
	cards[2].loadFromFile("resources/images/cellar.jpg");
	cards[3].loadFromFile("resources/images/chancellor.jpg");
	cards[4].loadFromFile("resources/images/chapel.jpg");
	cards[5].loadFromFile("resources/images/copper.jpg");
	cards[6].loadFromFile("resources/images/council_room.jpg");
	cards[7].loadFromFile("resources/images/curse.jpg");
	cards[8].loadFromFile("resources/images/duchy.jpg");
	cards[9].loadFromFile("resources/images/estate.jpg");
	cards[10].loadFromFile("resources/images/feast.jpg");
	cards[11].loadFromFile("resources/images/festival.jpg");
	cards[12].loadFromFile("resources/images/gardens.jpg");
	cards[13].loadFromFile("resources/images/gold.jpg");
	cards[14].loadFromFile("resources/images/laboratory.jpg");
	cards[15].loadFromFile("resources/images/library.jpg");
	cards[16].loadFromFile("resources/images/market.jpg");
	cards[17].loadFromFile("resources/images/militia.jpg");
	cards[18].loadFromFile("resources/images/mine.jpg");
	cards[19].loadFromFile("resources/images/moat.jpg");
	cards[20].loadFromFile("resources/images/moneylender.jpg");
	cards[21].loadFromFile("resources/images/province.jpg");
	cards[22].loadFromFile("resources/images/remodel.jpg");
	cards[23].loadFromFile("resources/images/silver.jpg");
	cards[24].loadFromFile("resources/images/smithy.jpg");
	cards[25].loadFromFile("resources/images/spy.jpg");
	cards[26].loadFromFile("resources/images/thief.jpg");
	cards[27].loadFromFile("resources/images/throne_room.jpg");
	cards[28].loadFromFile("resources/images/village.jpg");
	cards[29].loadFromFile("resources/images/witch.jpg");
	cards[30].loadFromFile("resources/images/woodcutter.jpg");
	cards[31].loadFromFile("resources/images/workshop.jpg");
	cards[32].loadFromFile("resources/images/card_back.jpg");

	deutschFont.loadFromFile("resources/fonts/Deutsch.ttf");
}
