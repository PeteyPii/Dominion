#include "cards\ChancellorCard.h"

#include "Card.h"
#include "Decision.h"
#include "OrderedDeck.h"
#include "Player.h"

using namespace std;

ChancellorCard::ChancellorCard()
{
	
}
ChancellorCard::~ChancellorCard()
{

}
int ChancellorCard::getCoinValue(Player *owner)
{
	return 0;
}
int ChancellorCard::getVPValue(Player *owner)
{
	return 0;
}
void ChancellorCard::playAction(Card *card, Player *owner, std::vector<Player*> &otherPlayers)
{
	owner->plusCoins(2);

	Decision discardDeck("Would you like to move your deck to the discard pile?", owner);
	discardDeck.addOption("Yes");
	discardDeck.addOption("No");

	int decisionResult = discardDeck.makeDecision(false);

	if(decisionResult == 0)	// Player would like to discard their deck
	{
		stringstream output;
		output << "Your entire deck was moved to your discard pile." << endl;
		owner->displayMessage(output.str(), false);

		stringstream globalOutput;
		globalOutput << owner->name << " moved his entire deck to his discard pile." << endl;
		owner->broadcastToOtherPlayers(globalOutput.str());

		owner->deck.moveContentsToAnotherDeck(owner->discardPile);
	}
	else	// Player does not want to discard their deck
	{
		stringstream output;
		output << "You chose not to move your deck to your discard pile." << endl;
		owner->displayMessage(output.str(), false);

		stringstream globalOutput;
		globalOutput << owner->name << " chose not to move his deck to his discard pile." << endl;
		owner->broadcastToOtherPlayers(globalOutput.str());
	}
}
void ChancellorCard::playTreasure(Card *card, Player *owner, std::vector<Player*> &otherPlayers)
{

}
void ChancellorCard::playDuration(Card *card, Player *owner, std::vector<Player*> &otherPlayers)
{

}
void ChancellorCard::setUpCardOnBoard()
{

}
