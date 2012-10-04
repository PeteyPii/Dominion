#include "Board.h"

#include "Cards.h"
#include "Decision.h"
#include "Player.h"
#include "RandomNumber.h"

using namespace std;

Board* Board::boardGame = 0;

void Board::deckDepleted()
{
	boardGame->recreatePurchasableCards();
}
void Board::lastVictoryPointCardDrawn()
{
	deckDepleted();

	boardGame->endGame();
}
void Board::lastCardOfDeckDrawn()
{
	deckDepleted();

	boardGame->numberOfDecksGone++;

	if(boardGame->numberOfDecksGone >= boardGame->maxNumberOfDecksGone)	// Too many kingdom decks gone
	{
		boardGame->endGame();
	}
}
Board::Board()
{

}
Board::Board(int numberOfDecks, int cardsPerDeck, int maxDecksGone, int numberOfVictoryCards, int numberOfCurseCards, int numberOfTreasureCards, std::vector<Player> &undefinedPlayers)
{
	boardGame = this;

	OrderedDeck allKingdomCards = Cards::allKingdomCards();
	allKingdomCards.shuffle();
	OrderedDeck treasureCards = Cards::allTreasureCards();
	OrderedDeck victoryPointCards = Cards::allVictoryPointCards();
	OrderedDeck curseCards = Cards::allCurseCards();

	for(int ii = 0; ii < numberOfDecks; ii++)
	{
		kingdomDecks.push_back(OrderedDeck());

		for(int jj = 0; jj < cardsPerDeck; jj++)
		{
			kingdomDecks[ii].addCard(allKingdomCards.cards[ii]);
		}

		kingdomDecks[ii].endOfDeckCallback = lastCardOfDeckDrawn;
	}
	
	for(unsigned int ii = 0; ii < treasureCards.cards.size(); ii++)
	{
		treasureDecks.push_back(OrderedDeck());

		for(int jj = 0; jj < numberOfTreasureCards; jj++)
		{
			treasureDecks[ii].addCard(treasureCards.cards[ii]);
		}

		treasureDecks[ii].endOfDeckCallback = lastCardOfDeckDrawn;
	}

	for(unsigned int ii = 0; ii < victoryPointCards.cards.size(); ii++)
	{
		victoryPointDecks.push_back(OrderedDeck());

		for(int jj = 0; jj < numberOfVictoryCards; jj++)
		{
			victoryPointDecks[ii].addCard(victoryPointCards.cards[ii]);
		}

		victoryPointDecks[ii].endOfDeckCallback = lastCardOfDeckDrawn;

		if(victoryPointDecks[ii].cards[0].cardID == Card::PROVINCE_CARD)
		{
			victoryPointDecks[ii].endOfDeckCallback = lastVictoryPointCardDrawn;
		}
	}

	for(unsigned int ii = 0; ii < curseCards.cards.size(); ii++)
	{
		curseDecks.push_back(OrderedDeck());

		for(int jj = 0; jj < numberOfCurseCards; jj++)
		{
			curseDecks[ii].addCard(curseCards.cards[ii]);
		}

		curseDecks[ii].endOfDeckCallback = lastCardOfDeckDrawn;
	}

	for(unsigned int ii = 0; ii < undefinedPlayers.size(); ii++)
	{
		Player tempPlayer;

		stringstream converter;
		converter << undefinedPlayers[ii];
		tempPlayer.name = converter.str();

		OrderedDeck startingDeck;

		int numberOfInitialCopperCards = 7;
		int numberOfInitialEstateCards = 3;

		Card copperCard, estateCard;
		copperCard.cardID = Card::COPPER_CARD;
		estateCard.cardID = Card::ESTATE_CARD;

		for(int jj = 0; jj < numberOfInitialCopperCards; jj++)
		{
			startingDeck.addCard(copperCard);
		}

		for(int jj = 0; jj < numberOfInitialEstateCards; jj++)
		{
			startingDeck.addCard(estateCard);
		} 

		startingDeck.shuffle();
		tempPlayer.deck = startingDeck;
		
		tempPlayer.drawNewHand();

		players.push_back(tempPlayer);
		players[ii].fixCointainerDeckPointersOfCards();
	}

	for(unsigned int ii = 0; ii < undefinedPlayers.size(); ii++)
	{
		for(unsigned int jj = ii + 1; jj < undefinedPlayers.size() + ii; jj++)
		{
			players[ii].otherPlayers.push_back(&players[cyclePlayerNumber(jj)]);
		}
	}

	maxNumberOfDecksGone = maxDecksGone;

	numberOfDecksGone = 0;
	gameIsOver = false;
	firstPlayer = RandomNumber::random() % players.size();
	numberOfTurns = 0;

	cardCost = 0;

	recreatePurchasableCards();
}
Board::~Board()
{

}
void Board::beginGame()
{
	int turn = (int)firstPlayer;

	while(!gameIsOver)
	{
		if(turn % players.size() == (int)firstPlayer)
		{
			numberOfTurns++;
		}

		players[cyclePlayerNumber(turn)].playTurn();

		turn++;
	}

	endGame();
}
void Board::endGame()
{
	unsigned int winningPlayer = 0;
	int highestScore = -999;

	for(unsigned int ii = 0; ii < players.size(); ii++)
	{
		players[ii].hand.moveContentsToAnotherDeck(players[ii].deck);
		players[ii].discardPile.moveContentsToAnotherDeck(players[ii].deck);
		players[ii].cleanupPile.moveContentsToAnotherDeck(players[ii].deck);

		int deckValue = players[ii].deck.victoryPointValueOfDeck(&players[ii]);

		if(deckValue > highestScore)
		{
			highestScore = deckValue;
			winningPlayer = ii;
		}
	}

	string pluralPoints = "s";

	if(highestScore == 1)
		pluralPoints = "";

	stringstream output;
	output << "You won the game with " << highestScore << " point" << pluralPoints <<  "." << endl;
	players[winningPlayer].displayMessage(output.str(), false);

	stringstream globalOutput;
	globalOutput << players[winningPlayer].name << "  won the game with " << highestScore << " point" << pluralPoints <<  "." << endl;
	players[winningPlayer].broadcastToOtherPlayers(globalOutput.str());
}
OrderedDeck& Board::getPurchasableCards()
{
	return purchasableCards;
}
OrderedDeck* Board::getSupplyDeckFromCardID(Card::CardIDs identifier)
{
	for(unsigned int ii = 0; ii < kingdomDecks.size(); ii++)
	{
		if(!kingdomDecks[ii].isEmpty())	// Deck has not been depleted
		{
			if(kingdomDecks[ii].cards[0].cardID == identifier)	// Match of ID
			{
				return &kingdomDecks[ii];
			}
		}
	}

	for(unsigned int ii = 0; ii < treasureDecks.size(); ii++)
	{
		if(!treasureDecks[ii].isEmpty())	// Deck has not been depleted
		{
			if(treasureDecks[ii].cards[0].cardID == identifier)	// Match of ID
			{
				return &treasureDecks[ii];
			}
		}
	}

	for(unsigned int ii = 0; ii < victoryPointDecks.size(); ii++)
	{
		if(!victoryPointDecks[ii].isEmpty())	// Deck has not been depleted
		{
			if(victoryPointDecks[ii].cards[0].cardID == identifier)	// Match of ID
			{
				return &victoryPointDecks[ii];
			}
		}
	}

	for(unsigned int ii = 0; ii < curseDecks.size(); ii++)
	{
		if(!curseDecks[ii].isEmpty())	// Deck has not been depleted
		{
			if(curseDecks[ii].cards[0].cardID == identifier)	// Match of ID
			{
				return &curseDecks[ii];
			}
		}
	}

	return 0;
}
bool cardDoesNotCostX(Card& card)
{
	return card.price() != Board::boardGame->cardCost;
}
bool cardCostsMoreThanX(Card& card)
{
	return card.price() > Board::boardGame->cardCost;
}
OrderedDeck Board::getPurchasableCardsCostingUpToX(int x)
{
	OrderedDeck returnDeck = purchasableCards;

	cardCost = x;

	returnDeck.cards.erase(remove_if(returnDeck.cards.begin(), returnDeck.cards.end(), cardCostsMoreThanX), returnDeck.cards.end());

	cardCost = 0;

	return returnDeck;
}
OrderedDeck Board::getPurchasableCardsCostingExactlyX(int x)
{
	OrderedDeck returnDeck = purchasableCards;

	cardCost = x;

	returnDeck.cards.erase(remove_if(returnDeck.cards.begin(), returnDeck.cards.end(), cardDoesNotCostX), returnDeck.cards.end());

	cardCost = 0;

	return returnDeck;
}
unsigned int Board::cyclePlayerNumber(int number)
{
	return (unsigned int)(((number % players.size()) + players.size())% players.size());
}
void Board::recreatePurchasableCards()
{
	purchasableCards.cards.clear();

	for(unsigned int ii = 0; ii < kingdomDecks.size(); ii++)
	{
		if(!kingdomDecks[ii].isEmpty())	// Deck has not been depleted
		{
			purchasableCards.cards.push_back(kingdomDecks[ii].cards[0]);
		}
	}

	for(unsigned int ii = 0; ii < treasureDecks.size(); ii++)
	{
		if(!treasureDecks[ii].isEmpty())	// Deck has not been depleted
		{
			purchasableCards.cards.push_back(treasureDecks[ii].cards[0]);
		}
	}

	for(unsigned int ii = 0; ii < victoryPointDecks.size(); ii++)
	{
		if(!victoryPointDecks[ii].isEmpty())	// Deck has not been depleted
		{
			purchasableCards.cards.push_back(victoryPointDecks[ii].cards[0]);
		}
	}

	for(unsigned int ii = 0; ii < curseDecks.size(); ii++)
	{
		if(!curseDecks[ii].isEmpty())	// Deck has not been depleted
		{
			purchasableCards.cards.push_back(curseDecks[ii].cards[0]);
		}
	}

	purchasableCards.sortByCostThenName();
}
