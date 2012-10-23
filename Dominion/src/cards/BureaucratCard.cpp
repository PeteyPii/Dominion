#include "cards\BureaucratCard.h"

#include "Board.h"
#include "Card.h"
#include "Decision.h"
#include "OrderedDeck.h"
#include "Player.h"
#include <sstream>
#include <string>

using namespace std;

BureaucratCard::BureaucratCard()
{
	
}
BureaucratCard::~BureaucratCard()
{

}
int BureaucratCard::getPrice(Card *card, Player *owner, vector<Player*> *otherPlayers)
{
	return 4;
}
void BureaucratCard::playAction(Card *card, Player *owner, vector<Player*> &otherPlayers)
{
	OrderedDeck *silverDeck = Board::boardGame->getSupplyDeckFromCardID(Card::SILVER_CARD);

	if(silverDeck != 0)	// Got a real deck from the supply for SILVER cards
	{
		if(silverDeck->drawCard(owner->deck))
		{
			stringstream output;
			output << "You put a SILVER card on top of your deck." << endl;
			owner->displayMessage(output.str(), false);

			stringstream globalOutput;
			globalOutput << owner->name << " put a SILVER card on top of his deck." << endl;
			owner->broadcastToOtherPlayers(globalOutput.str());
		}
	}

	for(unsigned int ii = 0; ii < otherPlayers.size(); ii++)
	{
		if(!otherPlayers[ii]->preAttack())	// Player has no immunity to attack
		{
			vector<Card*> victoryPointCards = otherPlayers[ii]->hand.getListOfCardsMatchingType(Card::VICTORY_TYPE);

			if(victoryPointCards.size() == 0)	// Player has no VICTORY POINT cards in their hand
			{
				stringstream otherPlayerOutput;
				otherPlayerOutput << "You have no VICTORY POINT cards in your hand. Revealing your hand to everybody else." << endl;
				otherPlayers[ii]->displayMessage(otherPlayerOutput.str(), false);

				stringstream globalOutput;
				globalOutput << otherPlayers[ii]->name << " is revealing a hand with no VICTORY POINT cards." << endl;
				globalOutput << "His hand contains the cards: ";

				for(unsigned int jj = 0; jj < otherPlayers[ii]->hand.cards.size(); jj++)
				{
					if(jj == otherPlayers[ii]->hand.cards.size() - 2)
					{
						globalOutput << otherPlayers[ii]->hand.cards[jj].name() << ", and ";
					}
					else
					{
						globalOutput << otherPlayers[ii]->hand.cards[jj].name() << ", ";
					}
				}

				globalOutput << endl;

				otherPlayers[ii]->broadcastToOtherPlayers(globalOutput.str());
			}
			else if(victoryPointCards.size() == 1) 	// Hand contains a single VICTORY POINT card. Player must put it on top of his deck
			{
				stringstream otherPlayerOutput;
				otherPlayerOutput << "You must put your VICTORY POINT card in your hand on top of your deck." << endl;
				otherPlayerOutput << "You put the card " << victoryPointCards[0]->name() << " on top of your deck." << endl;
				otherPlayers[ii]->displayMessage(otherPlayerOutput.str(), false);

				stringstream globalOutput;
				globalOutput << otherPlayers[ii]->name << " revealed the card " << victoryPointCards[0]->name() << " from his hand and put it on top of his deck." << endl;
				otherPlayers[ii]->broadcastToOtherPlayers(globalOutput.str());

				victoryPointCards[0]->moveToAnotherDeck(otherPlayers[ii]->deck);
			}
			else	// Hand contains more than one VICTORY POINT card. Player must choose which one to put on top of his deck
			{
				Decision whichCard("Choose a VICTORY POINT card to put on top of your deck:", otherPlayers[ii]);

				for(unsigned int jj = 0; jj < victoryPointCards.size(); jj++)
				{
					whichCard.addOption(victoryPointCards[jj]->name());
				}

				int decisionResult = whichCard.makeDecision(false);

				stringstream otherPlayerOutput;
				otherPlayerOutput << "You put the card " << victoryPointCards[decisionResult]->name() << " on top of your deck." << endl;
				otherPlayers[ii]->displayMessage(otherPlayerOutput.str(), false);

				stringstream globalOutput;
				globalOutput << otherPlayers[ii]->name << " revealed the card " << victoryPointCards[decisionResult]->name() << " from his hand and put it on top of his deck." << endl;
				otherPlayers[ii]->broadcastToOtherPlayers(globalOutput.str());

				victoryPointCards[decisionResult]->moveToAnotherDeck(otherPlayers[ii]->deck);
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
