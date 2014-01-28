#include "InstructionsState.h"

#include "CommonFunctions.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

InstructionsState::InstructionsState(void)
{

}
InstructionsState::~InstructionsState(void)
{

}
void InstructionsState::runState()
{
	CommonFunctions::clearScreen();

	cout << "|--- Instructions ---|" << endl;
	cout << "Press ENTER to keep scrolling." << endl;

	ifstream instructionsFile("resources/data/instructions.txt");

	if(!instructionsFile.is_open())
	{
		throw exception("Could not find the instructions file");
	}

	while(instructionsFile)
	{
		string buffer;
		getline(cin, buffer);	// Press ENTER to continue

		string line;
		getline(instructionsFile, line);
		cout << line;
	}

	instructionsFile.close();

	cout << "\nPress ENTER to return to the main menu.";

	string buffer;
	getline(cin, buffer);	// Press ENTER to continue
}
