#include "cards\DefaultCard.h"

#include "Card.h"
#include "Player.h"

using namespace std;

DefaultCard::DefaultCard()
{

}
DefaultCard::~DefaultCard()
{

}
int DefaultCard::getPrice(Card *card, Player *owner, std::vector<Player*> *otherPlayers)
{
	return 0;
}
int DefaultCard::getVPValue(Player *owner)
{
	return 0;
}
void DefaultCard::playAction(Card *card, Player *owner, std::vector<Player*> &otherPlayers)
{

}
void DefaultCard::playTreasure(Card *card, Player *owner, std::vector<Player*> &otherPlayers)
{

}
void DefaultCard::playDuration(Card *card, Player *owner, std::vector<Player*> &otherPlayers)
{

}
void DefaultCard::setUpCardOnBoard()
{

}
