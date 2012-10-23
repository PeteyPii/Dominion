#include "cards\SpyCard.h"

#include "Card.h"
#include "Decision.h"
#include "OrderedDeck.h"
#include "Player.h"
#include <sstream>
#include <string>


using namespace std;

SpyCard::SpyCard()
{
	
}
SpyCard::~SpyCard()
{

}
int SpyCard::getPrice(Card *card, Player *owner, vector<Player*> *otherPlayers)
{
	return 4;
}
void SpyCard::playAction(Card *card, Player *owner, vector<Player*> &otherPlayers)
{
	owner->plusCards(1);

	owner->plusActions(1);

	OrderedDeck ownersRevealedCard;

	if(owner->drawCard(ownersRevealedCard))
	{
		stringstream output;
		output << "You revealed the card " << ownersRevealedCard.cards[0].name() << "." << endl;
		owner->displayMessage(output.str(), false);

		Decision leaveOrDiscard("Discard or put back the revealed card?", owner);

		leaveOrDiscard.addOption("Discard the revealed card");
		leaveOrDiscard.addOption("Put the revealed card back on your deck");

		int decisionResult = leaveOrDiscard.makeDecision(false);

		if(decisionResult == 0)	// Discard the revealed card
		{
			stringstream outputTwo;
			outputTwo << "You discard the revealed card " << ownersRevealedCard.cards[0].name() << "." << endl;
			owner->displayMessage(outputTwo.str(), false);

			stringstream globalOutput;
			globalOutput << owner->name << " revealed a card and discarded it." << endl;
			owner->broadcastToOtherPlayers(globalOutput.str());

			ownersRevealedCard.cards[0].moveToAnotherDeck(owner->discardPile);
		}
		else	// Put it back
		{
			stringstream outputTwo;
			outputTwo << "You put the revealed card " << ownersRevealedCard.cards[0].name() << " back." << endl;
			owner->displayMessage(outputTwo.str(), false);

			stringstream globalOutput;
			globalOutput << owner->name << " revealed a card and put it back." << endl;
			owner->broadcastToOtherPlayers(globalOutput.str());

			ownersRevealedCard.cards[0].moveToAnotherDeck(owner->deck);
		}
	}
	else
	{
		stringstream output;
		output << "You had no card to draw and reveal." << endl;
		owner->displayMessage(output.str(), false);

		stringstream globalOutput;
		globalOutput << owner->name << " had no card to draw and reveal." << endl;
		owner->broadcastToOtherPlayers(globalOutput.str());
	}

	for(unsigned int ii = 0; ii < otherPlayers.size(); ii++)
	{
		if(!otherPlayers[ii]->preAttack())	// Player has no immunity to attack
		{
			OrderedDeck revealedCard;

			if(otherPlayers[ii]->drawCard(revealedCard))
			{
				stringstream output;
				output << "You revealed the card " << revealedCard.cards[0].name() << "." << endl;
				otherPlayers[ii]->displayMessage(output.str(), false);

				stringstream globalOutput;
				globalOutput << otherPlayers[ii]->name << " revealed the card " << revealedCard.cards[0].name() << "." << endl;
				otherPlayers[ii]->broadcastToOtherPlayers(globalOutput.str());

				Decision leaveOrDiscard("Discard or put back the revealed card?", owner);

				leaveOrDiscard.addOption("Discard the revealed card");
				leaveOrDiscard.addOption("Put the revealed card back on your deck");

				int decisionResult = leaveOrDiscard.makeDecision(false);

				if(decisionResult == 0)	// Discard the revealed card
				{
					stringstream outputTwo;
					outputTwo << "You discard the revealed card " << revealedCard.cards[0].name() << "." << endl;
					otherPlayers[ii]->displayMessage(outputTwo.str(), false);

					stringstream globalOutputTwo;
					globalOutputTwo << otherPlayers[ii]->name << " revealed the card " << revealedCard.cards[0].name() << " and discarded it." << endl;
					otherPlayers[ii]->broadcastToOtherPlayers(globalOutputTwo.str());

					revealedCard.cards[0].moveToAnotherDeck(owner->discardPile);
				}
				else	// Put it back
				{
					stringstream outputTwo;
					outputTwo << "You put the revealed card " << revealedCard.cards[0].name() << " back." << endl;
					otherPlayers[ii]->displayMessage(outputTwo.str(), false);

					stringstream globalOutputTwo;
					globalOutputTwo << owner->name << " revealed the card " << revealedCard.cards[0].name() << " and put it back." << endl;
					otherPlayers[ii]->broadcastToOtherPlayers(globalOutputTwo.str());

					revealedCard.cards[0].moveToAnotherDeck(owner->deck);
				}
			}
			else
			{
				stringstream output;
				output << "You had no card to draw and reveal." << endl;
				otherPlayers[ii]->displayMessage(output.str(), false);

				stringstream globalOutput;
				globalOutput << otherPlayers[ii]->name << " had no card to draw and reveal." << endl;
				otherPlayers[ii]->broadcastToOtherPlayers(globalOutput.str());
			}
		}
		else	// Player is immune to the attack
		{
			stringstream otherPlayerOutput;
			otherPlayerOutput << "You were immune to the attack." << endl;
			otherPlayers[ii]->displayMessage(otherPlayerOutput.str(), false);

			stringstream globalOutput;
			globalOutput << otherPlayers[ii]->name << " was immune to the attack." << endl;
			otherPlayers[ii]->broadcastToOtherPlayers(globalOutput.str());
		}
	}
}
