#include "cards\DuchyCard.h"

#include "Player.h"

DuchyCard::DuchyCard()
{
	
}
DuchyCard::~DuchyCard()
{

}
int DuchyCard::getCoinValue(Player *owner)
{
	return 0;
}
int DuchyCard::getVPValue(Player *owner)
{
	return 3;
}
void DuchyCard::playAction(Card *card, Player *owner, std::vector<Player*> &otherPlayers)
{
	
}
void DuchyCard::playTreasure(Card *card, Player *owner, std::vector<Player*> &otherPlayers)
{

}
void DuchyCard::playDuration(Card *card, Player *owner, std::vector<Player*> &otherPlayers)
{

}
void DuchyCard::setUpCardOnBoard()
{

}
