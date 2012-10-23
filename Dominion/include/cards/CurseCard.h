#pragma once

#include <vector>

class Card;
class Player;

class CurseCard
{
public:
	CurseCard();
	~CurseCard();

	static int getPrice(Card *card, Player *owner, std::vector<Player*> *otherPlayers);
	static int getVPValue(Player *owner);
};

