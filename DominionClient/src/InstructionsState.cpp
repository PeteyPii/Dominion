#include "InstructionsState.h"

#include "CommonFunctions.h"
#include <iostream>
#include <string>

using namespace std;

InstructionsState::InstructionsState()
{

}
InstructionsState::~InstructionsState()
{

}
void InstructionsState::runTextOnly()
{
	CommonFunctions::clearScreen();

	cout << "|--- Instructions ---|" << endl;
	cout << "To be completed..." << endl;

	string buffer;
	getline(cin, buffer);	// Press ENTER to continue
}
