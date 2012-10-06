#pragma once

#include <vector>

class OrderedDeck;
class Player;

class Card
{
public:
	enum CardTypes
	{
		NULL_TYPE = -1,
		TREASURE_TYPE = 0x01,
		VICTORY_TYPE = 0x02,
		ACTION_TYPE = 0x04,
		ATTACK_TYPE = 0x08,
		REACTION_TYPE = 0x16,
		CURSE_TYPE = 0x32,
		ACTION_ATTACK_TYPE = ACTION_TYPE | ATTACK_TYPE,
		ACTION_REACTION_TYPE = ACTION_TYPE | REACTION_TYPE
	};

	enum CardIDs
	{
		NULL_CARD = -1,
		ADVENTURER_CARD = 0,
		BUREAUCRAT_CARD,
		CELLAR_CARD,
		CHANCELLOR_CARD,
		CHAPEL_CARD,
		COPPER_CARD,
		COUNCIL_ROOM_CARD,
		CURSE_CARD,
		DUCHY_CARD,
		ESTATE_CARD,
		FEAST_CARD,
		FESTIVAL_CARD,
		GARDENS_CARD,
		GOLD_CARD,
		LABORATORY_CARD,
		LIBRARY_CARD,
		MARKET_CARD,
		MILITIA_CARD,
		MINE_CARD,
		MOAT_CARD,
		MONEYLENDER_CARD,
		PROVINCE_CARD,
		REMODEL_CARD,
		SILVER_CARD,
		SMITHY_CARD,
		SPY_CARD,
		THIEF_CARD,
		THRONE_ROOM_CARD,
		VILLAGE_CARD,
		WITCH_CARD,
		WOODCUTTER_CARD,
		WORKSHOP_CARD,
		NUMBER_OF_CARDS
	};

	CardIDs cardID;
	unsigned int deckIndex;
	OrderedDeck *containerDeck;
	
	Card();
	Card(CardIDs cardID, unsigned int deckIndex, OrderedDeck *containerDeck);
	~Card();

	std::string name();
	int price();
	CardTypes cardType();
	std::string description();

	int getCoinValue(Player *owner);
	int getVPValue(Player *owner);
	void playAction(Player *owner, std::vector<Player*> &otherPlayers);
	void playTreasure(Player *owner, std::vector<Player*> &otherPlayers);
	void playDuration(Player *owner, std::vector<Player*> &otherPlayers);
	void setupCardOnBoard();

	void printNameAndDescription(Player *player);
	void sameDeckSwap(Card &otherCard);
	void moveToAnotherDeck(OrderedDeck &deck);
};
