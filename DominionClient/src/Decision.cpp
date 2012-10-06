#include "Decision.h"

#include <iostream>
#include <sstream>

using namespace std;

Decision::Decision() 
{
	promptQuestion = "";
	choices = vector<string>();
}
Decision::Decision(string question) 
{
	promptQuestion = question;
}
Decision::Decision(const char* question) 
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
		cout << promptQuestion << endl;

		for(unsigned int ii = 0; ii < choices.size(); ii++)
		{
			cout << "\t[" << ii << "] " << choices[ii] << endl;
		}

		string input;
		getline(cin, input);

		if(input.compare("") == 0 && allowSkip)		// Empty input
			return -1;	// Return -1 for skipping the decision

		int selection = -1;

		stringstream converter;
		converter << input;

		if(!(converter >> selection) || selection < 0 || selection >= (int)choices.size())	// Invalid input
		{
			cout << "Please enter a valid number (press ENTER to continue)." << endl;

			getline(cin, input);	// Press enter to continue
		}
		else
		{
			return selection;
		}
	}
}
