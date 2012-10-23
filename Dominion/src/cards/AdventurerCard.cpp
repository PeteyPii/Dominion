#include "cards\AdventurerCard.h"

#include "Card.h"
#include "OrderedDeck.h"
#include "Player.h"
#include <sstream>
#include <string>

using namespace std;

AdventurerCard::AdventurerCard()
{
	
}
AdventurerCard::~AdventurerCard()
{

}
int AdventurerCard::getPrice(Card *card, Player *owner, vector<Player*> *otherPlayers)
{
	return 6;
}
void AdventurerCard::playAction(Card *card, Player *owner, vector<Player*> &otherPlayers)
{
	OrderedDeck revealedCards;
	int treasureCardCount = 0;

	while(owner->drawCard(revealedCards) && treasureCardCount < 2)
	{
		stringstream output;
		output << "You revealed the card " << revealedCards.cards[revealedCards.cards.size() - 1].name() << "." << endl;
		owner->displayMessage(output.str(), false);

		stringstream globalOutput;
		globalOutput << owner->name << " revealed the card " << revealedCards.cards[revealedCards.cards.size() - 1].name() << "." << endl;
		owner->broadcastToOtherPlayers(globalOutput.str());

		if(revealedCards.cards[revealedCards.cards.size() - 1].cardType() == Card::TREASURE_TYPE)	// Revealed a treasure card
		{
			treasureCardCount++;
		}
	}

	for(unsigned int ii = revealedCards.cards.size() - 1; ii >= 0; ii--)
	{
		if(revealedCards.cards[ii].cardType() == Card::TREASURE_TYPE)
		{
			stringstream output;
			output << "You put the card " << revealedCards.cards[ii].name() << " into your hand." << endl;
			owner->displayMessage(output.str(), false);

			stringstream globalOutput;
			globalOutput << owner->name << " put the card " << revealedCards.cards[ii].name() << "into his hand." << endl;
			owner->broadcastToOtherPlayers(globalOutput.str());

			revealedCards.cards[ii].moveToAnotherDeck(owner->hand);
		}
		else
		{
			revealedCards.cards[ii].moveToAnotherDeck(owner->discardPile);
		}
	}

	stringstream outputTwo;
	outputTwo << "You discarded the remaining revealed cards." << endl;
	owner->displayMessage(outputTwo.str(), false);

	stringstream globalOutputTwo;
	globalOutputTwo << owner->name << " discarded the remaining revealed cards." << endl;
	owner->broadcastToOtherPlayers(globalOutputTwo.str());
}
