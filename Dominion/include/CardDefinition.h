#pragma once

#include "Card.h"
#include <string>
#include <vector>

class Player;

class CardDefinition
{
public:
	std::string name;
	Card::CardTypes cardType;
	int price;
	std::string description;

	int (*getCoinValue)(Player*);
	int (*getVPValue)(Player*);
	void (*playAction)(Card*, Player*, std::vector<Player*>&);
	void (*playTreasure)(Card*, Player*, std::vector<Player*>&);
	void (*playDuration)(Card*, Player*, std::vector<Player*>&);
	void (*setupCardOnBoard)();

	CardDefinition(const char *name, Card::CardTypes cardType, int price, const char *description, int (*getCoinValue)(Player*), int (*getVPValue)(Player*), void (*playAction)(Card*, Player*, std::vector<Player*>&), void (*playTreasure)(Card*, Player*, std::vector<Player*>&), void (*playDuration)(Card*, Player*, std::vector<Player*>&), void (*setupCardOnBoard)());
	~CardDefinition();

private:
	CardDefinition();
};
