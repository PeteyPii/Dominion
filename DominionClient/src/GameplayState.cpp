#include "GameplayState.h"

#include "CommonFunctions.h"
#include "Decision.h"
#include "PacketID.h"
#include <exception>
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
		bool enteringName = true, enteringIP = true, enteringPort = true;

		while(enteringName)
		{
			cout << "Please enter your player name:" << endl;
			getline(cin, name);

			if(name.compare("") == 0)
			{
				cout << "\nPlease enter a valid name (press ENTER to continue)." << endl;

				getline(cin, name);	// Press enter to continue
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
				CommonFunctions::ClearScreen();
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
		CommonFunctions::ClearScreen();

		sf::Packet namePacket;
		namePacket << name;
		socket.send(namePacket);

		bool conenctionStatusOK = true;
		sf::Packet receivedPacket;

		while(conenctionStatusOK && socket.receive(receivedPacket) == sf::Socket::Done)
		{
			unsigned short packetID;

			receivedPacket >> packetID;

			switch(packetID)
			{
			case PacketID::GAME_OVER:
				cout << "Game is finished. Returning to main menu." << endl;
				return;
			case PacketID::STANDARD_MESSAGE:
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

				break;
			case PacketID::CLEAR_SCREEN:
				CommonFunctions::ClearScreen();
				break;
			default:
				throw exception
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
