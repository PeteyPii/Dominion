#include "cards\CurseCard.h"

#include "Player.h"

CurseCard::CurseCard()
{
	
}
CurseCard::~CurseCard()
{

}
int CurseCard::getCoinValue(Player *owner)
{
	return 0;
}
int CurseCard::getVPValue(Player *owner)
{
	return -1;
}
void CurseCard::playAction(Card *card, Player *owner, std::vector<Player*> &otherPlayers)
{
	
}
void CurseCard::playTreasure(Card *card, Player *owner, std::vector<Player*> &otherPlayers)
{

}
void CurseCard::playDuration(Card *card, Player *owner, std::vector<Player*> &otherPlayers)
{

}
void CurseCard::setUpCardOnBoard()
{

}
