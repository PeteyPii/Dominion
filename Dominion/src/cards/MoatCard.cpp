#include "cards\MoatCard.h"

#include "Card.h"
#include "OrderedDeck.h"
#include "Player.h"
#include <sstream>
#include <string>

using namespace std;

MoatCard::MoatCard()
{
	
}
MoatCard::~MoatCard()
{

}
int MoatCard::getPrice(Card *card, Player *owner, vector<Player*> *otherPlayers)
{
	return 2;
}
void MoatCard::playAction(Card *card, Player *owner, vector<Player*> &otherPlayers)
{
	owner->plusCards(2);
}
