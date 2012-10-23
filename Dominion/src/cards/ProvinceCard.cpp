#include "cards\ProvinceCard.h"

#include "Card.h"
#include "Player.h"

using namespace std;

ProvinceCard::ProvinceCard()
{
	
}
ProvinceCard::~ProvinceCard()
{

}
int ProvinceCard::getPrice(Card *card, Player *owner, vector<Player*> *otherPlayers)
{
	return 8;
}
int ProvinceCard::getVPValue(Player *owner)
{
	return 6;
}
