#include "MainMenuState.h"

#include "ClientResources.h"
#include "CommonFunctions.h"
#include "Decision.h"
#include "DominionApp.h"
#include "GameplayState.h"
#include "InstructionsState.h"
#include "Settings.h"
#include <iostream>
#include <SFML/System.hpp>

using namespace std;

MainMenuState::MainMenuState()
{
	app = DominionApp::dominionApp;

	if(!Settings::isGameTextOnly())
	{
		background.setTexture(app->resources.backgroundCastle);
		background.setPosition(0, 0);
		background.setScale(app->window->getView().getSize().x / app->resources.backgroundCastle.getSize().x, app->window->getView().getSize().y / app->resources.backgroundCastle.getSize().y);
	}
}
MainMenuState::~MainMenuState()
{
	
}
void MainMenuState::runTextOnly()
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
			app->gameplayState->runTextOnly();
		}
		else if(decisionResult == 1)	// See instructions
		{
			app->instructionsState->runTextOnly();
		}
		else if(decisionResult == 2)	// Exit game
		{
			break;
		}
	}
}
void MainMenuState::step()
{
	sf::Event event;

	while(app->window->pollEvent(event))
	{

	}
}
void MainMenuState::draw()
{
	app->window->clear(sf::Color(255,0,255,255));

	app->window->draw(background);

	app->window->display();
}
