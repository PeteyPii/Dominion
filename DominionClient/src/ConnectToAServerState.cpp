#include "ConnectToAServerState.h"

#include "ClientResources.h"
#include "DominionApp.h"
#include "GameplayState.h"
#include "MainMenuState.h"
#include <iostream>

using namespace std;

ConnectToAServerState::ConnectToAServerState()
{
	app = DominionApp::dominionApp;

	leftButtonDown = false;

	background.setTexture(app->resources.backgroundCastle);
	background.setPosition(0, 0);
	background.setScale(app->window->getView().getSize().x / app->resources.backgroundCastle.getSize().x, 
						app->window->getView().getSize().y / app->resources.backgroundCastle.getSize().y);

	titleText.setFont(app->resources.deutschFont);
	titleText.setString("Connect To A Server:");
	titleText.setCharacterSize(app->window->getSize().y / 11);
	titleText.setPosition(sf::Vector2f(0.3f * app->window->getSize().x, 0.05f * app->window->getSize().y));

	connectText = ClickableText("Connect", 
		sf::Vector2f(0.3f * app->window->getSize().x, 0.87f * app->window->getSize().y), 
		app->window->getSize().y / 27, 
		&DominionApp::dominionApp->resources.deutschFont);

	backText = ClickableText("Back", 
		sf::Vector2f(0.6f * app->window->getSize().x, 0.87f * app->window->getSize().y), 
		app->window->getSize().y / 27, 
		&DominionApp::dominionApp->resources.deutschFont);

	playerNameTextBox = TextBox(sf::Vector2f(0.2f * app->window->getSize().x, 0.3f * app->window->getSize().y),
		sf::Vector2f(0.6f * app->window->getSize().x, 0.06f * app->window->getSize().y),
		"Enter name here:",
		&app->resources.deutschFont,
		app->window->getSize().y / 22);
}
ConnectToAServerState::~ConnectToAServerState()
{
	
}
void ConnectToAServerState::step()
{
	
}
void ConnectToAServerState::draw()
{
	app->window->draw(background);

	app->window->draw(titleText);
	app->window->draw(connectText);
	app->window->draw(backText);

	app->window->draw(playerNameTextBox);

	app->window->display();
}
void ConnectToAServerState::eventMouseMoved(sf::Event mouseEvent)
{
	updateButtonsAndTextBoxes(app->window->convertCoords(sf::Vector2i(mouseEvent.mouseMove.x, mouseEvent.mouseMove.y)), leftButtonDown);
}
void ConnectToAServerState::eventMouseButtonPressed(sf::Event mouseEvent)
{
	if(mouseEvent.mouseButton.button == sf::Mouse::Left)
		leftButtonDown = true;

	updateButtonsAndTextBoxes(app->window->convertCoords(sf::Vector2i(mouseEvent.mouseButton.x, mouseEvent.mouseButton.y)), leftButtonDown);
}
void ConnectToAServerState::eventMouseButtonReleased(sf::Event mouseEvent)
{
	if(mouseEvent.mouseButton.button == sf::Mouse::Left)
		leftButtonDown = false;

	updateButtonsAndTextBoxes(app->window->convertCoords(sf::Vector2i(mouseEvent.mouseButton.x, mouseEvent.mouseButton.y)), leftButtonDown);
}
void ConnectToAServerState::eventTextEntered(sf::Event textEvent)
{

}
void ConnectToAServerState::updateButtonsAndTextBoxes(sf::Vector2f mousePosition, bool isLeftButtonPressed)
{
	if(connectText.updateAndGetClicked(mousePosition, isLeftButtonPressed))
		connect();

	if(backText.updateAndGetClicked(mousePosition, isLeftButtonPressed))
		back();

	if(playerNameTextBox.updateAndGetClicked(mousePosition, isLeftButtonPressed))
	{

	}
}
void ConnectToAServerState::connect()
{
	app->gameplayState->setConnectionDetails("", "", "");
}
void ConnectToAServerState::back()
{
	app->currentState = app->mainMenuState;
}
