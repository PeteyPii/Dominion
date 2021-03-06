#pragma once

#include <vector>

class Card;
class Player;

class ChancellorCard
{
public:
	ChancellorCard();
	~ChancellorCard();

	static int getPrice(Card *card, Player *owner, std::vector<Player*> *otherPlayers);
	static void playAction(Card *card, Player *owner, std::vector<Player*> &otherPlayers);
};

