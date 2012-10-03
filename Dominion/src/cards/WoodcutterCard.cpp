#include "cards\WoodcutterCard.h"

#include "Card.h"
#include "OrderedDeck.h"
#include "Player.h"

using namespace std;

WoodcutterCard::WoodcutterCard()
{
	
}
WoodcutterCard::~WoodcutterCard()
{

}
int WoodcutterCard::getCoinValue(Player *owner)
{
	return 0;
}
int WoodcutterCard::getVPValue(Player *owner)
{
	return 0;
}
void WoodcutterCard::playAction(Card *card, Player *owner, std::vector<Player*> &otherPlayers)
{
	owner->plusBuys(1);
	owner->plusCoins(2);
}
void WoodcutterCard::playTreasure(Card *card, Player *owner, std::vector<Player*> &otherPlayers)
{

}
void WoodcutterCard::playDuration(Card *card, Player *owner, std::vector<Player*> &otherPlayers)
{

}
void WoodcutterCard::setUpCardOnBoard()
{

}
