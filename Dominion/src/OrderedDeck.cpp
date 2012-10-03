#include "OrderedDeck.h"

#include "Cards.h"
#include "Player.h"
#include "RandomNumber.h"

using namespace std;

OrderedDeck::OrderedDeck()
{
	cards = deque<Card>();
	endOfDeckCallback = 0;
}
OrderedDeck::OrderedDeck(const OrderedDeck& orderedDeck)
{
	endOfDeckCallback = orderedDeck.endOfDeckCallback;
	cards = orderedDeck.cards;

	fixContainerDeckPointers();
}
OrderedDeck::~OrderedDeck()
{

}
OrderedDeck& OrderedDeck::operator=(const OrderedDeck& orderedDeck)
{
	if(this == &orderedDeck)
		return *this;

	endOfDeckCallback = orderedDeck.endOfDeckCallback;
	cards = orderedDeck.cards;

	fixContainerDeckPointers();

	return *this;
}
void OrderedDeck::addCard(Card &card)
{
	cards.push_back(Card(card.cardID, cards.size(), this));
}
void OrderedDeck::removeCard(Card &card)
{
	if(card.containerDeck != this)
	{
		throw std::exception("Tried to remove bad card.");
	}
	else
	{
		unsigned int tempIndex = card.deckIndex;

		card.containerDeck = 0;
		cards.erase(cards.begin() + tempIndex);
		
		for(unsigned int ii = tempIndex; ii < cards.size(); ii++)
		{
			cards[ii].deckIndex = ii;
		}

		if(isEmpty())
		{
			if(endOfDeckCallback != 0)
				endOfDeckCallback();
		}
	}
}
void OrderedDeck::shuffle()
{
	int iterations = cards.size() * cards.size();

	for(int ii = 0; ii < iterations; ii++)
	{
		unsigned int x = RandomNumber::random() % cards.size();
		unsigned int y = RandomNumber::random() % cards.size();

		if(x != y)
		{
			cards[x].sameDeckSwap(cards[y]);
		}
	}

	fixDeckIndexesOfCards();
}
void OrderedDeck::sortByName()
{
	for(unsigned int ii = 0; ii < cards.size() - 1; ii++)
	{
		for(unsigned int jj = 0; jj < cards.size() - 1 - ii; jj++)
		{
			if(cards[jj].name().compare(cards[jj + 1].name()) > 0)
			{
				cards[jj].sameDeckSwap(cards[jj + 1]);
			}
		}
	}

	fixDeckIndexesOfCards();
}
void OrderedDeck::sortByCostThenName()
{
	for(unsigned int ii = 0; ii < cards.size() - 1; ii++)
	{
		for(unsigned int jj = 0; jj < cards.size() - 1 - ii; jj++)
		{
			if(cards[jj].price() > cards[jj + 1].price())
			{
				cards[jj].sameDeckSwap(cards[jj + 1]);
			}
			else if(cards[jj].price() == cards[jj + 1].price())
			{
				if(cards[jj].name().compare(cards[jj + 1].name()) > 0)
				{
					cards[jj].sameDeckSwap(cards[jj + 1]);
				}
			}
		}
	}

	fixDeckIndexesOfCards();
}
bool OrderedDeck::drawCard(OrderedDeck &deck)
{
	if(cards.size() > 0)
	{
		Card card = cards[cards.size() - 1];
		cards.pop_back();
		deck.addCard(card);

		if(isEmpty())
		{
			if(endOfDeckCallback != 0)
				endOfDeckCallback();
		}
	}
	else
	{
		return true;
	}

	return false;
}
void OrderedDeck::moveContentsToAnotherDeck(OrderedDeck &deck)
{
	for(unsigned int ii = 0; ii < cards.size(); ii++)
	{
		deck.addCard(cards[ii]);
	}

	cards.clear();

	if(endOfDeckCallback != 0)
		endOfDeckCallback();
}
vector<Card*> OrderedDeck::getListOfCardsMatchingType(Card::CardTypes cardType)
{
	vector<Card*> cardList;

	for(unsigned int ii = 0; ii < cards.size(); ii++)
	{
		if((cards[ii].cardType() & cardType) > 0)	// Card matches type from argument (uses OR)
		{
			cardList.push_back(&cards[ii]);
		}
	}

	return cardList;
}
std::vector<Card*> OrderedDeck::getListOfCardsMatchingID(Card::CardIDs cardID)
{
	vector<Card*> cardList;

	for(unsigned int ii = 0; ii < cards.size(); ii++)
	{
		if(cards[ii].cardID == cardID)	// Card matches id from argument
		{
			cardList.push_back(&cards[ii]);
		}
	}

	return cardList;
}
void OrderedDeck::fixDeckIndexesOfCards()
{
	for(unsigned int ii = 0; ii < cards.size(); ii++)
	{
		cards[ii].deckIndex = ii;
	}
}
void OrderedDeck::fixContainerDeckPointers()
{
	for(unsigned int ii = 0; ii < cards.size(); ii++)
	{
		cards[ii].containerDeck = this;
	}
}
bool OrderedDeck::isEmpty()
{
	if(cards.size() == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int OrderedDeck::victoryPointValueOfDeck(Player *owner)
{
	int returnNumber = 0;

	for(unsigned int ii = 0; ii < cards.size(); ii++)
	{
		returnNumber += cards[ii].getVPValue(owner);
	}

	return returnNumber;
}
