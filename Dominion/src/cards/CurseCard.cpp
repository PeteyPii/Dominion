#include "cards\CurseCard.h"

#include "Card.h"
#include "Player.h"

using namespace std;

CurseCard::CurseCard()
{
	
}
CurseCard::~CurseCard()
{

}
int CurseCard::getPrice(Card *card, Player *owner, vector<Player*> *otherPlayers)
{
	return 0;
}
int CurseCard::getVPValue(Player *owner)
{
	return -1;
}
