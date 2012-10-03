#include "cards\VillageCard.h"

#include "Card.h"
#include "OrderedDeck.h"
#include "Player.h"

using namespace std;

VillageCard::VillageCard()
{

}
VillageCard::~VillageCard()
{

}
int VillageCard::getCoinValue(Player *owner)
{
	return 0;
}
int VillageCard::getVPValue(Player *owner)
{
	return 0;
}
void VillageCard::playAction(Card *card, Player *owner, std::vector<Player*> &otherPlayers)
{
	owner->plusCards(1);
	owner->plusActions(2);
}
void VillageCard::playTreasure(Card *card, Player *owner, std::vector<Player*> &otherPlayers)
{

}
void VillageCard::playDuration(Card *card, Player *owner, std::vector<Player*> &otherPlayers)
{

}
void VillageCard::setUpCardOnBoard()
{

}
