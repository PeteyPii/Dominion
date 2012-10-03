#include "cards\LaboratoryCard.h"

#include "Card.h"
#include "OrderedDeck.h"
#include "Player.h"

using namespace std;

LaboratoryCard::LaboratoryCard()
{
	
}
LaboratoryCard::~LaboratoryCard()
{

}
int LaboratoryCard::getCoinValue(Player *owner)
{
	return 0;
}
int LaboratoryCard::getVPValue(Player *owner)
{
	return 0;
}
void LaboratoryCard::playAction(Card *card, Player *owner, std::vector<Player*> &otherPlayers)
{
	owner->plusCards(2);

	owner->plusActions(1);
}
void LaboratoryCard::playTreasure(Card *card, Player *owner, std::vector<Player*> &otherPlayers)
{

}
void LaboratoryCard::playDuration(Card *card, Player *owner, std::vector<Player*> &otherPlayers)
{

}
void LaboratoryCard::setUpCardOnBoard()
{

}
