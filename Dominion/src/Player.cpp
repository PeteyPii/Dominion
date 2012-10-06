#include "Player.h"

#include "Board.h"
#include "Card.h"
#include "Decision.h"

using namespace std;

Player::Player()
{
	name = "";
	actions = 0;
	buys = 0;
	coins = 0;
}
Player::~Player()
{
	socket.disconnect();
}
void Player::displayMessage(string &messageOutput, bool responseRequired)
{
	cout << name << " <- " << messageOutput;

	sf::Packet sendPacket;
	sendPacket << responseRequired << messageOutput;
	socket.send(sendPacket);
}
void Player::broadcastToOtherPlayers(string &messageOutput)
{
	for(unsigned int ii = 0; ii < otherPlayers.size(); ii++)
	{
		otherPlayers[ii]->displayMessage(messageOutput, false);
	}
}
string Player::getInput()
{
	sf::Packet receivedPacket;
	socket.receive(receivedPacket);

	string receivedText;
	receivedPacket >> receivedText;
	cout << name << " -> " << receivedText;
	return receivedText;
}
void Player::outputStats()
{
	string pluralCoins = "s", pluralActions = "s", pluralBuys = "s", pluralDeckSize = "s", pluralDiscardPileSize = "s";

	if(coins == 1)
		pluralCoins = "";

	if(actions == 1)
		pluralActions = "";

	if(buys == 1)
		pluralBuys = "";

	if(deck.cards.size() == 1)
		pluralDeckSize = "";

	if(discardPile.cards.size() == 1)
		pluralDiscardPileSize = "";

	stringstream output;
	output << "You have: " << coins << " coin" << pluralCoins << ", " << actions << " action" << pluralActions << ", and " << buys << " buy" << pluralBuys << "." << endl;
	output << "You have: " << deck.cards.size() << " card" << pluralDeckSize << " left in your deck and " << discardPile.cards.size() << " card" << pluralDiscardPileSize << " in your discard pile." << endl;
	displayMessage(output.str(), false);
}
void Player::outputHand()
{
	Decision getDescriptionDecision("To see a description of any of your cards, submit the corresponding number. To continue on, press enter. The cards in your hand are:", this);
	for(unsigned int ii = 0; ii < hand.cards.size(); ii++)
	{
		getDescriptionDecision.addOption(hand.cards[ii].name());
	}

	bool playerIsInterested = true;

	while(playerIsInterested)
	{
		int decisionResult = getDescriptionDecision.makeDecision(true);

		if(decisionResult == -1)	// Skip description check
		{
			playerIsInterested = false;
		}
		else
		{
			hand.cards[decisionResult].printNameAndDescription(this);
		}
	}
}
void Player::outputPlayerStatus()
{
	outputStats();
	outputHand();
}
void Player::playTurn()
{
	turnStart();
	playActions();
	useBuys();
	turnEnd();
}
void Player::turnStart()
{
	stringstream output;
	output << "---| " << name << " |---" << endl;
	displayMessage(output.str(), false);
	broadcastToOtherPlayers(output.str());

	actions = 1;
	buys = 1;
	coins = 0;
}
void Player::playActions()
{
	bool wantsToDoSomething = true;

	while(actions > 0 && wantsToDoSomething)
	{
		vector<Card*> actionCards = hand.getListOfCardsMatchingType(Card::ACTION_TYPE);

		if(actionCards.size() == 0)		// Has no action cards
		{
			stringstream output;
			output << "You have no ACTION cards, proceeding to the next phase." << endl;
			displayMessage(output.str(), false);

			wantsToDoSomething = false;
		}
		else
		{
			outputPlayerStatus();

			Decision cardToPlayDecision("Select an ACTION card by typing the corresponding number and then press enter. The cards you can play are:", this);

			for(unsigned int ii = 0; ii < actionCards.size(); ii++)
			{
				cardToPlayDecision.addOption(actionCards[ii]->name());
			}

			cardToPlayDecision.addOption("Do not play any action cards.");
			cardToPlayDecision.addOption("See player status.");

			bool actionDecisionOngoing = true;

			while(actionDecisionOngoing)
			{
				unsigned int decisionResult = cardToPlayDecision.makeDecision(false);

				if(decisionResult == cardToPlayDecision.choices.size() - 2)	// No action
				{
					stringstream secondaryOutput;
					secondaryOutput << "You chose not to play a card, proceeding to the next phase." << endl;
					displayMessage(secondaryOutput.str(), false);

					actionDecisionOngoing = false;
					wantsToDoSomething = false;
				}
				else if(decisionResult == cardToPlayDecision.choices.size() - 1)	// See player status
				{
					stringstream secondaryOutput;
					secondaryOutput << "Showing player status." << endl;
					displayMessage(secondaryOutput.str(), false);

					outputPlayerStatus();
				}
				else
				{
					actions--;

					stringstream playerOutput;
					playerOutput << "You played the card " << actionCards[decisionResult]->name() << "." << endl;
					displayMessage(playerOutput.str(), false);

					stringstream globalOutput;
					globalOutput << name << " played the card " << actionCards[decisionResult]->name() << "." << endl;
					broadcastToOtherPlayers(globalOutput.str());

					actionCards[decisionResult]->moveToAnotherDeck(cleanupPile);
					cleanupPile.cards[cleanupPile.cards.size() - 1].playAction(this, otherPlayers);

					actionDecisionOngoing = false;
				}
			}
		}
	}

	if(actions < 1)	// No more actions left
	{
		stringstream output;
		output << "You have no more actions, proceeding to the next phase." << endl;
		displayMessage(output.str(), false);
	}
}
void Player::useBuys()
{
	bool wantsToPlayTreasures = true;

	while(wantsToPlayTreasures)
	{
		outputPlayerStatus();

		Decision treasureCardToPlay("Select a TREASURE card to play by submitting the corresponding number:", this);
		
		vector<Card*> treaureCardsInHand = hand.getListOfCardsMatchingType(Card::TREASURE_TYPE);

		for(unsigned int ii = 0; ii < treaureCardsInHand.size(); ii++)
		{
			treasureCardToPlay.addOption(treaureCardsInHand[ii]->name());
		}

		treasureCardToPlay.addOption("Play all remaining TREASURE cards in hand.");
		treasureCardToPlay.addOption("Do not play any more TREASURE cards.");

		int cardToPlay = treasureCardToPlay.makeDecision(false);

		if(cardToPlay == treasureCardToPlay.choices.size() - 2) // Play all remaining TREASURE cards
		{
			for(unsigned int ii = treaureCardsInHand.size() - 1; ii < treaureCardsInHand.size(); ii--)
			{
				stringstream playerOutput;
				playerOutput << "You played the card " << treaureCardsInHand[ii]->name() << "." << endl;
				displayMessage(playerOutput.str(), false);

				stringstream globalOutput;
				globalOutput << name << " played the card " << treaureCardsInHand[ii]->name() << "." << endl;
				broadcastToOtherPlayers(globalOutput.str());
				
				treaureCardsInHand[ii]->moveToAnotherDeck(cleanupPile);
				cleanupPile.cards[cleanupPile.cards.size() - 1].playTreasure(this, otherPlayers);
			}

			wantsToPlayTreasures = false;
		}
		else if(cardToPlay == treasureCardToPlay.choices.size() - 1)	// Do not play any more cards
		{
			wantsToPlayTreasures = false;
		}
		else
		{
			stringstream playerOutput;
			playerOutput << "You played the card " << treaureCardsInHand[cardToPlay]->name() << "." << endl;
			displayMessage(playerOutput.str(), false);

			stringstream globalOutput;
			globalOutput << name << " played the card " << treaureCardsInHand[cardToPlay]->name() << "." << endl;
			broadcastToOtherPlayers(globalOutput.str());

			treaureCardsInHand[cardToPlay]->moveToAnotherDeck(cleanupPile);
			cleanupPile.cards[cleanupPile.cards.size() - 1].playTreasure(this, otherPlayers);
		}
	}

	Board *board = Board::boardGame;

	OrderedDeck &purchasableCards = board->getPurchasableCards();

	bool wantsToBuy = true;

	while(buys > 0 && wantsToBuy)
	{
		outputPlayerStatus();

		Decision cardToExamineDecision("Select a card to examine by submitting the corresponding number:", this);

		for(unsigned int ii = 0; ii < purchasableCards.cards.size(); ii++)
		{
			string hasEnoughCoinToken = "*";
			string pluralCoins = "s";

			if(purchasableCards.cards[ii].price() > coins)
			{
				hasEnoughCoinToken = "";
			}

			if(purchasableCards.cards[ii].price() == 1)
			{
				pluralCoins = "";
			}

			stringstream formatter;
			formatter << "{" << hasEnoughCoinToken << purchasableCards.cards[ii].price() << " coin" << pluralCoins << "} " << purchasableCards.cards[ii].name();

			cardToExamineDecision.addOption(formatter.str());
		}

		cardToExamineDecision.addOption("Do not examine any cards.");

		bool examineCards = true;

		while(examineCards)
		{
			int decisionResult = cardToExamineDecision.makeDecision(false);

			if(decisionResult == cardToExamineDecision.choices.size() - 1)	// Chose not to examine anything
			{
				string pluralBuys = "S";

				if(buys == 1)
					pluralBuys = "";

				stringstream output;
				output << "You chose not to use your remaining BUY" << pluralBuys << ". Cleaning up." << endl;
				displayMessage(output.str(), false);

				examineCards = false;
				wantsToBuy = false;
			}
			else
			{
				stringstream converter;

				converter << "Choose what you would like to do with the card " << purchasableCards.cards[decisionResult].name() << ":";

				Decision nextDecision(converter.str(), this);

				nextDecision.addOption("See name and description");
				nextDecision.addOption("Purchase card");
				nextDecision.addOption("Choose another card");

				bool lookingAtACard = true;

				while(lookingAtACard)
				{
					int nextDecisionResult = nextDecision.makeDecision(false);

					if(nextDecisionResult == 0)	// See name and description
					{
						purchasableCards.cards[decisionResult].printNameAndDescription(this);
					}
					else if(nextDecisionResult == 1)	// Buy the card
					{
						if(coins >= purchasableCards.cards[decisionResult].price())	// Player has enough coins
						{
							if(purchasableCards.cards[decisionResult].containerDeck->drawCard(discardPile))	// Deck is empty
							{
								stringstream secondaryOutput;
								secondaryOutput << "This deck has recently been depleted so you cannot purchase this card." << endl;
								displayMessage(secondaryOutput.str(), false);
							}
							else
							{
								coins -= purchasableCards.cards[decisionResult].price();
								buys--;

								lookingAtACard = false;
								examineCards = false;

								stringstream secondaryOutput;
								secondaryOutput << "You purchased the card " << purchasableCards.cards[decisionResult].name() << "." << endl;
								displayMessage(secondaryOutput.str(), false);

								stringstream globalOutput;
								globalOutput << name << " purchased the card " << purchasableCards.cards[decisionResult].name() << "." << endl;
								broadcastToOtherPlayers(globalOutput.str());
							}
						}
						else
						{
							stringstream secondaryOutput;
							secondaryOutput << "You do not have enough coins to purchase this card." << endl;
							displayMessage(secondaryOutput.str(), false);
						}
					}
					else if(nextDecisionResult == 2)	// Choose another card
					{
						lookingAtACard = false;
					}
				}
			}
		}
	}

	if(buys < 1)	// No more buys left
	{
		stringstream output;
		output << "You have no more BUYS, cleaning up." << endl;
		displayMessage(output.str(), false);
	}
}
void Player::turnEnd()
{
	discardCleanupPileAndObtainedPile();
	drawNewHand();

	stringstream firstOutput;
	firstOutput << "You have drawn new cards." << endl;
	displayMessage(firstOutput.str(), false);

	outputHand();

	stringstream output;
	output << "Press enter to end your turn." << endl;
	displayMessage(output.str(), true);

	getInput();	// Press enter to continue
}
void Player::discardHand()
{
	hand.moveContentsToAnotherDeck(discardPile);
}
void Player::discardCleanupPileAndObtainedPile()
{
	cleanupPile.moveContentsToAnotherDeck(discardPile);
}
void Player::swapDeckAndDiscardPile()
{
	deck.cards.swap(discardPile.cards);
	deck.shuffle();
}
bool Player::drawCard()
{
	return drawCard(hand);
}
bool Player::drawCard(OrderedDeck &deck)
{
	if(this->deck.drawCard(deck))	// No cards left in deck
	{
		swapDeckAndDiscardPile();

		if(this->deck.drawCard(deck))	// All cards in player's hand
		{
			return true;
		}
	}

	return false;
}
void Player::drawNewHand()
{
	discardHand();

	for(unsigned int ii = 0; ii < 5; ii++)
	{
		drawCard();
	}

	hand.sortByName();
}
bool Player::plusCards(int numberOfCards)
{
	for(int ii = 0; ii < numberOfCards; ii++)
	{
		if(!drawCard())	// Drew a card
		{
			stringstream output;
			output << "You drew the card " << hand.cards[hand.cards.size() - 1].name() << "." << endl;
			displayMessage(output.str(), false);

			stringstream globalOutput;
			globalOutput << name << " drew a card." << endl;
			broadcastToOtherPlayers(globalOutput.str());
		}
		else
		{
			stringstream output;
			output << "You could not draw any more cards." << endl;
			displayMessage(output.str(), false);

			stringstream globalOutput;
			globalOutput << name << " could not draw any more cards." << endl;
			broadcastToOtherPlayers(globalOutput.str());

			return true;
		}
	}

	return false;
}
void Player::plusActions(int numberOfActions)
{
	string pluralActions = "S";

	if(numberOfActions == 1)
		pluralActions = "";

	stringstream output;
	output << "You gained " << numberOfActions << " ACTION" << pluralActions << "." << endl;
	displayMessage(output.str(), false);

	stringstream globalOutput;
	globalOutput << name << " gained " << numberOfActions << " ACTION" << pluralActions << "." << endl;
	broadcastToOtherPlayers(globalOutput.str());

	actions += numberOfActions;
}
void Player::plusBuys(int numberOfBuys)
{
	string pluralBuys = "S";

	if(numberOfBuys == 1)
		pluralBuys = "";

	stringstream output;
	output << "You gained " << numberOfBuys << " BUY" << pluralBuys << "." << endl;
	displayMessage(output.str(), false);

	stringstream globalOutput;
	globalOutput << name << " gained " << numberOfBuys << " BUY" << pluralBuys << "." << endl;
	broadcastToOtherPlayers(globalOutput.str());

	buys += numberOfBuys;
}
void Player::plusCoins(int numberOfCoins)
{
	string pluralCoins = "S";

	if(numberOfCoins == 1)
		pluralCoins = "";

	stringstream output;
	output << "You gained " << numberOfCoins << " COIN" << pluralCoins << "." << endl;
	displayMessage(output.str(), false);

	stringstream globalOutput;
	globalOutput << name << " gained " << numberOfCoins << " COIN" << pluralCoins << "." << endl;
	broadcastToOtherPlayers(globalOutput.str());

	coins += numberOfCoins;
}
void Player::fixCointainerDeckPointersOfCards()
{
	deck.fixContainerDeckPointers();
	discardPile.fixContainerDeckPointers();
	hand.fixContainerDeckPointers();
	cleanupPile.fixContainerDeckPointers();
}
bool Player::preAttack()
{
	if(moatReact())
		return true;
	else
		return false;
}
bool Player::moatReact()
{
	vector<Card*> moatCards = hand.getListOfCardsMatchingID(Card::MOAT_CARD);

	if(moatCards.size() > 0)
	{
		Decision revealMoat("Reveal your MOAT?", this);

		revealMoat.addOption("Yes");
		revealMoat.addOption("No");

		int decisionResult = revealMoat.makeDecision(false);

		if(decisionResult == 0)	// Yes
		{
			stringstream output;
			output << "You reacted with the card MOAT." << endl;
			displayMessage(output.str(), false);

			stringstream globalOutput;
			globalOutput << name << " reacted with the card MOAT." << endl;
			broadcastToOtherPlayers(globalOutput.str());

			return true;
		}
		else	// No
		{
			stringstream output;
			output << "You chose not to react with MOAT." << endl;
			displayMessage(output.str(), false);

			return false;
		}
	}
	else	// No MOAT cards in hand
	{
		return false;
	}
}
