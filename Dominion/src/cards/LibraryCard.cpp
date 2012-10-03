#include "cards\LibraryCard.h"

#include "Card.h"
#include "Decision.h"
#include "OrderedDeck.h"
#include "Player.h"

using namespace std;

LibraryCard::LibraryCard()
{
	
}
LibraryCard::~LibraryCard()
{

}
int LibraryCard::getCoinValue(Player *owner)
{
	return 0;
}
int LibraryCard::getVPValue(Player *owner)
{
	return 0;
}
void LibraryCard::playAction(Card *card, Player *owner, std::vector<Player*> &otherPlayers)
{
	bool playerCanDraw = true;

	OrderedDeck setAsideActionCards;

	do 
	{
		playerCanDraw = owner->plusCards(1);

		if((owner->hand.cards[owner->hand.cards.size() - 1].cardType() & Card::ACTION_TYPE) > 0)	// Drew an ACTION card
		{
			stringstream formatter;
			formatter << "Set aside the card " << owner->hand.cards[owner->hand.cards.size() - 1].name() << " you just drew?";

			Decision setAsideActionCard(formatter.str(), owner);
			setAsideActionCard.addOption("Yes");
			setAsideActionCard.addOption("No");

			int decisionResult = setAsideActionCard.makeDecision(false);

			if(decisionResult == 0)	// Set aside the ACTION card
			{
				stringstream output;
				output << "You set aside the card " << owner->hand.cards[owner->hand.cards.size() - 1].name() << "." << endl;
				owner->displayMessage(output.str(), false);

				stringstream globalOutput;
				globalOutput << owner->name << " set aside the card " << owner->hand.cards[owner->hand.cards.size() - 1].name() << "." << endl;
				owner->broadcastToOtherPlayers(globalOutput.str());

				owner->hand.cards[owner->hand.cards.size() - 1].moveToAnotherDeck(setAsideActionCards);
			}
			else	// Keep the ACTION card
			{

			}
		}
	} while(owner->hand.cards.size() < 7);

	stringstream output;
	output << "You discarded all the cards you set aside." << endl;
	owner->displayMessage(output.str(), false);

	stringstream globalOutput;
	globalOutput << owner->name << " discarded all the cards he set aside." << endl;
	owner->broadcastToOtherPlayers(globalOutput.str());

	setAsideActionCards.moveContentsToAnotherDeck(owner->discardPile);
}
void LibraryCard::playTreasure(Card *card, Player *owner, std::vector<Player*> &otherPlayers)
{

}
void LibraryCard::playDuration(Card *card, Player *owner, std::vector<Player*> &otherPlayers)
{

}
void LibraryCard::setUpCardOnBoard()
{

}
