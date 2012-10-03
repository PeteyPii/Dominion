#include "cards\CellarCard.h"

#include "Card.h"
#include "Decision.h"
#include "OrderedDeck.h"
#include "Player.h"

using namespace std;

CellarCard::CellarCard()
{

}
CellarCard::~CellarCard()
{

}
int CellarCard::getCoinValue(Player *owner)
{
	return 0;
}
int CellarCard::getVPValue(Player *owner)
{
	return 0;
}
void CellarCard::playAction(Card *card, Player *owner, std::vector<Player*> &otherPlayers)
{
	owner->plusActions(1);

	int discardCount = 0;
	bool keepDiscarding = true;

	while(keepDiscarding)
	{
		Decision discardWhat("Select a card from your hand to discard:", owner);
		
		for(unsigned int ii = 0; ii < owner->hand.cards.size(); ii++)
		{
			discardWhat.addOption(owner->hand.cards[ii].name());
		}

		discardWhat.addOption("Do not discard a card");

		int decisionResult = discardWhat.makeDecision(false);

		if(decisionResult == (int)(discardWhat.choices.size() - 1))	// Do not discard
		{
			keepDiscarding = false;
		}
		else
		{
			discardCount++;

			string pluralCount = "s";

			if(discardCount == 1)
				pluralCount = "";

			stringstream outputTwo;
			outputTwo << "You discarded " << owner->hand.cards[decisionResult].name() << "." << endl;
			outputTwo << "You have discarded " << discardCount << "card" << pluralCount << " so far." << endl;

			owner->hand.cards[decisionResult].moveToAnotherDeck(owner->discardPile);
		}

		string pluralDiscardCount = "s";

		if(discardCount == 1)
			pluralDiscardCount = "";

		stringstream globalOutput;
		globalOutput << owner->name << " discarded " << discardCount << " card" << pluralDiscardCount << "." << endl;
		owner->broadcastToOtherPlayers(globalOutput.str());

		owner->plusCards(discardCount);
	}
}
void CellarCard::playTreasure(Card *card, Player *owner, std::vector<Player*> &otherPlayers)
{

}
void CellarCard::playDuration(Card *card, Player *owner, std::vector<Player*> &otherPlayers)
{

}
void CellarCard::setUpCardOnBoard()
{

}
