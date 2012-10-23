#include "cards\EstateCard.h"

#include "Card.h"
#include "Player.h"

using namespace std;

EstateCard::EstateCard()
{
	
}
EstateCard::~EstateCard()
{

}
int EstateCard::getPrice(Card *card, Player *owner, vector<Player*> *otherPlayers)
{
	return 2;
}
int EstateCard::getVPValue(Player *owner)
{
	return 1;
}
