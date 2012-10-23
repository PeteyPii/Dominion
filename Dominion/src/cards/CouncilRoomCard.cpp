#include "cards\CouncilRoomCard.h"

#include "Card.h"
#include "OrderedDeck.h"
#include "Player.h"
#include <sstream>
#include <string>

using namespace std;

CouncilRoomCard::CouncilRoomCard()
{
	
}
CouncilRoomCard::~CouncilRoomCard()
{

}
int CouncilRoomCard::getPrice(Card *card, Player *owner, vector<Player*> *otherPlayers)
{
	return 5;
}
void CouncilRoomCard::playAction(Card *card, Player *owner, vector<Player*> &otherPlayers)
{
	owner->plusCards(4);

	owner->plusBuys(1);

	for(unsigned int ii = 0; ii < otherPlayers.size(); ii++)
	{
		otherPlayers[ii]->plusCards(1);
	}
}
