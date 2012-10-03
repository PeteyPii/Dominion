#include "cards\CopperCard.h"

#include "Player.h"

CopperCard::CopperCard()
{
	
}
CopperCard::~CopperCard()
{

}
int CopperCard::getCoinValue(Player *owner)
{
	return 1;
}
int CopperCard::getVPValue(Player *owner)
{
	return 0;
}
void CopperCard::playAction(Card *card, Player *owner, std::vector<Player*> &otherPlayers)
{

}
void CopperCard::playTreasure(Card *card, Player *owner, std::vector<Player*> &otherPlayers)
{
	owner->coins += getCoinValue(owner);
}
void CopperCard::playDuration(Card *card, Player *owner, std::vector<Player*> &otherPlayers)
{

}
void CopperCard::setUpCardOnBoard()
{

}
