#include "cards\MoneylenderCard.h"

#include "Board.h"
#include "Card.h"
#include "Decision.h"
#include "OrderedDeck.h"
#include "Player.h"

using namespace std;

MoneylenderCard::MoneylenderCard()
{
	
}
MoneylenderCard::~MoneylenderCard()
{

}
int MoneylenderCard::getCoinValue(Player *owner)
{
	return 0;
}
int MoneylenderCard::getVPValue(Player *owner)
{
	return 0;
}
void MoneylenderCard::playAction(Card *card, Player *owner, std::vector<Player*> &otherPlayers)
{
	vector<Card*> copperCards = owner->hand.getListOfCardsMatchingID(Card::COPPER_CARD);

	if(copperCards.size() > 0)	// Player has a COPPER card
	{
		stringstream output;
		output << "You trashed a COPPER card." << endl;
		owner->displayMessage(output.str(), false);

		stringstream globalOutput;
		globalOutput << owner->name << " trashed a COPPER card." << endl;
		owner->broadcastToOtherPlayers(globalOutput.str());

		copperCards[0]->moveToAnotherDeck(Board::boardGame->trashPile);

		owner->plusCoins(3);
	}
	else	// Player has no COPPER cards in their hand
	{
		stringstream output;
		output << "You had no COPPPER cards to trash. MONEYLENDER did nothing." << endl;
		owner->displayMessage(output.str(), false);

		stringstream globalOutput;
		globalOutput << owner->name << " had no COPPPER cards to trash. MONEYLENDER did nothing." << endl;
		owner->broadcastToOtherPlayers(globalOutput.str());
	}
}
void MoneylenderCard::playTreasure(Card *card, Player *owner, std::vector<Player*> &otherPlayers)
{

}
void MoneylenderCard::playDuration(Card *card, Player *owner, std::vector<Player*> &otherPlayers)
{

}
void MoneylenderCard::setUpCardOnBoard()
{

}
