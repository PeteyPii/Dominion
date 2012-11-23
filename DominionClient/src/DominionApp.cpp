#include "DominionApp.h"

#include "ConnectToAServerState.h"
#include "GameplayState.h"
#include "InstructionsState.h"
#include "MainMenuState.h"
#include "Settings.h"
#include "State.h"
#include <SFML/System.hpp>


DominionApp *DominionApp::dominionApp;

DominionApp::DominionApp()
{
	dominionApp = this;

	window = 0;

	keepRunning = true;

	Settings::loadSettings();

	if(!Settings::isGameTextOnly())
	{
		//window = new sf::RenderWindow(sf::VideoMode(960, 540, 32), "Dominion");
		window = new sf::RenderWindow(sf::VideoMode(1600, 900, 32), "Dominion");
		//window = new sf::RenderWindow(sf::VideoMode(1280, 720, 32), "Dominion");
		window->setFramerateLimit(60);

		resources.loadResources();
	}

	mainMenuState = new MainMenuState();
	connectToAServerState = new ConnectToAServerState();
	gameplayState = new GameplayState();
	instructionsState = new InstructionsState();

	currentState = mainMenuState;
}
DominionApp::~DominionApp()
{
	Settings::saveSettings();

	delete window;

	delete mainMenuState;
	delete connectToAServerState;
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
		while(window->isOpen() && keepRunning)
		{
			sf::Event event;

			while(window->pollEvent(event))
			{
				if(event.type == sf::Event::MouseMoved)
				{
					currentState->eventMouseMoved(event);
				}
				else if(event.type == sf::Event::MouseButtonPressed)
				{
					currentState->eventMouseButtonPressed(event);
				}
				else if(event.type == sf::Event::MouseButtonReleased)
				{
					currentState->eventMouseButtonReleased(event);
				}
				else if(event.type == sf::Event::KeyPressed)
				{
					currentState->eventKeyPressed(event);
				}
				else if(event.type == sf::Event::KeyReleased)
				{
					currentState->eventKeyReleased(event);
				}
				else if(event.type == sf::Event::TextEntered)
				{
					currentState->eventTextEntered(event);
				}
				else if(event.type == sf::Event::MouseWheelMoved)
				{
					currentState->eventMouseWheelMoved(event);
				}
				else if(event.type == sf::Event::Resized)
				{
					currentState->eventWindowResized(event);
				}
				else if(event.type == sf::Event::Closed)
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
void DominionApp::stop()
{
	keepRunning = false;
}
