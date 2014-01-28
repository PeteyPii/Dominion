#pragma once

#include "Card.h"
#include <string>
#include <vector>

class Player;

class CardDefinition
{
public:
	static CardDefinition baseCardDefinition(const char *name, Card::CardTypes cardType, const char *description, int (*getPrice)(Card*, Player*, std::vector<Player*>*), int (*getVPValue)(Player*), void (*playAction)(Card*, Player*, std::vector<Player*>&), void (*playTreasure)(Card*, Player*, std::vector<Player*>&));

	std::string name;
	Card::CardTypes cardType;
	std::string description;

	int (*getPrice)(Card*, Player*, std::vector<Player*>*);	// Can use NULL for Player pointers for default price
	int (*getVPValue)(Player*);
	void (*playAction)(Card*, Player*, std::vector<Player*>&);
	void (*playTreasure)(Card*, Player*, std::vector<Player*>&);
	void (*playDuration)(Card*, Player*, std::vector<Player*>&);
	void (*setupCardOnBoard)();

	CardDefinition(const char *name, Card::CardTypes cardType, const char *description, int (*getPrice)(Card*, Player*, std::vector<Player*>*), int (*getVPValue)(Player*), void (*playAction)(Card*, Player*, std::vector<Player*>&), void (*playTreasure)(Card*, Player*, std::vector<Player*>&), void (*playDuration)(Card*, Player*, std::vector<Player*>&), void (*setupCardOnBoard)());
	~CardDefinition();

private:
	CardDefinition();
};
