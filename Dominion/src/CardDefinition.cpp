#include "CardDefinition.h"

#include "Player.h"

using namespace std;

CardDefinition::CardDefinition()
{

}
CardDefinition::CardDefinition(const char *name, Card::CardTypes cardType, int price, const char *description, int (*getCoinValue)(Player*), int (*getVPValue)(Player*), void (*playAction)(Card*, Player*, std::vector<Player*>&), void (*playTreasure)(Card*, Player*, std::vector<Player*>&), void (*playDuration)(Card*, Player*, std::vector<Player*>&), void (*setupCardOnBoard)())
{
	this->name = name;
	this->cardType = cardType;
	this->price = price;
	this->description = description;

	this->getCoinValue = getCoinValue;
	this->getVPValue = getVPValue;
	this->playAction = playAction;
	this->playTreasure = playTreasure;
	this->playDuration = playDuration;
	this->setupCardOnBoard = setupCardOnBoard;
}
CardDefinition::~CardDefinition()
{

}
