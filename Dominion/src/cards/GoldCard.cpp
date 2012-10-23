#include "cards\GoldCard.h"

#include "Card.h"
#include "Player.h"

using namespace std;

GoldCard::GoldCard()
{
	
}
GoldCard::~GoldCard()
{

}
int GoldCard::getPrice(Card *card, Player *owner, vector<Player*> *otherPlayers)
{
	return 6;
}
void GoldCard::playTreasure(Card *card, Player *owner, vector<Player*> &otherPlayers)
{
	owner->coins += 3;
}
