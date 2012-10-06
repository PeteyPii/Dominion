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
	unsigned short portNumber = 4521;
	bool enterPort = true;

	while(enterPort)
	{
		cout << "Please enter the port you wish to host the server on (2048 - 65535, press enter for default):" << endl;

		string input;
		getline(cin, input);

		if(input.compare("") == 0)
		{
			enterPort = false;
		}
		else
		{
			stringstream converter;
			converter << input;

			if(!(converter >> portNumber) || portNumber > 65535 || portNumber < 2048)
			{
				cout << "Bad input (press enter to continue)." << endl;

				getline(cin, input);
			}
			else
			{
				enterPort = false;
			}
		}
	}

	sf::TcpListener listener;

	if (listener.listen(portNumber) != sf::TcpListener::Done)
	{
		cerr << "Listening on the socket failed." << endl;

		return 1;
	}

	cout << "Listening on port " << portNumber 
		 << " from the internal address " << sf::IpAddress::getLocalAddress() 
		 << " and from the external address " << sf::IpAddress::getPublicAddress(sf::seconds(10))
		 << endl;

	Board board;
	int numberOfPlayers = 0;
	bool acceptingMoreConnections = true;
	
	while(acceptingMoreConnections)
	{
		board.players.push_back(new Player());
		listener.accept(board.players[numberOfPlayers]->socket);

		sf::Packet namePacket;
		board.players[numberOfPlayers]->socket.receive(namePacket);
		namePacket >> board.players[numberOfPlayers]->name;

		numberOfPlayers++;

		for(int ii = 0; ii < numberOfPlayers; ii++)
		{
			stringstream output;
			output << board.players[numberOfPlayers - 1]->name << " has joined the lobby." << endl;
			board.players[ii]->displayMessage(output.str(), false);
		}

		Decision beginGame("Start game?", board.players[0]);

		beginGame.addOption("Yes");
		beginGame.addOption("No");

		int decisionResult = beginGame.makeDecision(false);

		if(decisionResult == 0)	// Yes
		{
			for(int ii = 0; ii < numberOfPlayers; ii++)
			{
				stringstream output;
				output << "Starting the game." << endl;
				board.players[ii]->displayMessage(output.str(), false);
			}

			acceptingMoreConnections = false;
		}
		else	// No
		{
			for(int ii = 0; ii < numberOfPlayers; ii++)
			{
				stringstream output;
				output << "Waiting for another player." << endl;
				board.players[ii]->displayMessage(output.str(), false);
			}
		}
	}

	board.initializeGame(10, 10, maxValue(3, (int)(numberOfPlayers * 0.5 + 2)), maxValue(8, numberOfPlayers * 4), maxValue(10, numberOfPlayers * 10 - 10), 30);
	board.beginGame();

	cout << "Game has been finished, press ENTER to exit the application." << endl;

	string input;
	getline(cin, input);

	return 0;
}

