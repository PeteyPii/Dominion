#pragma once

#include <string>
#include <vector>

class Decision
{
public:
	std::string promptQuestion;		// Message to be shown before options.
	std::vector<std::string> choices;

	Decision();
	Decision(std::string question);
	Decision(const char *question);
	~Decision();

	void addOption(std::string optionString);
	void addOption(const char* optionString);
	unsigned int makeDecision(bool allowSkip);
};
