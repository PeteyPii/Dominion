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
	playerNameBoxClicked = false;
	ipAddressBoxClicked = false;
	portNumberBoxClicked = false;

	background.setTexture(app->resources.backgroundCastle);
	background.setPosition(0, 0);
	background.setScale(app->window->getView().getSize().x / app->resources.backgroundCastle.getSize().x, 
						app->window->getView().getSize().y / app->resources.backgroundCastle.getSize().y);

	titleText.setFont(app->resources.deutschFont);
	titleText.setString("Connect To A Server");
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
		
	playerNameText.setFont(app->resources.deutschFont);
	playerNameText.setString("Player name:");
	playerNameText.setCharacterSize(app->window->getSize().y / 22);
	playerNameText.setPosition(sf::Vector2f(0.1f * app->window->getSize().x, 0.3f * app->window->getSize().y));
	
	ipAddressText.setFont(app->resources.deutschFont);
	ipAddressText.setString("IP address:");
	ipAddressText.setCharacterSize(app->window->getSize().y / 22);
	ipAddressText.setPosition(sf::Vector2f(0.1f * app->window->getSize().x, 0.5f * app->window->getSize().y));
	
	portNumberText.setFont(app->resources.deutschFont);
	portNumberText.setString("Port number:");
	portNumberText.setCharacterSize(app->window->getSize().y / 22);
	portNumberText.setPosition(sf::Vector2f(0.1f * app->window->getSize().x, 0.7f * app->window->getSize().y));

	playerNameTextBox = TextBox("Enter name here:",
		sf::Vector2f(0.25f * app->window->getSize().x, 0.3f * app->window->getSize().y),
		sf::Vector2f(0.6f * app->window->getSize().x, 0.06f * app->window->getSize().y),
		&app->resources.deutschFont,
		app->window->getSize().y / 22);

	playerNameTextBox.select(true);
	
	ipAddressTextBox = TextBox("Enter IP address here:",
		sf::Vector2f(0.25f * app->window->getSize().x, 0.5f * app->window->getSize().y),
		sf::Vector2f(0.6f * app->window->getSize().x, 0.06f * app->window->getSize().y),
		&app->resources.deutschFont,
		app->window->getSize().y / 22);
	
	portNumberTextBox = TextBox("Enter name here:",
		sf::Vector2f(0.25f * app->window->getSize().x, 0.7f * app->window->getSize().y),
		sf::Vector2f(0.6f * app->window->getSize().x, 0.06f * app->window->getSize().y),
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
	app->window->draw(playerNameText);
	app->window->draw(ipAddressText);
	app->window->draw(portNumberText);

	app->window->draw(connectText);
	app->window->draw(backText);
	app->window->draw(playerNameTextBox);
	app->window->draw(ipAddressTextBox);
	app->window->draw(portNumberTextBox);

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
void ConnectToAServerState::eventKeyPressed(sf::Event keyEvent)
{
	if(keyEvent.key.code == sf::Keyboard::BackSpace)
	{
		if(playerNameTextBox.isSelected() && playerNameTextBox.text.getString().getSize() >= 1)
		{
			if(playerNameBoxClicked)
			{
				sf::String text(playerNameTextBox.text.getString());
				text.erase(text.getSize() - 1);
				playerNameTextBox.text.setString(text);
			}
			else
			{
				playerNameTextBox.text.setString("");
				playerNameBoxClicked = true;
			}
		}
		else if(ipAddressTextBox.isSelected() && ipAddressTextBox.text.getString().getSize() >= 1)
		{
			sf::String text(ipAddressTextBox.text.getString());
			text.erase(text.getSize() - 1);
			ipAddressTextBox.text.setString(text);
		}
		else if(portNumberTextBox.isSelected() && portNumberTextBox.text.getString().getSize() >= 1)
		{
			sf::String text(portNumberTextBox.text.getString());
			text.erase(text.getSize() - 1);
			portNumberTextBox.text.setString(text);
		}
	}
	else if(keyEvent.key.code == sf::Keyboard::Return)
	{
		connect();
	}
	else if(keyEvent.key.code == sf::Keyboard::Tab)
	{
		if(playerNameTextBox.isSelected())
		{
			playerNameTextBox.select(false);
			ipAddressTextBox.select(true);

			if(!ipAddressBoxClicked)
			{
				ipAddressTextBox.text.setString("");
				ipAddressBoxClicked = true;
			}
		}
		else if(ipAddressTextBox.isSelected())
		{
			ipAddressTextBox.select(false);
			portNumberTextBox.select(true);

			if(!portNumberBoxClicked)
			{
				portNumberTextBox.text.setString("");
				portNumberBoxClicked = true;
			}
		}
		else if(portNumberTextBox.isSelected())
		{
			portNumberTextBox.select(false);
			playerNameTextBox.select(true);

			if(!playerNameBoxClicked)
			{
				playerNameTextBox.text.setString("");
				playerNameBoxClicked = true;
			}
		}
		else
		{
			playerNameTextBox.select(true);

			if(!playerNameBoxClicked)
			{
				playerNameTextBox.text.setString("");
				playerNameBoxClicked = true;
			}
		}
	}
	else if(keyEvent.key.code == sf::Keyboard::Escape)
	{
		back();
	}
}
void ConnectToAServerState::eventTextEntered(sf::Event textEvent)
{
	if(textEvent.text.unicode >= 0x20 && textEvent.text.unicode <= 0x7E)
	{
		if(playerNameTextBox.isSelected())
		{
			if(!playerNameBoxClicked)
			{
				playerNameTextBox.text.setString(textEvent.text.unicode);
				playerNameBoxClicked = true;
			}
			else
			{
				playerNameTextBox.text.setString(playerNameTextBox.text.getString() + textEvent.text.unicode);
			}
		}
		else if(ipAddressTextBox.isSelected())
		{
			ipAddressTextBox.text.setString(ipAddressTextBox.text.getString() + textEvent.text.unicode);
		}
		else if(portNumberTextBox.isSelected())
		{
			portNumberTextBox.text.setString(portNumberTextBox.text.getString() + textEvent.text.unicode);
		}
	}
}
void ConnectToAServerState::updateButtonsAndTextBoxes(sf::Vector2f mousePosition, bool isLeftButtonPressed)
{
	if(connectText.updateAndGetClicked(mousePosition, isLeftButtonPressed))
		connect();

	if(backText.updateAndGetClicked(mousePosition, isLeftButtonPressed))
		back();

	if(playerNameTextBox.updateAndGetClicked(mousePosition, isLeftButtonPressed))
	{
		if(!playerNameBoxClicked)
		{
			playerNameTextBox.text.setString("");
			playerNameBoxClicked = true;
		}
	}

	if(ipAddressTextBox.updateAndGetClicked(mousePosition, isLeftButtonPressed))
	{
		if(!ipAddressBoxClicked)
		{
			ipAddressTextBox.text.setString("");
			ipAddressBoxClicked = true;
		}
	}

	if(portNumberTextBox.updateAndGetClicked(mousePosition, isLeftButtonPressed))
	{
		if(!portNumberBoxClicked)
		{
			portNumberTextBox.text.setString("");
			portNumberBoxClicked = true;
		}
	}
}
void ConnectToAServerState::connect()
{
	app->gameplayState->setConnectionDetails(playerNameTextBox.text.getString(), ipAddressTextBox.text.getString(), portNumberTextBox.text.getString());
}
void ConnectToAServerState::back()
{
	app->currentState = app->mainMenuState;
}
