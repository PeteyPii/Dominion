#include "MainMenuState.h"

#include "CommonFunctions.h"
#include "Decision.h"
#include "DominionApp.h"
#include <iostream>

using namespace std;

MainMenuState::MainMenuState(void)
{

}
MainMenuState::~MainMenuState(void)
{

}
void MainMenuState::runState()
{
	while(true)
	{
		CommonFunctions::clearScreen();

		cout << "______________________" << endl;
		cout << "|                    |" << endl;
		cout << "|   DOMINION         |" << endl;
		cout << "|      by PeteyPii   |" << endl;
		cout << "|____________________|" << endl;
		cout << "\n\n" << endl;

		Decision mainMenu("Choose what you want to do:");

		mainMenu.addOption("Play game");
		mainMenu.addOption("See instructions");
		mainMenu.addOption("Exit game");

		int decisionResult = mainMenu.makeDecision(false);

		if(decisionResult == 0)	// Play game
		{
			DominionApp::dominionApp->gameplayState.runState();
		}
		else if(decisionResult == 1)	// See instructions
		{
			DominionApp::dominionApp->instructionsState.runState();
		}
		else if(decisionResult == 2)	// Exit game
		{
			break;
		}
	}
}
