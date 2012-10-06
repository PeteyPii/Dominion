#include "GameplayState.h"

#include "CommonFunctions.h"
#include "Decision.h"
#include <iostream>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <sstream>

using namespace std;

GameplayState::GameplayState()
{

}
GameplayState::~GameplayState()
{

}
void GameplayState::runState()
{
	CommonFunctions::ClearScreen();

	string name, ipAddressString, port;
	unsigned short portNumber = 4521;
	sf::IpAddress ipAddress;
	bool wantsToConnect = true, connectionSuccessful = false;

	sf::TcpSocket socket;

	while(wantsToConnect)
	{
		bool enteringName = true, enteringPort = true;

		while(enteringName)
		{
			cout << "Please enter your player name:" << endl;
			getline(cin, name);

			if(name.compare("") == 0)
			{
				cout << "Please enter a valid name (press enter to continue)." << endl;

				getline(cin, name);	// Press enter to continue
			}
			else
			{
				enteringName = false;
			}
		}

		cout << "Please enter the IP address of the server you wish to connect to:" << endl;
		getline(cin, ipAddressString);

		ipAddress = ipAddressString;

		while(enteringPort)
		{
			cout << "Please enter the port the server is being hosted on (2048 - 65535, press enter for default):" << endl;
			getline(cin, port);

			if(!(port.compare("") == 0))
			{
				stringstream converter;
				converter << port;

				if(!(converter >> portNumber) || portNumber < 2048 || portNumber > 65535)	// Invalid input
				{
					cout << "Please enter a valid number (press enter to continue)." << endl;

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
			Decision tryAgain("Connection failed, try again?");

			tryAgain.addOption("Yes");
			tryAgain.addOption("No");

			int decisionResult = tryAgain.makeDecision(false);

			if(decisionResult == 0)	// Yes
			{
				wantsToConnect = true;
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
		sf::Packet namePacket;
		namePacket << name;
		socket.send(namePacket);

		bool conenctionStatusOK = true;
		sf::Packet receivedPacket;

		while(conenctionStatusOK && socket.receive(receivedPacket) == sf::Socket::Done)
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

		cout << "Game ended unexpectedly, returning to main menu." << endl;
	}
	else
	{
		cout << "Returning to main menu." << endl;
	}

	socket.disconnect();
}
