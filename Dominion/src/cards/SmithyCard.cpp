#include "cards\SmithyCard.h"

#include "Card.h"
#include "OrderedDeck.h"
#include "Player.h"

using namespace std;

SmithyCard::SmithyCard()
{
	
}
SmithyCard::~SmithyCard()
{

}
int SmithyCard::getCoinValue(Player *owner)
{
	return 0;
}
int SmithyCard::getVPValue(Player *owner)
{
	return 0;
}
void SmithyCard::playAction(Card *card, Player *owner, std::vector<Player*> &otherPlayers)
{
	owner->plusCards(3);
}
void SmithyCard::playTreasure(Card *card, Player *owner, std::vector<Player*> &otherPlayers)
{

}
void SmithyCard::playDuration(Card *card, Player *owner, std::vector<Player*> &otherPlayers)
{

}
void SmithyCard::setUpCardOnBoard()
{

}
