#include "cards\WoodcutterCard.h"

#include "Card.h"
#include "OrderedDeck.h"
#include "Player.h"
#include <sstream>
#include <string>

using namespace std;

WoodcutterCard::WoodcutterCard()
{
	
}
WoodcutterCard::~WoodcutterCard()
{

}
int WoodcutterCard::getPrice(Card *card, Player *owner, vector<Player*> *otherPlayers)
{
	return 3;
}
void WoodcutterCard::playAction(Card *card, Player *owner, vector<Player*> &otherPlayers)
{
	owner->plusBuys(1);
	owner->plusCoins(2);
}
