#include "cards\ChapelCard.h"

#include "Board.h"
#include "Card.h"
#include "Decision.h"
#include "OrderedDeck.h"
#include "Player.h"

using namespace std;

ChapelCard::ChapelCard()
{

}
ChapelCard::~ChapelCard()
{

}
int ChapelCard::getCoinValue(Player *owner)
{
	return 0;
}
int ChapelCard::getVPValue(Player *owner)
{
	return 0;
}
void ChapelCard::playAction(Card *card, Player *owner, std::vector<Player*> &otherPlayers)
{
	int trashesLeft = 4;
	bool wantsToTrash = true;

	while(trashesLeft > 0 && wantsToTrash)
	{
		string pluralCards = "s";

		if(trashesLeft == 1)
			pluralCards = "";

		stringstream formatter;
		formatter << "You can trash " << trashesLeft << " more card" << pluralCards << ". Choose a card to trash:";
		Decision cardToTrash(formatter.str(), owner);

		for(unsigned int ii = 0; ii < owner->hand.cards.size(); ii++)
		{
			cardToTrash.addOption(owner->hand.cards[ii].name());
		}

		cardToTrash.addOption("Do not trash a card.");

		int decisionResult = cardToTrash.makeDecision(false);

		if(decisionResult == cardToTrash.choices.size() - 1)	// Do not trash a card
		{
			wantsToTrash = false;
		}
		else
		{
			stringstream outputOne;
			outputOne << "You trashed the card " << owner->hand.cards[decisionResult].name() << "." << endl;
			owner->displayMessage(outputOne.str(), false);

			stringstream globalOutputOne;
			globalOutputOne << owner->name << " trashed the card " << owner->hand.cards[decisionResult].name() << "." << endl;
			owner->broadcastToOtherPlayers(globalOutputOne.str());

			owner->hand.cards[decisionResult].moveToAnotherDeck(Board::boardGame->trashPile);
		}
	}
	
}
void ChapelCard::playTreasure(Card *card, Player *owner, std::vector<Player*> &otherPlayers)
{

}
void ChapelCard::playDuration(Card *card, Player *owner, std::vector<Player*> &otherPlayers)
{

}
void ChapelCard::setUpCardOnBoard()
{

}
