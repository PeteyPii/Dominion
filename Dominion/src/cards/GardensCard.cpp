#include "cards\GardensCard.h"

#include "Card.h"
#include "OrderedDeck.h"
#include "Player.h"

using namespace std;

GardensCard::GardensCard()
{
	
}
GardensCard::~GardensCard()
{

}
int GardensCard::getPrice(Card *card, Player *owner, vector<Player*> *otherPlayers)
{
	return 4;
}
int GardensCard::getVPValue(Player *owner)
{
	return (int)(owner->deck.cards.size() / 10);
}
