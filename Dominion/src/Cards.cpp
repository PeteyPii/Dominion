#include "Cards.h"

#include "AllCardTypes.h"
#include "Card.h"

using namespace std;

CardDefinition Cards::def("", Card::NULL_TYPE, "", DefaultCard::getPrice, DefaultCard::getVPValue, DefaultCard::playAction, DefaultCard::playTreasure, DefaultCard::playDuration, DefaultCard::setUpCardOnBoard);

CardDefinition Cards::cardDefinitions[] =
{
	CardDefinition::baseCardDefinition("ADVENTURER", Card::ACTION_TYPE, 
				   "| Reveal cards from your deck until you reveal 2 TREASURE cards. | Put those TREASURE cards in your hand and discard the other revealed cards. |",
				   AdventurerCard::getPrice, def.getVPValue, AdventurerCard::playAction, def.playTreasure),
	CardDefinition::baseCardDefinition("BUREAUCRAT", Card::ACTION_ATTACK_TYPE, 
				   "| Gain a silver card and put it on top of your deck. | Each other player reveals a VICTORY card from his hand and puts it on top of his deck (or reveals a hand with no VICTORY cards). |", 
				   BureaucratCard::getPrice, def.getVPValue, BureaucratCard::playAction, def.playTreasure),
	CardDefinition::baseCardDefinition("CELLAR", Card::ACTION_TYPE,
				   "| +1 ACTION. | Discard any number of cards. | +1 CARD per card discarded. |", 
				   CellarCard::getPrice, def.getVPValue, CellarCard::playAction, def.playTreasure),
	CardDefinition::baseCardDefinition("CHANCELLOR", Card::ACTION_TYPE,
				   "| +2 COINS | You may immediately put your deck into your discard pile. |", 
				   ChancellorCard::getPrice, def.getVPValue, ChancellorCard::playAction, def.playTreasure),
	CardDefinition::baseCardDefinition("CHAPEL", Card::ACTION_TYPE,
				   "| Trash up to four cards from your hand. |", 
				   ChapelCard::getPrice, def.getVPValue, ChapelCard::playAction, def.playTreasure),
	CardDefinition::baseCardDefinition("COPPER", Card::TREASURE_TYPE,
				   "| <1 COIN> |", 
				   CopperCard::getPrice, def.getVPValue, def.playAction, CopperCard::playTreasure),
	CardDefinition::baseCardDefinition("COUNCIL ROOM", Card::ACTION_TYPE,
				   "| +4 CARDS | +1 BUY | Each other player discards a card. |", 
				   CouncilRoomCard::getPrice, def.getVPValue, CouncilRoomCard::playAction, def.playTreasure),
	CardDefinition::baseCardDefinition("CURSE", Card::CURSE_TYPE,
				   "| <-1 VICTORY POINT> |", 
				   CurseCard::getPrice, CurseCard::getVPValue, def.playAction, def.playTreasure),
	CardDefinition::baseCardDefinition("DUCHY", Card::VICTORY_TYPE,
				   "| <3 VICTORY POINTS> |", 
				   DuchyCard::getPrice, DuchyCard::getVPValue, def.playAction, def.playTreasure),
	CardDefinition::baseCardDefinition("ESTATE", Card::VICTORY_TYPE,
				   "| <1 VICTORY POINT> |", 
				   EstateCard::getPrice, EstateCard::getVPValue, def.playAction, def.playTreasure),
	CardDefinition::baseCardDefinition("FEAST", Card::ACTION_TYPE,
				   "| Trash this card. | Gain a card costing up to 5 COINS. |", 
				   FeastCard::getPrice, def.getVPValue, FeastCard::playAction, def.playTreasure),
	CardDefinition::baseCardDefinition("FESTIVAL", Card::ACTION_TYPE,
				   "| +2 ACTIONS | +1 BUY | +2 COINS |", 
				   FestivalCard::getPrice, def.getVPValue, FestivalCard::playAction, def.playTreasure),
	CardDefinition::baseCardDefinition("GARDENS", Card::VICTORY_TYPE,
				   "| Worth 1 VICTORY POINT for every 10 cards in your deck (rounded down). |", 
				   GardensCard::getPrice, GardensCard::getVPValue, def.playAction, def.playTreasure),
	CardDefinition::baseCardDefinition("GOLD", Card::TREASURE_TYPE,
				   "| <3 COINS> |", 
				   GoldCard::getPrice, def.getVPValue, def.playAction, GoldCard::playTreasure),
	CardDefinition::baseCardDefinition("LABORATORY", Card::ACTION_TYPE, 
				   "| +2 CARDS | +1 ACTION |", 
				   LaboratoryCard::getPrice, def.getVPValue, LaboratoryCard::playAction, def.playTreasure),
	CardDefinition::baseCardDefinition("LIBRARY", Card::ACTION_TYPE,
				   "| Draw until you have 7 cards in your hand. You may set aside any ACTION cards drawn this way, as you draw them. | Discard the set aside cards after you finish drawing. |", 
				   LibraryCard::getPrice, def.getVPValue, LibraryCard::playAction, def.playTreasure),
	CardDefinition::baseCardDefinition("MARKET", Card::ACTION_TYPE,
				   "| +1 CARD | +1 ACTION | +1 BUY | +1 COIN |", 
				   MarketCard::getPrice, def.getVPValue, MarketCard::playAction, def.playTreasure),
	CardDefinition::baseCardDefinition("MILITIA", Card::ACTION_ATTACK_TYPE,
				   "| +2 COINS | Each other player discards down to 3 cards. |", 
				   MilitiaCard::getPrice, def.getVPValue, MilitiaCard::playAction, def.playTreasure),
	CardDefinition::baseCardDefinition("MINE", Card::ACTION_TYPE,
				   "| Trash a TREASURE card from your hand. | Gain a TREASURE card costing up to 3 COINS more. Put it in your hand. |", 
				   MineCard::getPrice, def.getVPValue, MineCard::playAction, def.playTreasure),
	CardDefinition::baseCardDefinition("MOAT", Card::ACTION_REACTION_TYPE,
				   "| +2 CARDS | When another player plays an ATTACK card, you may reveal this and be unaffected by that ATTACK. |", 
				   MoatCard::getPrice, def.getVPValue, MoatCard::playAction, def.playTreasure),
	CardDefinition::baseCardDefinition("MONEYLENDER", Card::ACTION_TYPE,
				   "| Trash a copper from your hand. | If you do, +3 COINS |", 
				   MoneylenderCard::getPrice, def.getVPValue, MoneylenderCard::playAction, def.playTreasure),
	CardDefinition::baseCardDefinition("PROVINCE", Card::VICTORY_TYPE,
				   "| <6 VICTORY POINTS |", 
				   ProvinceCard::getPrice, ProvinceCard::getVPValue, def.playAction, def.playTreasure),
	CardDefinition::baseCardDefinition("REMODEL", Card::ACTION_TYPE,
				   "| Trash a card from your hand.| Gain a card costing up to 2 COINS more than the trashed card. |", 
				   RemodelCard::getPrice, def.getVPValue, RemodelCard::playAction, def.playTreasure),
	CardDefinition::baseCardDefinition("SILVER", Card::TREASURE_TYPE,
				   "| <2 COINS> |", 
				   SilverCard::getPrice, def.getVPValue, def.playAction, SilverCard::playTreasure),
	CardDefinition::baseCardDefinition("SMITHY", Card::ACTION_TYPE,
				   "| +3 CARDS |", 
				   SmithyCard::getPrice, def.getVPValue, SmithyCard::playAction, def.playTreasure),
	CardDefinition::baseCardDefinition("SPY", Card::ACTION_ATTACK_TYPE,
				   "| +1 CARD | +1 ACTION | Each player (including you) reveals the top card of his deck and either discards it or puts it back, your choice. |", 
				   SpyCard::getPrice, def.getVPValue, SpyCard::playAction, def.playTreasure),
	CardDefinition::baseCardDefinition("THIEF", Card::ACTION_TYPE,
				   "| Each other player reveals the top 2 cards of their deck. | If they revealed any TREASURE cards, they trash one of them that you choose. | You may gain any or all of these trashed cards. | They discard all other revealed cards. |", 
				   ThiefCard::getPrice, def.getVPValue, ThiefCard::playAction, def.playTreasure),
	CardDefinition::baseCardDefinition("THRONE ROOM", Card::ACTION_TYPE,
				   "| +1 BUY | +2 COINS |", 
				   ThroneRoomCard::getPrice, def.getVPValue, ThroneRoomCard::playAction, def.playTreasure),
	CardDefinition::baseCardDefinition("VILLAGE", Card::ACTION_TYPE,
				   "| +1 CARD | +2 ACTIONS |", 
				   VillageCard::getPrice, def.getVPValue, VillageCard::playAction, def.playTreasure),
	CardDefinition::baseCardDefinition("WITCH", Card::ACTION_ATTACK_TYPE,
				   "| +2 CARDS | Each other player gains a curse card. |", 
				   WitchCard::getPrice, def.getVPValue, WitchCard::playAction, def.playTreasure),
	CardDefinition::baseCardDefinition("WOODCUTTER", Card::ACTION_TYPE,
				   "| +1 BUY | +2 COINS |", 
				   WoodcutterCard::getPrice, def.getVPValue, WoodcutterCard::playAction, def.playTreasure),
	CardDefinition::baseCardDefinition("WORKSHOP", Card::ACTION_TYPE,
				   "| Gain a card costing up to 4 COINS. |", 
				   WorkshopCard::getPrice, def.getVPValue, WorkshopCard::playAction, def.playTreasure)
};

OrderedDeck Cards::allKingdomCards()
{
	OrderedDeck returnDeck;

	returnDeck.addCard(Card(Card::ADVENTURER_CARD, 0, 0));
	returnDeck.addCard(Card(Card::BUREAUCRAT_CARD, 0, 0));
	returnDeck.addCard(Card(Card::CELLAR_CARD, 0, 0));
	returnDeck.addCard(Card(Card::CHANCELLOR_CARD, 0, 0));
	returnDeck.addCard(Card(Card::CHAPEL_CARD, 0, 0));
	returnDeck.addCard(Card(Card::COUNCIL_ROOM_CARD, 0, 0));
	returnDeck.addCard(Card(Card::FEAST_CARD, 0, 0));
	returnDeck.addCard(Card(Card::FESTIVAL_CARD, 0, 0));
	returnDeck.addCard(Card(Card::GARDENS_CARD, 0, 0));
	returnDeck.addCard(Card(Card::LABORATORY_CARD, 0, 0));
	returnDeck.addCard(Card(Card::LIBRARY_CARD, 0, 0));
	returnDeck.addCard(Card(Card::MARKET_CARD, 0, 0));
	returnDeck.addCard(Card(Card::MILITIA_CARD, 0, 0));
	returnDeck.addCard(Card(Card::MINE_CARD, 0, 0));
	returnDeck.addCard(Card(Card::MOAT_CARD, 0, 0));
	returnDeck.addCard(Card(Card::MONEYLENDER_CARD, 0, 0));
	returnDeck.addCard(Card(Card::REMODEL_CARD, 0, 0));
	returnDeck.addCard(Card(Card::SMITHY_CARD, 0, 0));
	returnDeck.addCard(Card(Card::SPY_CARD, 0, 0));
	returnDeck.addCard(Card(Card::THIEF_CARD, 0, 0));
	returnDeck.addCard(Card(Card::THRONE_ROOM_CARD, 0, 0));
	returnDeck.addCard(Card(Card::VILLAGE_CARD, 0, 0));
	returnDeck.addCard(Card(Card::WITCH_CARD, 0, 0));
	returnDeck.addCard(Card(Card::WOODCUTTER_CARD, 0, 0));
	returnDeck.addCard(Card(Card::WORKSHOP_CARD, 0, 0));

	return returnDeck;
}
OrderedDeck Cards::allTreasureCards()
{
	OrderedDeck returnDeck;

	returnDeck.addCard(Card(Card::COPPER_CARD, 0, 0));
	returnDeck.addCard(Card(Card::GOLD_CARD, 0, 0));
	returnDeck.addCard(Card(Card::SILVER_CARD, 0, 0));

	return returnDeck;
}
OrderedDeck Cards::allVictoryPointCards()
{
	OrderedDeck returnDeck;

	returnDeck.addCard(Card(Card::DUCHY_CARD, 0, 0));
	returnDeck.addCard(Card(Card::ESTATE_CARD, 0, 0));
	returnDeck.addCard(Card(Card::PROVINCE_CARD, 0, 0));

	return returnDeck;
}
OrderedDeck Cards::allCurseCards()
{
	OrderedDeck returnDeck;

	returnDeck.addCard(Card(Card::CURSE_CARD, 0, 0));

	return returnDeck;
}
