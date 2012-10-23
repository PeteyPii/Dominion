#pragma once

#include <vector>

class Card;
class Player;

class DefaultCard
{
public:
	DefaultCard();
	~DefaultCard();

	static int getPrice(Card *card, Player *owner, std::vector<Player*> *otherPlayers);
	static int getVPValue(Player *owner);
	static void playAction(Card *card, Player *owner, std::vector<Player*> &otherPlayers);
	static void playTreasure(Card *card, Player *owner, std::vector<Player*> &otherPlayers);
	static void playDuration(Card *card, Player *owner, std::vector<Player*> &otherPlayers);
	static void setUpCardOnBoard();
};
