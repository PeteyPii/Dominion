#include "cards\MilitiaCard.h"

#include "Card.h"
#include "Decision.h"
#include "OrderedDeck.h"
#include "Player.h"
#include <sstream>
#include <string>

using namespace std;

MilitiaCard::MilitiaCard()
{
	
}
MilitiaCard::~MilitiaCard()
{

}
int MilitiaCard::getPrice(Card *card, Player *owner, vector<Player*> *otherPlayers)
{
	return 4;
}
void MilitiaCard::playAction(Card *card, Player *owner, vector<Player*> &otherPlayers)
{
	owner->plusCoins(2);

	for(unsigned int ii = 0; ii < otherPlayers.size(); ii++)
	{
		if(!otherPlayers[ii]->preAttack())	// Player has no immunity to attack
		{
			while(otherPlayers[ii]->hand.cards.size() > 3)
			{
				string pluralCards = "s";

				if(otherPlayers[ii]->hand.cards.size() == 4)
					pluralCards = "";

				stringstream formatter;
				formatter << "You must discard " << otherPlayers[ii]->hand.cards.size() - 3 << " more card" << pluralCards << "s. Choose a card to discard:";

				Decision cardToDiscard(formatter.str(), otherPlayers[ii]);

				for(unsigned int jj = 0; jj < otherPlayers[ii]->hand.cards.size(); jj++)
				{
					cardToDiscard.addOption(otherPlayers[ii]->hand.cards[jj].name());
				}

				int decisionResult = cardToDiscard.makeDecision(false);

				stringstream output;
				output << "You discarded the card " << otherPlayers[ii]->hand.cards[decisionResult].name() << "." << endl;
				otherPlayers[ii]->displayMessage(output.str(), false);

				stringstream globalOutput;
				globalOutput << otherPlayers[ii]->name << " discarded a card." << endl;
				otherPlayers[ii]->broadcastToOtherPlayers(globalOutput.str());

				otherPlayers[ii]->hand.cards[decisionResult].moveToAnotherDeck(otherPlayers[ii]->discardPile);
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
