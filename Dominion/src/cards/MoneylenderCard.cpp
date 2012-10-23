#include "cards\MoneylenderCard.h"

#include "Board.h"
#include "Card.h"
#include "Decision.h"
#include "OrderedDeck.h"
#include "Player.h"
#include <sstream>
#include <string>

using namespace std;

MoneylenderCard::MoneylenderCard()
{
	
}
MoneylenderCard::~MoneylenderCard()
{

}
int MoneylenderCard::getPrice(Card *card, Player *owner, vector<Player*> *otherPlayers)
{
	return 4;
}
void MoneylenderCard::playAction(Card *card, Player *owner, vector<Player*> &otherPlayers)
{
	vector<Card*> copperCards = owner->hand.getListOfCardsMatchingID(Card::COPPER_CARD);

	if(copperCards.size() > 0)	// Player has a COPPER card
	{
		stringstream output;
		output << "You trashed a COPPER card." << endl;
		owner->displayMessage(output.str(), false);

		stringstream globalOutput;
		globalOutput << owner->name << " trashed a COPPER card." << endl;
		owner->broadcastToOtherPlayers(globalOutput.str());

		copperCards[0]->moveToAnotherDeck(Board::boardGame->trashPile);

		owner->plusCoins(3);
	}
	else	// Player has no COPPER cards in their hand
	{
		stringstream output;
		output << "You had no COPPPER cards to trash. MONEYLENDER did nothing." << endl;
		owner->displayMessage(output.str(), false);

		stringstream globalOutput;
		globalOutput << owner->name << " had no COPPPER cards to trash. MONEYLENDER did nothing." << endl;
		owner->broadcastToOtherPlayers(globalOutput.str());
	}
}
