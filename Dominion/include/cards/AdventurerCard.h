#pragma once

#include <vector>

class Card;
class Player;

class AdventurerCard
{
public:
	AdventurerCard();
	~AdventurerCard();

	static int getPrice(Card *card, Player *owner, std::vector<Player*> *otherPlayers);
	static void playAction(Card *card, Player *owner, std::vector<Player*> &otherPlayers);
};
