#include "MainMenuState.h"

#include "ConnectToAServerState.h"
#include "ClientResources.h"
#include "CommonFunctions.h"
#include "Decision.h"
#include "DominionApp.h"
#include "GameplayState.h"
#include "InstructionsState.h"
#include "Settings.h"
#include <iostream>

using namespace std;

MainMenuState::MainMenuState()
{
	app = DominionApp::dominionApp;

	leftButtonDown = false;

	if(!Settings::isGameTextOnly())
	{
		background.setTexture(app->resources.backgroundCastle);
		background.setPosition(0, 0);
		background.setScale(app->window->getView().getSize().x / app->resources.backgroundCastle.getSize().x, 
							app->window->getView().getSize().y / app->resources.backgroundCastle.getSize().y);

		titleText.setFont(app->resources.deutschFont);
		titleText.setString("DOMINION");
		titleText.setCharacterSize(app->window->getSize().y / 9);
		titleText.setPosition(sf::Vector2f(0.05f * app->window->getSize().x, 0.05f * app->window->getSize().y));

		connectToServerText = ClickableText("Connect to a server", 
			sf::Vector2f(0.75f * app->window->getSize().x, 0.8f * app->window->getSize().y), 
			app->window->getSize().y / 27, 
			&DominionApp::dominionApp->resources.deutschFont);

		exitText = ClickableText("Exit game", 
			sf::Vector2f(0.75f * app->window->getSize().x, 0.85f * app->window->getSize().y), 
			app->window->getSize().y / 27, 
			&DominionApp::dominionApp->resources.deutschFont);
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
	
}
void MainMenuState::draw()
{
	app->window->draw(background);

	app->window->draw(titleText);
	app->window->draw(connectToServerText);
	app->window->draw(exitText);

	app->window->display();
}
void MainMenuState::eventMouseMoved(sf::Event mouseEvent)
{
	updateButtons(app->window->convertCoords(sf::Vector2i(mouseEvent.mouseMove.x, mouseEvent.mouseMove.y)), leftButtonDown);
}
void MainMenuState::eventMouseButtonPressed(sf::Event mouseEvent)
{
	if(mouseEvent.mouseButton.button == sf::Mouse::Left)
		leftButtonDown = true;

	updateButtons(app->window->convertCoords(sf::Vector2i(mouseEvent.mouseButton.x, mouseEvent.mouseButton.y)), leftButtonDown);
}
void MainMenuState::eventMouseButtonReleased(sf::Event mouseEvent)
{
	if(mouseEvent.mouseButton.button == sf::Mouse::Left)
		leftButtonDown = false;

	updateButtons(app->window->convertCoords(sf::Vector2i(mouseEvent.mouseButton.x, mouseEvent.mouseButton.y)), leftButtonDown);
}
void MainMenuState::updateButtons(sf::Vector2f mousePosition, bool isLeftButtonPressed)
{
	if(connectToServerText.updateAndGetClicked(mousePosition, isLeftButtonPressed))
	{
		connectToServer();
	}
	else if(exitText.updateAndGetClicked(mousePosition, isLeftButtonPressed))
	{
		exit();
	}
}
void MainMenuState::connectToServer()
{
	app->currentState = app->connectToAServerState;
	connectToServerText.resetStates();
}
void MainMenuState::exit()
{
	app->stop();
}
