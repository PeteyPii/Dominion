#pragma once

#include <vector>

class Card;
class Player;

class EstateCard
{
public:
	EstateCard();
	~EstateCard();

	static int getPrice(Card *card, Player *owner, std::vector<Player*> *otherPlayers);
	static int getVPValue(Player *owner);
};

