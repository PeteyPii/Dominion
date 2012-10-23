#include "cards\MineCard.h"

#include "Board.h"
#include "Card.h"
#include "Decision.h"
#include "OrderedDeck.h"
#include "Player.h"
#include <sstream>
#include <string>

using namespace std;

MineCard::MineCard()
{
	
}
MineCard::~MineCard()
{

}
int MineCard::getPrice(Card *card, Player *owner, vector<Player*> *otherPlayers)
{
	return 5;
}
void MineCard::playAction(Card *card, Player *owner, vector<Player*> &otherPlayers)
{
	Board *board = Board::boardGame;

	vector<Card*> treasureCardsInHand = owner->hand.getListOfCardsMatchingType(Card::TREASURE_TYPE);

	int priceOfTrashedCard = -1;

	if(treasureCardsInHand.size() == 0)	// Player has no TREASURE cards
	{
		stringstream output;
		output << "You have no TREASURE cards to trash." << endl;
		owner->displayMessage(output.str(), false);

		stringstream globalOutput;
		globalOutput << owner->name << " has no TREASURE cards to trash." << endl;
		owner->broadcastToOtherPlayers(globalOutput.str());
	}
	else if(treasureCardsInHand.size() == 1)
	{
		stringstream output;
		output << "You trashed the card " << treasureCardsInHand[0]->name() << "." << endl;
		owner->displayMessage(output.str(), false);

		stringstream globalOutput;
		globalOutput << owner->name << " trashed the card " << treasureCardsInHand[0]->name() << "." << endl;
		owner->broadcastToOtherPlayers(globalOutput.str());

		priceOfTrashedCard = treasureCardsInHand[0]->getPrice(treasureCardsInHand[0], owner, otherPlayers);

		treasureCardsInHand[0]->moveToAnotherDeck(board->trashPile);
	}
	else	// Player has more than one TREASURE card
	{
		Decision treasureCardToTrash("Select a TREASURE card to trash:", owner);

		for(unsigned int ii = 0; ii < treasureCardsInHand.size(); ii++)
		{
			treasureCardToTrash.addOption(treasureCardsInHand[ii]->name());
		}

		int decisionResult = treasureCardToTrash.makeDecision(false);

		stringstream output;
		output << "You trashed the card " << treasureCardsInHand[decisionResult]->name() << "." << endl;
		owner->displayMessage(output.str(), false);

		stringstream globalOutput;
		globalOutput << owner->name << " trashed the card " << treasureCardsInHand[decisionResult]->name() << "." << endl;
		owner->broadcastToOtherPlayers(globalOutput.str());

		priceOfTrashedCard = treasureCardsInHand[decisionResult]->getPrice(treasureCardsInHand[decisionResult], owner, otherPlayers);

		treasureCardsInHand[decisionResult]->moveToAnotherDeck(board->trashPile);
	}
	
	if(priceOfTrashedCard == -1)	// Player did not trash a card
	{
		stringstream output;
		output << "You cannot gain a card because you did not trash a TREASURE card." << endl;
		owner->displayMessage(output.str(), false);

		stringstream globalOutput;
		globalOutput << owner->name << " could not gain a card because he did not trash a TREASURE card." << endl;
		owner->broadcastToOtherPlayers(globalOutput.str());
	}
	else
	{
		OrderedDeck purchasableCards = board->getPurchasableCardsCostingUpToX(priceOfTrashedCard + 3, owner, &otherPlayers);

		vector<Card*> buyableCards = purchasableCards.getListOfCardsMatchingType(Card::TREASURE_TYPE);

		if(buyableCards.size() == 0)
		{
			stringstream output;
			output << "You could not obtain any TREASURE cards with MINE." << endl;
			owner->displayMessage(output.str(), false);

			stringstream globalOutput;
			globalOutput << owner->name << " could not obtain any TREASURE cards with MINE." << endl;
			owner->broadcastToOtherPlayers(globalOutput.str());
		}
		else if(buyableCards.size() == 1)
		{
			stringstream output;
			output << "You gained the card " << buyableCards[0]->name() << " and put it into your hand." << endl;
			owner->displayMessage(output.str(), false);

			stringstream globalOutput;
			globalOutput << owner->name << " gained the card " << buyableCards[0]->name() << " and put it into his hand." << endl;
			owner->broadcastToOtherPlayers(globalOutput.str());

			buyableCards[0]->containerDeck->drawCard(owner->hand);
		}
		else
		{
			Decision cardToGain("Select a TREASURE card to gain:", owner);

			for(unsigned int ii = 0; ii < buyableCards.size(); ii++)
			{
				cardToGain.addOption(buyableCards[ii]->name());
			}

			int decisionResult = cardToGain.makeDecision(false);

			stringstream output;
			output << "You gained the card " << buyableCards[decisionResult]->name() << " and put it into your hand." << endl;
			owner->displayMessage(output.str(), false);

			stringstream globalOutput;
			globalOutput << owner->name << " gained the card " << buyableCards[decisionResult]->name() << " and put it into his hand." << endl;
			owner->broadcastToOtherPlayers(globalOutput.str());

			buyableCards[decisionResult]->containerDeck->drawCard(owner->hand);
		}
	}
}
