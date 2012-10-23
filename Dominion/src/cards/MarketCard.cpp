#include "cards\MarketCard.h"

#include "Card.h"
#include "OrderedDeck.h"
#include "Player.h"
#include <sstream>
#include <string>

using namespace std;

MarketCard::MarketCard()
{
	
}
MarketCard::~MarketCard()
{

}
int MarketCard::getPrice(Card *card, Player *owner, vector<Player*> *otherPlayers)
{
	return 5;
}
void MarketCard::playAction(Card *card, Player *owner, vector<Player*> &otherPlayers)
{
	owner->plusCards(1);

	owner->plusActions(1);

	owner->plusBuys(1);

	owner->plusCoins(1);
}
