#include "InstructionsState.h"

#include "CommonFunctions.h"
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
	CommonFunctions::ClearScreen();

	cout << "|--- Instructions ---|" << endl;
	cout << "To be completed..." << endl;

	string buffer;
	getline(cin, buffer);	// Press ENTER to continue
}
