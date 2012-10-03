#include "cards\GardensCard.h"

#include "Card.h"
#include "OrderedDeck.h"
#include "Player.h"

GardensCard::GardensCard()
{
	
}
GardensCard::~GardensCard()
{

}
int GardensCard::getCoinValue(Player *owner)
{
	return 0;
}
int GardensCard::getVPValue(Player *owner)
{
	return (int)(owner->deck.cards.size() / 10);
}
void GardensCard::playAction(Card *card, Player *owner, std::vector<Player*> &otherPlayers)
{

}
void GardensCard::playTreasure(Card *card, Player *owner, std::vector<Player*> &otherPlayers)
{

}
void GardensCard::playDuration(Card *card, Player *owner, std::vector<Player*> &otherPlayers)
{

}
void GardensCard::setUpCardOnBoard()
{

}
