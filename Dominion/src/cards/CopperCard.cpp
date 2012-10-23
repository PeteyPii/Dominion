#include "cards\CopperCard.h"

#include "Card.h"
#include "Player.h"

using namespace std;

CopperCard::CopperCard()
{
	
}
CopperCard::~CopperCard()
{

}
int CopperCard::getPrice(Card *card, Player *owner, vector<Player*> *otherPlayers)
{
	return 0;
}
void CopperCard::playTreasure(Card *card, Player *owner, vector<Player*> &otherPlayers)
{
	owner->coins += 1;
}
