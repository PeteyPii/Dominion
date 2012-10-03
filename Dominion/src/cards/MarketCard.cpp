#include "cards\MarketCard.h"

#include "Card.h"
#include "OrderedDeck.h"
#include "Player.h"

MarketCard::MarketCard()
{
	
}
MarketCard::~MarketCard()
{

}
int MarketCard::getCoinValue(Player *owner)
{
	return 0;
}
int MarketCard::getVPValue(Player *owner)
{
	return 0;
}
void MarketCard::playAction(Card *card, Player *owner, std::vector<Player*> &otherPlayers)
{
	owner->plusCards(1);

	owner->plusActions(1);

	owner->plusBuys(1);

	owner->plusCoins(1);
}
void MarketCard::playTreasure(Card *card, Player *owner, std::vector<Player*> &otherPlayers)
{

}
void MarketCard::playDuration(Card *card, Player *owner, std::vector<Player*> &otherPlayers)
{

}
void MarketCard::setUpCardOnBoard()
{

}
