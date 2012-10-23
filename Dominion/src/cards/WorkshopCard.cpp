#include "cards\WorkshopCard.h"

#include "Board.h"
#include "Card.h"
#include "Decision.h"
#include "OrderedDeck.h"
#include "Player.h"
#include <sstream>
#include <string>

using namespace std;

WorkshopCard::WorkshopCard()
{
	
}
WorkshopCard::~WorkshopCard()
{

}
int WorkshopCard::getPrice(Card *card, Player *owner, vector<Player*> *otherPlayers)
{
	return 3;
}
void WorkshopCard::playAction(Card *card, Player *owner, vector<Player*> &otherPlayers)
{
	Board* board = Board::boardGame;

	OrderedDeck gainableCards = board->getPurchasableCardsCostingUpToX(4, owner, &otherPlayers);

	if(gainableCards.cards.size() == 0)	// No obtainable cards
	{
		stringstream output;
		output << "You could not obtain any cards with WORKSHOP." << endl;
		owner->displayMessage(output.str(), false);

		stringstream globalOutput;
		globalOutput << owner->name << " could not obtain any cards with WORKSHOP." << endl;
		owner->broadcastToOtherPlayers(globalOutput.str());
	}
	else if(gainableCards.cards.size() == 1)	// Only one obtainable card
	{
		stringstream output;
		output << "You gained the card " << gainableCards.cards[0].name() << "." << endl;
		owner->displayMessage(output.str(), false);

		stringstream globalOutput;
		globalOutput << owner->name << " gained the card " << gainableCards.cards[0].name() << "." << endl;
		owner->broadcastToOtherPlayers(globalOutput.str());

		gainableCards.cards[0].containerDeck->drawCard(owner->discardPile);
	}
	else
	{
		Decision cardToGain("Select a card to gain with WORKSHOP:", owner);

		for(unsigned int ii = 0; ii < gainableCards.cards.size(); ii++)
		{
			cardToGain.addOption(gainableCards.cards[ii].name());
		}

		int decisionResult = cardToGain.makeDecision(false);

		stringstream output;
		output << "You gained the card " << gainableCards.cards[decisionResult].name() << "." << endl;
		owner->displayMessage(output.str(), false);

		stringstream globalOutput;
		globalOutput << owner->name << " gained the card " << gainableCards.cards[decisionResult].name() << "." << endl;
		owner->broadcastToOtherPlayers(globalOutput.str());

		gainableCards.cards[decisionResult].containerDeck->drawCard(owner->discardPile);
	}
}
