#include "cards\ThiefCard.h"

#include "Board.h"
#include "Card.h"
#include "Decision.h"
#include "OrderedDeck.h"
#include "Player.h"
#include <sstream>
#include <string>


using namespace std;

ThiefCard::ThiefCard()
{
	
}
ThiefCard::~ThiefCard()
{

}
int ThiefCard::getPrice(Card *card, Player *owner, vector<Player*> *otherPlayers)
{
	return 4;
}
void ThiefCard::playAction(Card *card, Player *owner, vector<Player*> &otherPlayers)
{
	Board *board = Board::boardGame;

	for(unsigned int ii = 0; ii < otherPlayers.size(); ii++)
	{
		if(!otherPlayers[ii]->preAttack())	// Player has no immunity to attack
		{
			OrderedDeck revealedCards;

			for(int jj = 0; jj < 2; jj++)
			{
				otherPlayers[ii]->drawCard(revealedCards);
			}

			if(revealedCards.cards.size() > 0)
			{
				for(unsigned int jj = 0; jj < revealedCards.cards.size(); jj++)
				{
					stringstream output;
					output << "You revealed the card " << revealedCards.cards[jj].name() << "." << endl;
					otherPlayers[ii]->displayMessage(output.str(), false);

					stringstream globalOutput;
					globalOutput << otherPlayers[ii]->name << " revealed the card " << revealedCards.cards[jj].name() << "." << endl;
					otherPlayers[ii]->broadcastToOtherPlayers(globalOutput.str());
				}

				vector<Card*> revealedTreasures = revealedCards.getListOfCardsMatchingType(Card::TREASURE_TYPE);

				if(revealedTreasures.size() == 0)
				{
					stringstream otherPlayerOutput;
					otherPlayerOutput << "You revealed no TREASURE cards. You discarded the revealed cards." << endl;
					otherPlayers[ii]->displayMessage(otherPlayerOutput.str(), false);

					stringstream globalOutput;
					globalOutput << otherPlayers[ii]->name << " revealed no TREASURE cards. He discarded the revealed cards." << endl;
					otherPlayers[ii]->broadcastToOtherPlayers(globalOutput.str());

					revealedCards.moveContentsToAnotherDeck(otherPlayers[ii]->discardPile);
				}
				else if(revealedTreasures.size() == 1)
				{
					stringstream otherPlayerOutput;
					otherPlayerOutput << "You trashed the card " << revealedTreasures[0]->name() << " and discarded the remaining revealed cards." << endl;
					otherPlayers[ii]->displayMessage(otherPlayerOutput.str(), false);

					stringstream globalOutput;
					globalOutput << otherPlayers[ii]->name << " trashed the card " << revealedTreasures[0]->name() << " and discarded the remaining revealed cards." << endl;
					otherPlayers[ii]->broadcastToOtherPlayers(globalOutput.str());

					stringstream formattar;
					formattar << "Gain the trashed card " << revealedTreasures[0]->name() << "?";

					Decision gainCard(formattar.str(), owner);

					gainCard.addOption("Yes");
					gainCard.addOption("No");

					int decisionResult = gainCard.makeDecision(false);

					if(decisionResult == 0)	// Yes
					{
						stringstream playerOutput;
						playerOutput << "You gained the trashed card " << revealedTreasures[0]->name() << "." << endl;
						owner->displayMessage(playerOutput.str(), false);

						stringstream globalOutput;
						globalOutput << otherPlayers[ii]->name << " gained the trashed card " << revealedTreasures[0]->name() << "." << endl;
						otherPlayers[ii]->broadcastToOtherPlayers(globalOutput.str());

						for(int jj = 2; jj >= 0; jj--)
						{
							if(revealedCards.cards[jj].cardType() == Card::TREASURE_TYPE)
							{
								revealedCards.cards[jj].moveToAnotherDeck(owner->discardPile);
							}
							else
							{
								revealedCards.cards[jj].moveToAnotherDeck(otherPlayers[ii]->discardPile);
							}
						}
					}
					else	// No
					{
						stringstream playerOutput;
						playerOutput << "You chose not to gain the trashed card." << endl;
						owner->displayMessage(playerOutput.str(), false);

						stringstream globalOutputTwo;
						globalOutputTwo << otherPlayers[ii]->name << " chose not to gain the trashed card." << endl;
						otherPlayers[ii]->broadcastToOtherPlayers(globalOutputTwo.str());

						for(int jj = 2; jj >= 0; jj--)
						{
							if(revealedCards.cards[jj].cardType() == Card::TREASURE_TYPE)
							{
								revealedCards.cards[jj].moveToAnotherDeck(board->trashPile);
							}
							else
							{
								revealedCards.cards[jj].moveToAnotherDeck(otherPlayers[ii]->discardPile);
							}
						}
					}
				}
				else if(revealedTreasures.size() == 2)
				{
					if(revealedTreasures[0]->cardID == revealedTreasures[1]->cardID)
					{
						stringstream otherPlayerOutput;
						otherPlayerOutput << "You trashed the card " << revealedTreasures[0]->name() << " and discarded the remaining revealed cards." << endl;
						otherPlayers[ii]->displayMessage(otherPlayerOutput.str(), false);

						stringstream globalOutput;
						globalOutput << otherPlayers[ii]->name << " trashed the card " << revealedTreasures[0]->name() << " and discarded the remaining revealed cards." << endl;
						otherPlayers[ii]->broadcastToOtherPlayers(globalOutput.str());

						stringstream formattar;
						formattar << "Gain the trashed card " << revealedTreasures[0]->name() << "?";

						Decision gainCard(formattar.str(), owner);

						gainCard.addOption("Yes");
						gainCard.addOption("No");

						int decisionResult = gainCard.makeDecision(false);

						if(decisionResult == 0)	// Yes
						{
							stringstream playerOutput;
							playerOutput << "You gained the trashed card " << revealedTreasures[0]->name() << "." << endl;
							owner->displayMessage(playerOutput.str(), false);

							stringstream globalOutputTwo;
							globalOutputTwo << otherPlayers[ii]->name << " gained the trashed card " << revealedTreasures[0]->name() << "." << endl;
							otherPlayers[ii]->broadcastToOtherPlayers(globalOutputTwo.str());
							
							revealedCards.cards[1].moveToAnotherDeck(owner->discardPile);
							revealedCards.cards[0].moveToAnotherDeck(otherPlayers[ii]->discardPile);
						}
						else	// No
						{
							stringstream playerOutput;
							playerOutput << "You chose not to gain the trashed card." << endl;
							owner->displayMessage(playerOutput.str(), false);

							stringstream globalOutput;
							globalOutput << otherPlayers[ii]->name << " chose not to gain the trashed card." << endl;
							otherPlayers[ii]->broadcastToOtherPlayers(globalOutput.str());

							revealedCards.cards[1].moveToAnotherDeck(board->trashPile);
							revealedCards.cards[0].moveToAnotherDeck(otherPlayers[ii]->discardPile);
						}
					}
					else
					{
						stringstream formattar;
						formattar << "Choose a card for " << otherPlayers[ii]->name << " to trash:";

						Decision trashCard(formattar.str(), owner);

						for(int jj = 0; jj < 2; jj++)
						{
							trashCard.addOption(revealedTreasures[jj]->name());
						}

						int trashDecisionResult = trashCard.makeDecision(false);

						stringstream otherPlayerOutput;
						otherPlayerOutput << "You trashed the card " << revealedTreasures[trashDecisionResult]->name() << " and discarded the remaining revealed cards." << endl;
						otherPlayers[ii]->displayMessage(otherPlayerOutput.str(), false);

						stringstream globalOutput;
						globalOutput << otherPlayers[ii]->name << " trashed the card " << revealedTreasures[trashDecisionResult]->name() << " and discarded the remaining revealed cards." << endl;
						otherPlayers[ii]->broadcastToOtherPlayers(globalOutput.str());

						stringstream formattarTwo;
						formattarTwo << "Gain the trashed card " << revealedTreasures[trashDecisionResult]->name() << "?";

						Decision gainCard(formattarTwo.str(), owner);

						gainCard.addOption("Yes");
						gainCard.addOption("No");

						int decisionResult = gainCard.makeDecision(false);

						if(decisionResult == 0)	// Yes
						{
							stringstream playerOutput;
							playerOutput << "You gained the trashed card " << revealedTreasures[0]->name() << "." << endl;
							owner->displayMessage(playerOutput.str(), false);

							stringstream globalOutput;
							globalOutput << otherPlayers[ii]->name << " gained the trashed card " << revealedTreasures[0]->name() << "." << endl;
							otherPlayers[ii]->broadcastToOtherPlayers(globalOutput.str());

							if(trashDecisionResult == 1)
							{
								revealedCards.cards[1].moveToAnotherDeck(owner->discardPile);
								revealedCards.cards[0].moveToAnotherDeck(otherPlayers[ii]->discardPile);
							}
							else
							{
								revealedCards.cards[1].moveToAnotherDeck(otherPlayers[ii]->discardPile);
								revealedCards.cards[0].moveToAnotherDeck(owner->discardPile);
							}
						}
						else	// No
						{
							stringstream playerOutput;
							playerOutput << "You chose not to gain the trashed card." << endl;
							owner->displayMessage(playerOutput.str(), false);

							stringstream globalOutputTwo;
							globalOutputTwo << otherPlayers[ii]->name << " chose not to gain the trashed card." << endl;
							otherPlayers[ii]->broadcastToOtherPlayers(globalOutputTwo.str());

							if(trashDecisionResult == 1)
							{
								revealedCards.cards[1].moveToAnotherDeck(board->trashPile);
								revealedCards.cards[0].moveToAnotherDeck(otherPlayers[ii]->discardPile);
							}
							else
							{
								revealedCards.cards[1].moveToAnotherDeck(otherPlayers[ii]->discardPile);
								revealedCards.cards[0].moveToAnotherDeck(board->trashPile);
							}
						}
					}
				}
			}
			else
			{
				stringstream otherPlayerOutput;
				otherPlayerOutput << "You did not reveal any cards because you could not." << endl;
				otherPlayers[ii]->displayMessage(otherPlayerOutput.str(), false);

				stringstream globalOutput;
				globalOutput << otherPlayers[ii]->name << " did not reveal any cards because he could not." << endl;
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
