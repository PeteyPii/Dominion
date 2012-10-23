#include "cards\SilverCard.h"

#include "Card.h"
#include "Player.h"
#include <string>

using namespace std;

SilverCard::SilverCard()
{
	
}
SilverCard::~SilverCard()
{

}
int SilverCard::getPrice(Card *card, Player *owner, vector<Player*> *otherPlayers)
{
	return 3;
}
void SilverCard::playTreasure(Card *card, Player *owner, vector<Player*> &otherPlayers)
{
	owner->coins += 2;
}
