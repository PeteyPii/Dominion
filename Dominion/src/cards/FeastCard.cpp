#include "cards\FeastCard.h"

#include "Board.h"
#include "Card.h"
#include "Decision.h"
#include "OrderedDeck.h"
#include "Player.h"
#include <sstream>
#include <string>

using namespace std;

FeastCard::FeastCard()
{
	
}
FeastCard::~FeastCard()
{

}
int FeastCard::getPrice(Card *card, Player *owner, vector<Player*> *otherPlayers)
{
	return 4;
}
void FeastCard::playAction(Card *card, Player *owner, vector<Player*> &otherPlayers)
{
	
	Board* board = Board::boardGame;

	if(card->containerDeck != &board->trashPile)	// Card is not already in trash
	{
		stringstream output;
		output << "You trashed your FEAST card." << endl;
		owner->displayMessage(output.str(), false);

		stringstream globalOutput;
		globalOutput << owner->name << " trashed a FEAST card." << endl;
		owner->broadcastToOtherPlayers(globalOutput.str());

		card->moveToAnotherDeck(board->trashPile);
	}
	
	OrderedDeck gainableCards = board->getPurchasableCardsCostingUpToX(5, owner, &otherPlayers);

	if(gainableCards.cards.size() == 0)	// No obtainable cards
	{
		stringstream output;
		output << "You could not obtain any cards with FEAST." << endl;
		owner->displayMessage(output.str(), false);

		stringstream globalOutput;
		globalOutput << owner->name << " could not obtain any cards with FEAST." << endl;
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
		Decision cardToGain("Select a card to gain:", owner);

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
