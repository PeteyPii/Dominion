#pragma once

#include <vector>

class Card;
class Player;

class SilverCard
{
public:
	SilverCard();
	~SilverCard();

	static int getPrice(Card *card, Player *owner, std::vector<Player*> *otherPlayers);
	static void playTreasure(Card *card, Player *owner, std::vector<Player*> &otherPlayers);
};
