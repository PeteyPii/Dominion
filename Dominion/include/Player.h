#pragma once

#include "OrderedDeck.h"
#include <SFML/Network.hpp>
#include <string>
#include <vector>

class Player
{
public:
	std::string name;
	int actions;
	int buys;
	int coins;
	OrderedDeck hand;
	OrderedDeck deck;
	OrderedDeck cleanupPile;
	OrderedDeck discardPile;
	std::vector<Player*> otherPlayers;

	sf::TcpSocket socket;

	Player();
	~Player();

	void displayMessage(std::string &messageOutput, bool responseRequired);
	void broadcastToOtherPlayers(std::string &messageOutput);
	std::string getInput();
	void clearScreen();
	void sendGameOverMessage();
	void outputStats();
	void outputHand();
	void outputPlayerStatus();
	void playTurn();
	void turnStart();
	void playActions();
	void useBuys();
	void turnEnd();
	void discardHand();
	void discardCleanupPileAndObtainedPile();
	void swapDeckAndDiscardPile();
	bool drawCard();							// Goes to hand. Returns true if player could not draw a card
	bool drawCard(OrderedDeck &deck);			// Choose where to go. Returns true if player could not draw a card
	void drawNewHand();
	bool plusCards(int numberOfCards);			// Returns true if player could not draw all the cards
	void plusActions(int numberOfActions);
	void plusBuys(int numberOfBuys);
	void plusCoins(int numberOfCoins);
	void fixCointainerDeckPointersOfCards();	// This needs to be called after doing a 
	bool preAttack();							// Returns true if player is immune to attack

	bool moatReact();							// Returns true if player gets to be immune to attacks
};
