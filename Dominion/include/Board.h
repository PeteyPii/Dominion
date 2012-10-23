#pragma once

#include "Card.h"
#include "OrderedDeck.h"
#include <vector>

class Player;

class Board
{
public:
	static Board *boardGame;

	static void deckDepleted();
	static void lastVictoryPointCardDrawn();
	static void lastCardOfDeckDrawn();

	std::vector<Player*> players;
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

	int tempCardCost;
	Player *tempPlayer;
	std::vector<Player*> *tempOtherPlayers;
	
	Board();
	~Board();

	void initializeGame(int numberOfDecks, int cardsPerDeck, int maxKingdomDecksGone, int numberOfVictoryCards, int numberOfCurseCards, int numberOfTreasureCards);
	void beginGame();
	void endGame();

	OrderedDeck& getPurchasableCards();
	OrderedDeck* getSupplyDeckFromCardID(Card::CardIDs identifier);				// Never returns empty deck, can return NULL
	OrderedDeck getPurchasableCardsCostingUpToX(int x, Player *buyer, std::vector<Player*> *otherPlayers);
	OrderedDeck getPurchasableCardsCostingExactlyX(int x, Player *buyer, std::vector<Player*> *otherPlayers);

	unsigned int cyclePlayerNumber(int number);
private:
	OrderedDeck purchasableCards;

	void recreatePurchasableCards();
};
