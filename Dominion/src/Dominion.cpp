#include "Board.h"
#include "Decision.h"
#include "Player.h"
#include <iostream>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int minValue(int valueOne, int valueTwo)
{
	if(valueOne < valueTwo)
		return valueOne;
	else
		return valueTwo;
}

int maxValue(int valueOne, int valueTwo)
{
	if(valueOne > valueTwo)
		return valueOne;
	else
		return valueTwo;
}

int main()
{
	unsigned short portNumber;
	bool enterSocket = true;

	while(enterSocket)
	{
		cout << "Please enter the socket you wish to host the server on (2048 - 65535):" << endl;

		if(!(cin >> portNumber) || portNumber > 65535 || portNumber < 2048)
		{
			cout << "Bad input." << endl;
		}
		else
		{
			enterSocket = false;
		}
	}

	sf::TcpListener listener;

	if (!listener.listen(portNumber))
	{
		cerr << "Listening on the socket failed." << endl;

		return 1;
	}

	cout << "Listening on port " << portNumber 
		 << " from the internal address " << sf::IpAddress::getLocalAddress() 
		 << " and from the external address " << sf::IpAddress::getPublicAddress(sf::Time(10 * 1000 * 1000))
		 << endl;

	vector<Player> initPlayers;
	int numberOfPlayers = 0;
	bool acceptingMoreConnections = true;
	
	while(acceptingMoreConnections)
	{
		initPlayers.push_back(Player());
		listener.accept(initPlayers[numberOfPlayers].socket);

		sf::Packet namePacket;
		initPlayers[numberOfPlayers].socket.receive(namePacket);
		char nameBuffer[64];
		namePacket >> nameBuffer;
		nameBuffer[63] = 0;
		initPlayers[numberOfPlayers].name = nameBuffer;

		numberOfPlayers++;

		for(unsigned int ii = 0; ii < numberOfPlayers; ii++)
		{
			stringstream output;
			output << initPlayers[numberOfPlayers - 1].name << " has joined the lobby." << endl;
			initPlayers[ii].displayMessage(output.str(), false);
		}

		Decision beginGame("Start game?", &initPlayers[0]);

		beginGame.addOption("Yes");
		beginGame.addOption("No");

		int decisionResult = beginGame.makeDecision(false);

		if(decisionResult == 0)	// Yes
		{
			for(unsigned int ii = 0; ii < numberOfPlayers; ii++)
			{
				stringstream output;
				output << "Starting the game." << endl;
				initPlayers[ii].displayMessage(output.str(), false);
			}

			acceptingMoreConnections = false;
		}
		else	// No
		{
			for(unsigned int ii = 0; ii < numberOfPlayers; ii++)
			{
				stringstream output;
				output << "Waiting for another player." << endl;
				initPlayers[ii].displayMessage(output.str(), false);
			}
		}
	}

	Board boardGame(10, 10, maxValue(3, numberOfPlayers * 0.5 + 2), maxValue(8, numberOfPlayers * 4), maxValue(10, numberOfPlayers * 10 - 10), 30, initPlayers);

	boardGame.beginGame();

	cout << "Game has been finished, press ENTER to exit the application." << endl;

	string buffer;
	cin >> buffer;

	return 0;
}

