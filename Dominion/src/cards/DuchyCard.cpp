#include "cards\DuchyCard.h"

#include "Card.h"
#include "Player.h"

using namespace std;

DuchyCard::DuchyCard()
{
	
}
DuchyCard::~DuchyCard()
{

}
int DuchyCard::getPrice(Card *card, Player *owner, vector<Player*> *otherPlayers)
{
	return 5;
}
int DuchyCard::getVPValue(Player *owner)
{
	return 3;
}
