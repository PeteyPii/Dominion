#include "cards\SmithyCard.h"

#include "Card.h"
#include "OrderedDeck.h"
#include "Player.h"
#include <sstream>
#include <string>

using namespace std;

SmithyCard::SmithyCard()
{
	
}
SmithyCard::~SmithyCard()
{

}
int SmithyCard::getPrice(Card *card, Player *owner, vector<Player*> *otherPlayers)
{
	return 4;
}
void SmithyCard::playAction(Card *card, Player *owner, vector<Player*> &otherPlayers)
{
	owner->plusCards(3);
}
