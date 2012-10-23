#pragma once

#include <vector>

class Card;
class Player;

class MarketCard
{
public:
	MarketCard();
	~MarketCard();

	static int getPrice(Card *card, Player *owner, std::vector<Player*> *otherPlayers);
	static void playAction(Card *card, Player *owner, std::vector<Player*> &otherPlayers);
};
