#include "CardDefinition.h"

#include "cards/DefaultCard.h"
#include "Player.h"

using namespace std;

CardDefinition CardDefinition::def("", Card::NULL_TYPE, "", DefaultCard::getPrice, DefaultCard::getVPValue, DefaultCard::playAction, DefaultCard::playTreasure, DefaultCard::playTreasure, DefaultCard::setUpCardOnBoard);

CardDefinition::CardDefinition()
{

}
CardDefinition CardDefinition::baseCardDefinition(const char *name, Card::CardTypes cardType, const char *description, int (*getPrice)(Card*, Player*, std::vector<Player*>*), int (*getVPValue)(Player*), void (*playAction)(Card*, Player*, std::vector<Player*>&), void (*playTreasure)(Card*, Player*, std::vector<Player*>&))
{
	return CardDefinition(name, cardType, description, getPrice, getVPValue, playAction, playTreasure, def.playDuration, def.setupCardOnBoard);
}
CardDefinition::CardDefinition(const char *name, Card::CardTypes cardType, const char *description, int (*getPrice)(Card*, Player*, std::vector<Player*>*), int (*getVPValue)(Player*), void (*playAction)(Card*, Player*, std::vector<Player*>&), void (*playTreasure)(Card*, Player*, std::vector<Player*>&), void (*playDuration)(Card*, Player*, std::vector<Player*>&), void (*setupCardOnBoard)())
{
	this->name = name;
	this->cardType = cardType;
	this->description = description;

	this->getPrice = getPrice;
	this->getVPValue = getVPValue;
	this->playAction = playAction;
	this->playTreasure = playTreasure;
	this->playDuration = playDuration;
	this->setupCardOnBoard = setupCardOnBoard;
}
CardDefinition::~CardDefinition()
{

}
