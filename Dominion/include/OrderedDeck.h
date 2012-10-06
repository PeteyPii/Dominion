#pragma once

#include "Card.h"
#include <deque>

class Player;

class OrderedDeck
{
public:
	std::deque<Card> cards;
	void (*endOfDeckCallback)();

	OrderedDeck();
	OrderedDeck(const OrderedDeck& orderedDeck);
	~OrderedDeck();

	OrderedDeck& operator=(const OrderedDeck& orderedDeck);

	void addCard(Card &card);
	void removeCard(Card &card);
	void shuffle();
	void sortByName();
	void sortByCostThenName();
	bool drawCard(OrderedDeck &deck);	// Returns true if deck is empty
	void moveContentsToAnotherDeck(OrderedDeck &deck);
	std::vector<Card*> getListOfCardsMatchingType(Card::CardTypes cardType);
	std::vector<Card*> getListOfCardsMatchingID(Card::CardIDs cardID);
	void fixDeckIndexesOfCards();
	void fixContainerDeckPointers();
	bool isEmpty();
	int victoryPointValueOfDeck(Player *owner);
};
