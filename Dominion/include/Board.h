#pragma once

#include "Card.h"
#include "OrderedDeck.h"
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

class Player;

class Board
{
private:
	Board();	// Have to use other constructor
public:
	static Board *boardGame;

	static void deckDepleted();
	static void lastVictoryPointCardDrawn();
	static void lastCardOfDeckDrawn();

	std::vector<Player> players;
	std::vector<OrderedDeck> kingdomDecks;
	std::vector<OrderedDeck> treasureDecks;
	std::vector<OrderedDeck> victoryPointDecks;
	std::vector<OrderedDeck> curseDecks;
	OrderedDeck trashPile;

	int maxNumberOfDecksGone;

	int numberOfDecksGone;
	bool gameIsOver;
	unsigned int firstPlayer;
	int numberOfTurns;

	int cardCost;
	
	Board(int numberOfDecks, int cardsPerDeck, int maxKingdomDecksGone, int numberOfVictoryCards, int numberOfCurseCards, int numberOfTreasureCards, std::vector<std::string> &playerNames);
	~Board();

	void beginGame();
	void endGame();

	OrderedDeck& getPurchasableCards();
	OrderedDeck* getSupplyDeckFromCardID(Card::CardIDs identifier);	// Never returns empty deck, can return 0 (AKA null)
	OrderedDeck getPurchasableCardsCostingUpToX(int x);
	OrderedDeck getPurchasableCardsCostingExactlyX(int x);

	unsigned int cyclePlayerNumber(int number);
private:
	OrderedDeck purchasableCards;

	void recreatePurchasableCards();
};
