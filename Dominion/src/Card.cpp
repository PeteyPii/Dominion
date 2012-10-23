#include "Card.h"

#include "CardDefinition.h"
#include "Cards.h"
#include "OrderedDeck.h"
#include "Player.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Card::Card()
{
	cardID = NULL_CARD;
	deckIndex = 0;
	containerDeck = 0;
}
Card::Card(CardIDs cardID, unsigned int deckIndex, OrderedDeck *containerDeck)
{
	this->cardID = cardID;
	this->deckIndex = deckIndex;
	this->containerDeck = containerDeck;
}
Card::~Card()
{

}
std::string Card::name()
{
	return Cards::cardDefinitions[cardID].name;
}
int Card::getPrice(Card *card, Player *owner, std::vector<Player*> &otherPlayers)
{
	return getPrice(card, owner, &otherPlayers);
}
int Card::getPrice(Card *card, Player *owner, std::vector<Player*> *otherPlayers)
{
	return Cards::cardDefinitions[cardID].getPrice(card, owner, otherPlayers);
}
Card::CardTypes Card::cardType()
{
	return Cards::cardDefinitions[cardID].cardType;
}
std::string Card::description()
{
	return Cards::cardDefinitions[cardID].description;
}
int Card::getVPValue(Player *owner)
{
	return Cards::cardDefinitions[cardID].getVPValue(owner);
}
void Card::playAction(Player *owner, vector<Player*> &otherPlayers)
{
	Cards::cardDefinitions[cardID].playAction(this, owner, otherPlayers);
}
void Card::playTreasure(Player *owner, std::vector<Player*> &otherPlayers)
{
	Cards::cardDefinitions[cardID].playTreasure(this, owner, otherPlayers);
}
void Card::playDuration(Player *owner, std::vector<Player*> &otherPlayers)
{
	Cards::cardDefinitions[cardID].playDuration(this, owner, otherPlayers);
}
void Card::setupCardOnBoard()
{
	Cards::cardDefinitions[cardID].setupCardOnBoard();
}
void Card::printNameAndDescription(Player *player)
{
	stringstream output;
	output << name() << " - " << description() << endl;
	player->displayMessage(output.str(), false);
}
void Card::sameDeckSwap(Card &otherCard)
{
	CardIDs tempID = otherCard.cardID;
	unsigned int tempIndex = otherCard.deckIndex;
	OrderedDeck *tempDeck = otherCard.containerDeck;

	otherCard.cardID = cardID;
	otherCard.deckIndex = deckIndex;
	otherCard.containerDeck = containerDeck;

	cardID = tempID;
	deckIndex = tempIndex;
	containerDeck = tempDeck;
}
void Card::moveToAnotherDeck(OrderedDeck &deck)
{
	Card tempCopy = *this;

	containerDeck->removeCard(*this);
	deck.addCard(tempCopy);
}
