#include "cards\MoatCard.h"

#include "Card.h"
#include "OrderedDeck.h"
#include "Player.h"

using namespace std;

MoatCard::MoatCard()
{
	
}
MoatCard::~MoatCard()
{

}
int MoatCard::getCoinValue(Player *owner)
{
	return 0;
}
int MoatCard::getVPValue(Player *owner)
{
	return 0;
}
void MoatCard::playAction(Card *card, Player *owner, std::vector<Player*> &otherPlayers)
{
	owner->plusCards(2);
}
void MoatCard::playTreasure(Card *card, Player *owner, std::vector<Player*> &otherPlayers)
{

}
void MoatCard::playDuration(Card *card, Player *owner, std::vector<Player*> &otherPlayers)
{

}
void MoatCard::setUpCardOnBoard()
{

}
