#include "InstructionsState.h"

#include "CommonFunctions.h"
#include <iostream>

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
}
