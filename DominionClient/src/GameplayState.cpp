#include "GameplayState.h"

#include "CommonFunctions.h"
#include "Decision.h"
#include "DominionApp.h"
#include "MainMenuState.h"
#include "PacketID.h"
#include "Settings.h"
#include <exception>
#include <iostream>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <sstream>

using namespace std;

GameplayState::GameplayState()
{
	app = DominionApp::dominionApp;

	playerName = "";
	ipAddressString = "";
	port = "";
	
	portNumber = 4521;

	stage = CONNECTING;
	leftButtonDown = false;

	if(!Settings::isGameTextOnly())
	{
		background.setTexture(app->resources.backgroundCastle);
		background.setPosition(0, 0);
		background.setScale(app->window->getView().getSize().x / app->resources.backgroundCastle.getSize().x, 
			app->window->getView().getSize().y / app->resources.backgroundCastle.getSize().y);

		unableToConnectText.setFont(app->resources.deutschFont);
		unableToConnectText.setString("Trying to connect...");
		unableToConnectText.setCharacterSize(app->window->getSize().y / 25);
		unableToConnectText.setPosition(sf::Vector2f(0.05f * app->window->getSize().x, 0.05f * app->window->getSize().y));

		exitButton = ClickableButton(&app->resources.xButton,
			sf::Vector2f(0.0f * app->window->getSize().x, 0.0f * app->window->getSize().y),
			sf::Vector2f(0.02f * app->window->getSize().x, 0.03f * app->window->getSize().y));
	}
}
GameplayState::~GameplayState()
{

}
void GameplayState::runTextOnly()
{
	CommonFunctions::clearScreen();
	
	bool wantsToConnect = true, connectionSuccessful = false;

	while(wantsToConnect)
	{
		bool enteringName = true, enteringIP = true, enteringPort = true;

		while(enteringName)
		{
			cout << "Please enter your player name:" << endl;
			getline(cin, playerName);

			if(playerName.compare("") == 0)
			{
				cout << "\nPlease enter a valid name (press ENTER to continue)." << endl;

				getline(cin, playerName);	// Press enter to continue
			}
			else
			{
				enteringName = false;
			}
		}

		while(enteringIP)
		{
			cout << "\nPlease enter the IP address of the server you wish to connect to (press ENTER for LOCALHOST):" << endl;
			getline(cin, ipAddressString);

			if(ipAddressString.compare("") == 0)
			{
				ipAddress = sf::IpAddress::LocalHost;
				enteringIP = false;
			}
			else
			{
				ipAddress = ipAddressString;
				enteringIP = false;
			}
		}
		
		while(enteringPort)
		{
			cout << "\nPlease enter the port the server is being hosted on (2048 - 65535, press ENTER for default):" << endl;
			getline(cin, port);

			if(port.compare("") != 0)
			{
				stringstream converter;
				converter << port;

				if(!(converter >> portNumber) || portNumber < 2048 || portNumber > 65535)	// Invalid input
				{
					cout << "Please enter a valid number (press ENTER to continue)." << endl;

					getline(cin, port);	// Press enter to continue
				}
				else
				{
					enteringPort = false;
				}
			}
			else
			{
				enteringPort = false;
			}
		}
		
		if(socket.connect(ipAddress, portNumber, sf::seconds(5)) != sf::Socket::Done)
		{
			cout << endl;

			Decision tryAgain("Connection failed, try again?");

			tryAgain.addOption("Yes");
			tryAgain.addOption("No");

			int decisionResult = tryAgain.makeDecision(false);

			if(decisionResult == 0)	// Yes
			{
				CommonFunctions::clearScreen();
			}
			else	// No
			{
				wantsToConnect = false;
			}
		}
		else
		{
			connectionSuccessful = true;
			wantsToConnect = false;
		}
	}

	if(connectionSuccessful)
	{
		CommonFunctions::clearScreen();

		sf::Packet namePacket;
		namePacket << playerName;
		socket.send(namePacket);

		bool conenctionStatusOK = true;
		sf::Packet receivedPacket;

		while(conenctionStatusOK && socket.receive(receivedPacket) == sf::Socket::Done)
		{
			unsigned short packetID;

			receivedPacket >> packetID;

			if(packetID == PacketID::GAME_OVER)
			{
				cout << "Game is finished. Returning to main menu." << endl;
				return;
			}
			else if(packetID == PacketID::STANDARD_MESSAGE)
			{
				bool requiredResponse;
				string message;

				receivedPacket >> requiredResponse >> message;

				cout << message;

				if(requiredResponse)
				{
					sf::Packet responsePacket;
					string response;

					getline(cin, response);
					responsePacket << response;

					if(socket.send(responsePacket) != sf::Socket::Done)
					{
						conenctionStatusOK = false;
					}
				}
			}
			else if(packetID == PacketID::CLEAR_SCREEN)
			{
				CommonFunctions::clearScreen();
			}
		}

		cout << "Game ended unexpectedly, returning to main menu." << endl;
	}
	else
	{
		cout << "Returning to main menu." << endl;
	}

	socket.disconnect();
}
void GameplayState::step()
{
	switch(stage)
	{
		case CONNECTING:
		{
			if(playerName.compare("") == 0)
			{
				unableToConnectText.setString("Name cannot be blank. Enter a different name.");
			}
			else if(ipAddressString.compare("") == 0)
			{
				unableToConnectText.setString("IP address cannot be blank. Enter a different IP address.");
			}
			else if(port.compare("") == 0)
			{
				unableToConnectText.setString("Port number cannot be blank. Enter a different port number.");
			}
			else
			{
				stringstream converter;
				converter << port;

				if(!(converter >> portNumber) || portNumber < 2048 || portNumber > 65535)
				{
					unableToConnectText.setString("Invalid port number. Enter a port number betwwen 2048 and 65535.");
				}
			}
		}
		break;

		case LOBBY:
		{

		}
		break;

		default:
			throw exception("Undefined stage of game");
	}
}
void GameplayState::draw()
{
	app->window->draw(background);
	app->window->draw(unableToConnectText);
	app->window->draw(exitButton);

	app->window->display();
}
void GameplayState::eventMouseMoved(sf::Event mouseEvent)
{
	updateClickables(app->window->convertCoords(sf::Vector2i(mouseEvent.mouseMove.x, mouseEvent.mouseMove.y)), leftButtonDown);
}
void GameplayState::eventMouseButtonPressed(sf::Event mouseEvent)
{
	if(mouseEvent.mouseButton.button == sf::Mouse::Left)
		leftButtonDown = true;

	updateClickables(app->window->convertCoords(sf::Vector2i(mouseEvent.mouseButton.x, mouseEvent.mouseButton.y)), leftButtonDown);
}
void GameplayState::eventMouseButtonReleased(sf::Event mouseEvent)
{
	if(mouseEvent.mouseButton.button == sf::Mouse::Left)
		leftButtonDown = false;

	updateClickables(app->window->convertCoords(sf::Vector2i(mouseEvent.mouseButton.x, mouseEvent.mouseButton.y)), leftButtonDown);
}
void GameplayState::eventKeyPressed(sf::Event keyEvent)
{
	if(keyEvent.key.code == sf::Keyboard::Escape)
	{
		backToMainMenu();
	}
}
void GameplayState::setConnectionDetails(string playerName, string ipAddressString, string port)
{
	this->playerName = playerName;
	this->ipAddressString = ipAddressString;
	this->port = port;
}
void GameplayState::updateClickables(sf::Vector2f mousePosition, bool isLeftButtonPressed)
{
	if(exitButton.updateAndGetClicked(mousePosition, isLeftButtonPressed))
	{
		exitButton.resetStates();
		app->currentState = app->mainMenuState;
	}
}
void GameplayState::backToMainMenu()
{
	app->currentState = app->mainMenuState;
}
