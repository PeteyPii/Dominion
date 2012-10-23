#include "cards\FestivalCard.h"

#include "Card.h"
#include "OrderedDeck.h"
#include "Player.h"
#include <sstream>
#include <string>

using namespace std;

FestivalCard::FestivalCard()
{
	
}
FestivalCard::~FestivalCard()
{

}
int FestivalCard::getPrice(Card *card, Player *owner, vector<Player*> *otherPlayers)
{
	return 5;
}
void FestivalCard::playAction(Card *card, Player *owner, vector<Player*> &otherPlayers)
{
	owner->plusActions(2);

	owner->plusBuys(1);

	owner->plusCoins(2);
}
