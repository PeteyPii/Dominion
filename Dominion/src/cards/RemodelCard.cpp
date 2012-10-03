#include "cards\RemodelCard.h"

#include "Board.h"
#include "Card.h"
#include "Decision.h"
#include "OrderedDeck.h"
#include "Player.h"

using namespace std;

RemodelCard::RemodelCard()
{
	
}
RemodelCard::~RemodelCard()
{

}
int RemodelCard::getCoinValue(Player *owner)
{
	return 0;
}
int RemodelCard::getVPValue(Player *owner)
{
	return 0;
}
void RemodelCard::playAction(Card *card, Player *owner, std::vector<Player*> &otherPlayers)
{
	Board *board = Board::boardGame;

	int priceOfTrashedCard = -1;

	if(owner->hand.cards.size() == 0)	// Player has no card to trash
	{
		stringstream output;
		output << "You had no cards to trash. REMODEL did nothing." << endl;
		owner->displayMessage(output.str(), false);

		stringstream globalOutput;
		globalOutput << owner->name << " had no cards to trash. REMODEL did nothing." << endl;
		owner->broadcastToOtherPlayers(globalOutput.str());
	}
	else if(owner->hand.cards.size() == 1)	// Player has to trash his only card
	{
		stringstream output;
		output << "You trash the card " << owner->hand.cards[0].name() << "." << endl;
		owner->displayMessage(output.str(), false);

		stringstream globalOutput;
		globalOutput << owner->name << " trashed the card " << owner->hand.cards[0].name() << "." << endl;
		owner->broadcastToOtherPlayers(globalOutput.str());

		priceOfTrashedCard = owner->hand.cards[0].price();

		owner->hand.cards[0].moveToAnotherDeck(board->trashPile);
	}
	else	// Player has to choose a card from his hand to trash
	{
		Decision cardToTrash("Select a card from your hand to trash:", owner);

		for(unsigned int ii = 0; ii < owner->hand.cards.size(); ii++)
		{
			cardToTrash.addOption(owner->hand.cards[ii].name());
		}

		int decisionResult = cardToTrash.makeDecision(false);

		stringstream output;
		output << "You trash the card " << owner->hand.cards[decisionResult].name() << "." << endl;
		owner->displayMessage(output.str(), false);

		stringstream globalOutput;
		globalOutput << owner->name << " trashed the card " << owner->hand.cards[decisionResult].name() << "." << endl;
		owner->broadcastToOtherPlayers(globalOutput.str());

		priceOfTrashedCard = owner->hand.cards[decisionResult].price();

		owner->hand.cards[decisionResult].moveToAnotherDeck(board->trashPile);
	}

	if(priceOfTrashedCard != -1)	// Player trashed a card
	{
		OrderedDeck gainableCards = board->getPurchasableCardsCostingUpToX(priceOfTrashedCard + 2);

		if(gainableCards.cards.size() == 0)	// No obtainable cards
		{
			stringstream output;
			output << "You could not obtain any cards with REMODEL." << endl;
			owner->displayMessage(output.str(), false);

			stringstream globalOutput;
			globalOutput << owner->name << " could not obtain any cards with REMODEL." << endl;
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
		else	// Player chooses what card to gain
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
}
void RemodelCard::playTreasure(Card *card, Player *owner, std::vector<Player*> &otherPlayers)
{

}
void RemodelCard::playDuration(Card *card, Player *owner, std::vector<Player*> &otherPlayers)
{

}
void RemodelCard::setUpCardOnBoard()
{

}
