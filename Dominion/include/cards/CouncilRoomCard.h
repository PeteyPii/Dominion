#pragma once

#include <sstream>
#include <string>
#include <vector>

class Card;
class Player;

class CouncilRoomCard
{
public:
	CouncilRoomCard();
	~CouncilRoomCard();

	static int getCoinValue(Player *owner);
	static int getVPValue(Player *owner);
	static void playAction(Card *card, Player *owner, std::vector<Player*> &otherPlayers);
	static void playTreasure(Card *card, Player *owner, std::vector<Player*> &otherPlayers);
	static void playDuration(Card *card, Player *owner, std::vector<Player*> &otherPlayers);
	static void setUpCardOnBoard();
};

