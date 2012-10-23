#include "cards\VillageCard.h"

#include "Card.h"
#include "OrderedDeck.h"
#include "Player.h"
#include <sstream>
#include <string>


using namespace std;

VillageCard::VillageCard()
{

}
VillageCard::~VillageCard()
{

}
int VillageCard::getPrice(Card *card, Player *owner, vector<Player*> *otherPlayers)
{
	return 3;
}
void VillageCard::playAction(Card *card, Player *owner, vector<Player*> &otherPlayers)
{
	owner->plusCards(1);
	owner->plusActions(2);
}
