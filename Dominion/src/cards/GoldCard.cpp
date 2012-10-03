#include "cards\GoldCard.h"

#include "Card.h"
#include "OrderedDeck.h"
#include "Player.h"

GoldCard::GoldCard()
{
	
}
GoldCard::~GoldCard()
{

}
int GoldCard::getCoinValue(Player *owner)
{
	return 3;
}
int GoldCard::getVPValue(Player *owner)
{
	return 0;
}
void GoldCard::playAction(Card *card, Player *owner, std::vector<Player*> &otherPlayers)
{
	
}
void GoldCard::playTreasure(Card *card, Player *owner, std::vector<Player*> &otherPlayers)
{
	owner->coins += getCoinValue(owner);
}
void GoldCard::playDuration(Card *card, Player *owner, std::vector<Player*> &otherPlayers)
{

}
void GoldCard::setUpCardOnBoard()
{

}
