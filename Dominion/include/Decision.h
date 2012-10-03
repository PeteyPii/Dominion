#pragma once

#include "Player.h"
#include <string>
#include <vector>

class Decision
{
public:
	std::string promptQuestion;		// Message to be shown before options.
	Player *player;					// Who's decision?
	std::vector<std::string> choices;
	
	Decision();
	Decision(std::string question, Player *player);
	Decision(const char *question, Player *player);
	~Decision();

	void addOption(std::string optionString);
	void addOption(const char* optionString);
	unsigned int makeDecision(bool allowSkip);
};
