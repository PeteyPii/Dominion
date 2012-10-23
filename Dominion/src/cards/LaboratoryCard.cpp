#include "cards\LaboratoryCard.h"

#include "Card.h"
#include "OrderedDeck.h"
#include "Player.h"
#include <sstream>
#include <string>

using namespace std;

LaboratoryCard::LaboratoryCard()
{
	
}
LaboratoryCard::~LaboratoryCard()
{

}
int LaboratoryCard::getPrice(Card *card, Player *owner, vector<Player*> *otherPlayers)
{
	return 5;
}
void LaboratoryCard::playAction(Card *card, Player *owner, vector<Player*> &otherPlayers)
{
	owner->plusCards(2);
	owner->plusActions(1);
}
