#include "cards\FestivalCard.h"

#include "Card.h"
#include "OrderedDeck.h"
#include "Player.h"

using namespace std;

FestivalCard::FestivalCard()
{
	
}
FestivalCard::~FestivalCard()
{

}
int FestivalCard::getCoinValue(Player *owner)
{
	return 0;
}
int FestivalCard::getVPValue(Player *owner)
{
	return 0;
}
void FestivalCard::playAction(Card *card, Player *owner, std::vector<Player*> &otherPlayers)
{
	owner->plusActions(2);

	owner->plusBuys(1);

	owner->plusCoins(2);
}
void FestivalCard::playTreasure(Card *card, Player *owner, std::vector<Player*> &otherPlayers)
{

}
void FestivalCard::playDuration(Card *card, Player *owner, std::vector<Player*> &otherPlayers)
{

}
void FestivalCard::setUpCardOnBoard()
{

}
