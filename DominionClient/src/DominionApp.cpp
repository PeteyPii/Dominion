#include "DominionApp.h"

#include "GameplayState.h"
#include "InstructionsState.h"
#include "MainMenuState.h"
#include "Settings.h"
#include "State.h"

DominionApp* DominionApp::dominionApp;

DominionApp::DominionApp()
{
	dominionApp = this;

	window = 0;

	Settings::loadSettings();

	if(!Settings::isGameTextOnly())
	{
		window = new sf::RenderWindow(sf::VideoMode(960, 540, 32), "Dominion");
		window->setFramerateLimit(60);

		resources.loadResources();
	}

	mainMenuState = new MainMenuState();
	gameplayState = new GameplayState();
	instructionsState = new InstructionsState();

	currentState = mainMenuState;
}
DominionApp::~DominionApp()
{
	Settings::saveSettings();

	delete window;

	delete mainMenuState;
	delete gameplayState;
	delete instructionsState;
}
void DominionApp::begin()
{
	if(Settings::isGameTextOnly())	// Run game from command line
	{
		mainMenuState->runTextOnly();
	}
	else
	{
		while(window->isOpen())
		{
			sf::Event event;

			while(window->pollEvent(event))
			{
				if(event.type == sf::Event::Closed)
				{
					window->close();
					return;
				}
			}

			currentState->step();
			currentState->draw();
		}
	}
}
