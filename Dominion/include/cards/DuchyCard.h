#pragma once

#include <vector>

class Card;
class Player;

class DuchyCard
{
public:
	DuchyCard();
	~DuchyCard();

	static int getPrice(Card *card, Player *owner, std::vector<Player*> *otherPlayers);
	static int getVPValue(Player *owner);
};

