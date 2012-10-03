#include "cards\CouncilRoomCard.h"

#include "Card.h"
#include "OrderedDeck.h"
#include "Player.h"

using namespace std;

CouncilRoomCard::CouncilRoomCard()
{
	
}
CouncilRoomCard::~CouncilRoomCard()
{

}
int CouncilRoomCard::getCoinValue(Player *owner)
{
	return 0;
}
int CouncilRoomCard::getVPValue(Player *owner)
{
	return 0;
}
void CouncilRoomCard::playAction(Card *card, Player *owner, std::vector<Player*> &otherPlayers)
{
	owner->plusCards(4);

	owner->plusBuys(1);

	for(unsigned int ii = 0; ii < otherPlayers.size(); ii++)
	{
		otherPlayers[ii]->plusCards(1);
	}
}
void CouncilRoomCard::playTreasure(Card *card, Player *owner, std::vector<Player*> &otherPlayers)
{

}
void CouncilRoomCard::playDuration(Card *card, Player *owner, std::vector<Player*> &otherPlayers)
{

}
void CouncilRoomCard::setUpCardOnBoard()
{

}
