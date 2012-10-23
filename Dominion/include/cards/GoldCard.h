#pragma once

#include <vector>

class Card;
class Player;

class GoldCard
{
public:
	GoldCard();
	~GoldCard();

	static int getPrice(Card *card, Player *owner, std::vector<Player*> *otherPlayers);
	static void playTreasure(Card *card, Player *owner, std::vector<Player*> &otherPlayers);
};

