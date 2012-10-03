#include "Decision.h"

using namespace std;

Decision::Decision() 
	: player(0)
{
	promptQuestion = "";
	choices = vector<string>();
}
Decision::Decision(string question, Player* player) 
	: player(player)
{
	promptQuestion = question;
}
Decision::Decision(const char* question, Player* player) 
	: player(player)
{
	promptQuestion = string(question);
}
Decision::~Decision()
{

}
void Decision::addOption(string optionString)
{
	choices.push_back(optionString);
}
void Decision::addOption(const char* optionString)
{
	choices.push_back(string(optionString));
}
unsigned int Decision::makeDecision(bool allowSkip)
{
	while(true)
	{
		stringstream output;
		output << promptQuestion << endl;

		for(unsigned int ii = 0; ii < choices.size(); ii++)
		{
			output << "\t[" << ii << "] " << choices[ii] << endl;
		}

		player->displayMessage(output.str(), true);

		string input = player->getInput();

		if(input.compare("") == 0 && allowSkip)		// Empty input
			return -1;	// Return -1 for skipping the decision

		int selection = -1;

		stringstream converter;
		converter << input;

		if(!(converter >> selection) || selection < 0 || selection >= (int)choices.size())	// Invalid input
		{
			stringstream secondaryOutput;
			secondaryOutput << "Please enter a valid number." << endl;
			player->displayMessage(secondaryOutput.str(), false);

			player->getInput();	// Press enter to continue
		}
		else
		{
			return selection;
		}
	}
}
