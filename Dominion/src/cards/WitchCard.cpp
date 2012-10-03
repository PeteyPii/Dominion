#include "cards\WitchCard.h"

#include "Board.h"
#include "Card.h"
#include "OrderedDeck.h"
#include "Player.h"

using namespace std;

WitchCard::WitchCard()
{
	
}
WitchCard::~WitchCard()
{

}
int WitchCard::getCoinValue(Player *owner)
{
	return 0;
}
int WitchCard::getVPValue(Player *owner)
{
	return 0;
}
void WitchCard::playAction(Card *card, Player *owner, std::vector<Player*> &otherPlayers)
{
	owner->plusCards(2);

	Board *board = Board::boardGame;

	for(unsigned int ii = 0; ii < otherPlayers.size(); ii++)
	{
		if(!otherPlayers[ii]->preAttack())	// Player has no immunity to attack
		{
			OrderedDeck *cursePile = board->getSupplyDeckFromCardID(Card::CURSE_CARD);

			if(cursePile != 0)	// Pile is not empty
			{
				stringstream output;
				output << "You gained a CURSE card." << endl;
				otherPlayers[ii]->displayMessage(output.str(), false);

				stringstream globalOutput;
				globalOutput << otherPlayers[ii]->name << " gained a CURSE card." << endl;
				otherPlayers[ii]->broadcastToOtherPlayers(globalOutput.str());
			}
			else
			{
				stringstream output;
				output << "There were no CURSE cards left for you to gain." << endl;
				otherPlayers[ii]->displayMessage(output.str(), false);

				stringstream globalOutput;
				globalOutput << "There were no CURSE cards left for " << otherPlayers[ii]->name << " to gain." << endl;
				otherPlayers[ii]->broadcastToOtherPlayers(globalOutput.str());
			}
		}
	}
}
void WitchCard::playTreasure(Card *card, Player *owner, std::vector<Player*> &otherPlayers)
{

}
void WitchCard::playDuration(Card *card, Player *owner, std::vector<Player*> &otherPlayers)
{

}
void WitchCard::setUpCardOnBoard()
{

}
