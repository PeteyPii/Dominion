#pragma once

#include "CardDefinition.h"
#include "OrderedDeck.h"

class Cards
{
public:
	static CardDefinition cardDefinitions[];
	
	static OrderedDeck allKingdomCards();
	static OrderedDeck allTreasureCards();
	static OrderedDeck allVictoryPointCards();
	static OrderedDeck allCurseCards();
	
	Cards() {}
	~Cards() {}
};
