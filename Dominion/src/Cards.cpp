#include "Cards.h"

#include "AllCardTypes.h"
#include "Card.h"

CardDefinition Cards::cardDefinitions[] =
{
	CardDefinition("ADVENTURER", Card::ACTION_TYPE, 6, 
				   "| Reveal cards from your deck until you reveal 2 TREASURE cards. | Put those TREASURE cards in your hand and discard the other revealed cards. |",
				   AdventurerCard::getCoinValue, AdventurerCard::getVPValue, AdventurerCard::playAction, AdventurerCard::playTreasure,
				   AdventurerCard::playDuration, AdventurerCard::setUpCardOnBoard),
	CardDefinition("BUREAUCRAT", Card::ACTION_ATTACK_TYPE, 4, 
				   "| Gain a silver card and put it on top of your deck. | Each other player reveals a VICTORY card from his hand and puts it on top of his deck (or reveals a hand with no VICTORY cards). |", 
				   BureaucratCard::getCoinValue, BureaucratCard::getVPValue, BureaucratCard::playAction, BureaucratCard::playTreasure,
				   BureaucratCard::playDuration, BureaucratCard::setUpCardOnBoard),
	CardDefinition("CELLAR", Card::ACTION_TYPE, 2, 
				   "| +1 ACTION. | Discard any number of cards. | +1 CARD per card discarded. |", 
				   CellarCard::getCoinValue, CellarCard::getVPValue, CellarCard::playAction, CellarCard::playTreasure,
				   CellarCard::playDuration, CellarCard::setUpCardOnBoard),
	CardDefinition("CHANCELLOR", Card::ACTION_TYPE, 3, 
				   "| +2 COINS | You may immediately put your deck into your discard pile. |", 
				   ChancellorCard::getCoinValue, ChancellorCard::getVPValue, ChancellorCard::playAction, ChancellorCard::playTreasure,
				   ChancellorCard::playDuration, ChancellorCard::setUpCardOnBoard),
	CardDefinition("CHAPEL", Card::ACTION_TYPE, 2, 
				   "| Trash up to four cards from your hand. |", 
				   ChapelCard::getCoinValue, ChapelCard::getVPValue, ChapelCard::playAction, ChapelCard::playTreasure,
				   ChapelCard::playDuration, ChapelCard::setUpCardOnBoard),
	CardDefinition("COPPER", Card::TREASURE_TYPE, 0, 
				   "| <1 COIN> |", 
				   CopperCard::getCoinValue, CopperCard::getVPValue, CopperCard::playAction, CopperCard::playTreasure,
 				   CopperCard::playDuration, CopperCard::setUpCardOnBoard),
	CardDefinition("COUNCIL ROOM", Card::ACTION_TYPE, 5, 
				   "| +4 CARDS | +1 BUY | Each other player discards a card. |", 
				   CouncilRoomCard::getCoinValue, CouncilRoomCard::getVPValue, CouncilRoomCard::playAction, CouncilRoomCard::playTreasure,
				   CouncilRoomCard::playDuration, CouncilRoomCard::setUpCardOnBoard),
	CardDefinition("CURSE", Card::CURSE_TYPE, 0, 
				   "| <-1 VICTORY POINT> |", 
				   CurseCard::getCoinValue, CurseCard::getVPValue, CurseCard::playAction, CurseCard::playTreasure,
				   CurseCard::playDuration, CurseCard::setUpCardOnBoard),
	CardDefinition("DUCHY", Card::VICTORY_TYPE, 5, 
				   "| <3 VICTORY POINTS> |", 
				   DuchyCard::getCoinValue, DuchyCard::getVPValue, DuchyCard::playAction, DuchyCard::playTreasure,
				   DuchyCard::playDuration, DuchyCard::setUpCardOnBoard),
	CardDefinition("ESTATE", Card::VICTORY_TYPE, 2, 
				   "| <1 VICTORY POINT> |", 
				   EstateCard::getCoinValue, EstateCard::getVPValue, EstateCard::playAction, EstateCard::playTreasure,
				   EstateCard::playDuration, EstateCard::setUpCardOnBoard),
	CardDefinition("FEAST", Card::ACTION_TYPE, 4, 
				   "| Trash this card. | Gain a card costing up to 5 COINS. |", 
				   FeastCard::getCoinValue, FeastCard::getVPValue, FeastCard::playAction, FeastCard::playTreasure,
				   FeastCard::playDuration, FeastCard::setUpCardOnBoard),
	CardDefinition("FESTIVAL", Card::ACTION_TYPE, 5, 
				   "| +2 ACTIONS | +1 BUY | +2 COINS |", 
				   FestivalCard::getCoinValue, FestivalCard::getVPValue, FestivalCard::playAction, FestivalCard::playTreasure,
				   FestivalCard::playDuration, FestivalCard::setUpCardOnBoard),
	CardDefinition("GARDENS", Card::VICTORY_TYPE, 4, 
				   "| Worth 1 VICTORY POINT for every 10 cards in your deck (rounded down). |", 
				   GardensCard::getCoinValue, GardensCard::getVPValue, GardensCard::playAction, GardensCard::playTreasure,
				   GardensCard::playDuration, GardensCard::setUpCardOnBoard),
	CardDefinition("GOLD", Card::TREASURE_TYPE, 6, 
				   "| <3 COINS> |", 
				   GoldCard::getCoinValue, GoldCard::getVPValue, GoldCard::playAction, GoldCard::playTreasure,
				   GoldCard::playDuration, GoldCard::setUpCardOnBoard),
	CardDefinition("LABORATORY", Card::ACTION_TYPE, 5, 
				   "| +2 CARDS | +1 ACTION |", 
				   LaboratoryCard::getCoinValue, LaboratoryCard::getVPValue, LaboratoryCard::playAction, LaboratoryCard::playTreasure,
				   LaboratoryCard::playDuration, LaboratoryCard::setUpCardOnBoard),
	CardDefinition("LIBRARY", Card::ACTION_TYPE, 5, 
				   "| Draw until you have 7 cards in your hand. You may set aside any ACTION cards drawn this way, as you draw them. | Discard the set aside cards after you finish drawing. |", 
				   LibraryCard::getCoinValue, LibraryCard::getVPValue, LibraryCard::playAction, LibraryCard::playTreasure,
				   LibraryCard::playDuration, LibraryCard::setUpCardOnBoard),
	CardDefinition("MARKET", Card::ACTION_TYPE, 5, 
				   "| +1 CARD | +1 ACTION | +1 BUY | +1 COIN |", 
				   MarketCard::getCoinValue, MarketCard::getVPValue, MarketCard::playAction, MarketCard::playTreasure,
				   MarketCard::playDuration, MarketCard::setUpCardOnBoard),
	CardDefinition("MILITIA", Card::ACTION_ATTACK_TYPE, 4, 
				   "| +2 COINS | Each other player discards down to 3 cards. |", 
				   MilitiaCard::getCoinValue, MilitiaCard::getVPValue, MilitiaCard::playAction, MilitiaCard::playTreasure,
				   MilitiaCard::playDuration, MilitiaCard::setUpCardOnBoard),
	CardDefinition("MINE", Card::ACTION_TYPE, 5, 
				   "| Trash a TREASURE card from your hand. | Gain a TREASURE card costing up to 3 COINS more. Put it in your hand. |", 
				   MineCard::getCoinValue, MineCard::getVPValue, MineCard::playAction, MineCard::playTreasure,
				   MineCard::playDuration, MineCard::setUpCardOnBoard),
	CardDefinition("MOAT", Card::ACTION_REACTION_TYPE, 2, 
				   "| +2 CARDS | When another player plays an ATTACK card, you may reveal this and be unaffected by that ATTACK. |", 
				   MoatCard::getCoinValue, MoatCard::getVPValue, MoatCard::playAction, MoatCard::playTreasure,
				   MoatCard::playDuration, MoatCard::setUpCardOnBoard),
	CardDefinition("MONEYLENDER", Card::ACTION_TYPE, 3, 
				   "| Trash a copper from your hand. | If you do, +3 COINS |", 
				   MoneylenderCard::getCoinValue, MoneylenderCard::getVPValue, MoneylenderCard::playAction, MoneylenderCard::playTreasure,
				   MoneylenderCard::playDuration, MoneylenderCard::setUpCardOnBoard),
	CardDefinition("PROVINCE", Card::VICTORY_TYPE, 8, 
				   "| <6 VICTORY POINTS |", 
				   ProvinceCard::getCoinValue, ProvinceCard::getVPValue, ProvinceCard::playAction, ProvinceCard::playTreasure,
				   ProvinceCard::playDuration, ProvinceCard::setUpCardOnBoard),
	CardDefinition("REMODEL", Card::ACTION_TYPE, 4, 
				   "| Trash a card from your hand.| Gain a card costing up to 2 COINS more than the trashed card. |", 
				   RemodelCard::getCoinValue, RemodelCard::getVPValue, RemodelCard::playAction, RemodelCard::playTreasure,
				   RemodelCard::playDuration, RemodelCard::setUpCardOnBoard),
	CardDefinition("SILVER", Card::TREASURE_TYPE, 3, 
				   "| <2 COINS> |", 
				   SilverCard::getCoinValue, SilverCard::getVPValue, SilverCard::playAction, SilverCard::playTreasure,
				   SilverCard::playDuration, SilverCard::setUpCardOnBoard),
	CardDefinition("SMITHY", Card::ACTION_TYPE, 3, 
				   "| +3 CARDS |", 
				   SmithyCard::getCoinValue, SmithyCard::getVPValue, SmithyCard::playAction, SmithyCard::playTreasure,
				   SmithyCard::playDuration, SmithyCard::setUpCardOnBoard),
	CardDefinition("SPY", Card::ACTION_ATTACK_TYPE, 4, 
				   "| +1 CARD | +1 ACTION | Each player (including you) reveals the top card of his deck and either discards it or puts it back, your choice. |", 
				   SpyCard::getCoinValue, SpyCard::getVPValue, SpyCard::playAction, SpyCard::playTreasure,
				   SpyCard::playDuration, SpyCard::setUpCardOnBoard),
	CardDefinition("THIEF", Card::ACTION_TYPE, 4, 
				   "| Each other player reveals the top 2 cards of their deck. | If they revealed any TREASURE cards, they trash one of them that you choose. | You may gain any or all of these trashed cards. | They discard all other revealed cards. |", 
				   ThiefCard::getCoinValue, ThiefCard::getVPValue, ThiefCard::playAction, ThiefCard::playTreasure,
				   ThiefCard::playDuration, ThiefCard::setUpCardOnBoard),
	CardDefinition("THRONE ROOM", Card::ACTION_TYPE, 4, 
				   "| +1 BUY | +2 COINS |", 
				   ThroneRoomCard::getCoinValue, ThroneRoomCard::getVPValue, ThroneRoomCard::playAction, ThroneRoomCard::playTreasure,
				   ThroneRoomCard::playDuration, ThroneRoomCard::setUpCardOnBoard),
	CardDefinition("VILLAGE", Card::ACTION_TYPE, 3, 
				   "| +1 CARD | +2 ACTIONS |", 
				   VillageCard::getCoinValue, VillageCard::getVPValue, VillageCard::playAction, VillageCard::playTreasure,
				   VillageCard::playDuration, VillageCard::setUpCardOnBoard),
	CardDefinition("WITCH", Card::ACTION_ATTACK_TYPE, 5, 
				   "| +2 CARDS | Each other player gains a curse card. |", 
				   WitchCard::getCoinValue, WitchCard::getVPValue, WitchCard::playAction, WitchCard::playTreasure,
				   WitchCard::playDuration, WitchCard::setUpCardOnBoard),
	CardDefinition("WOODCUTTER", Card::ACTION_TYPE, 3, 
				   "| +1 BUY | +2 COINS |", 
				   WoodcutterCard::getCoinValue, WoodcutterCard::getVPValue, WoodcutterCard::playAction, WoodcutterCard::playTreasure,
				   WoodcutterCard::playDuration, WoodcutterCard::setUpCardOnBoard),
	CardDefinition("WORKSHOP", Card::ACTION_TYPE, 3, 
				   "| Gain a card costing up to 4 COINS. |", 
				   WorkshopCard::getCoinValue, WorkshopCard::getVPValue, WorkshopCard::playAction, WorkshopCard::playTreasure,
				   WorkshopCard::playDuration, WorkshopCard::setUpCardOnBoard)
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
