#include "cards\ThroneRoomCard.h"

#include "Card.h"
#include "Decision.h"
#include "OrderedDeck.h"
#include "Player.h"
#include <sstream>
#include <string>


using namespace std;

ThroneRoomCard::ThroneRoomCard()
{
	
}
ThroneRoomCard::~ThroneRoomCard()
{

}
int ThroneRoomCard::getPrice(Card *card, Player *owner, vector<Player*> *otherPlayers)
{
	return 4;
}
void ThroneRoomCard::playAction(Card *card, Player *owner, vector<Player*> &otherPlayers)
{
	vector<Card*> actionCards = owner->hand.getListOfCardsMatchingType(Card::ACTION_TYPE);

	if(actionCards.size() == 0)
	{
		stringstream output;
		output << "You had no ACTION cards to play with your THRONE ROOM so it did nothing." << endl;
		owner->displayMessage(output.str(), false);

		stringstream globalOutput;
		globalOutput << owner->name << " had no ACTION cards to play with his THRONE ROOM so it did nothing." << endl;
		owner->broadcastToOtherPlayers(globalOutput.str());
	}
	else if(actionCards.size() == 1)
	{
		stringstream output;
		output << "You played the card " << actionCards[0]->name() << " with THRONE ROOM." << endl;
		owner->displayMessage(output.str(), false);

		stringstream globalOutput;
		globalOutput << owner->name << " played the card " << actionCards[0]->name() << " with THRONE ROOM." << endl;
		owner->broadcastToOtherPlayers(globalOutput.str());

		OrderedDeck tempPile;

		actionCards[0]->moveToAnotherDeck(tempPile);
		tempPile.cards[0].playAction(owner, owner->otherPlayers);

		stringstream outputTwo;
		outputTwo << "You played the card " << actionCards[0]->name() << " with THRONE ROOM a second time." << endl;
		owner->displayMessage(outputTwo.str(), false);

		stringstream globalOutputTwo;
		globalOutputTwo << owner->name << " played the card " << actionCards[0]->name() << " with THRONE ROOM a second time." << endl;
		owner->broadcastToOtherPlayers(globalOutputTwo.str());

		tempPile.cards[0].playAction(owner, owner->otherPlayers);

		tempPile.moveContentsToAnotherDeck(owner->cleanupPile);
	}
	else
	{
		Decision cardToPlayTwice("Select a card to play twice with THRONE ROOM:", owner);

		for(unsigned int ii = 0; ii < actionCards.size(); ii++)
		{
			cardToPlayTwice.addOption(actionCards[ii]->name());
		}

		int decisionResult = cardToPlayTwice.makeDecision(false);

		stringstream output;
		output << "You played the card " << actionCards[decisionResult]->name() << " with THRONE ROOM." << endl;
		owner->displayMessage(output.str(), false);

		stringstream globalOutput;
		globalOutput << owner->name << " played the card " << actionCards[decisionResult]->name() << " with THRONE ROOM." << endl;
		owner->broadcastToOtherPlayers(globalOutput.str());

		OrderedDeck tempPile;

		actionCards[decisionResult]->moveToAnotherDeck(tempPile);
		tempPile.cards[0].playAction(owner, owner->otherPlayers);

		stringstream outputTwo;
		outputTwo << "You played the card " << actionCards[decisionResult]->name() << " with THRONE ROOM a second time." << endl;
		owner->displayMessage(outputTwo.str(), false);

		stringstream globalOutputTwo;
		globalOutputTwo << owner->name << " played the card " << actionCards[decisionResult]->name() << " with THRONE ROOM a second time." << endl;
		owner->broadcastToOtherPlayers(globalOutputTwo.str());

		tempPile.cards[0].playAction(owner, owner->otherPlayers);

		tempPile.moveContentsToAnotherDeck(owner->cleanupPile);
	}
}
