#pragma once

#include <vector>

class Card;
class Player;

class GardensCard
{
public:
	GardensCard();
	~GardensCard();

	static int getPrice(Card *card, Player *owner, std::vector<Player*> *otherPlayers);
	static int getVPValue(Player *owner);
};

