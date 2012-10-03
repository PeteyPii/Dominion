#include "cards\SilverCard.h"

#include "Player.h"

SilverCard::SilverCard()
{
	
}
SilverCard::~SilverCard()
{

}
int SilverCard::getCoinValue(Player *owner)
{
	return 2;
}
int SilverCard::getVPValue(Player *owner)
{
	return 0;
}
void SilverCard::playAction(Card *card, Player *owner, std::vector<Player*> &otherPlayers)
{
	
}
void SilverCard::playTreasure(Card *card, Player *owner, std::vector<Player*> &otherPlayers)
{
	owner->coins += getCoinValue(owner);
}
void SilverCard::playDuration(Card *card, Player *owner, std::vector<Player*> &otherPlayers)
{

}
void SilverCard::setUpCardOnBoard()
{

}
