#include "Board.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	vector<string> playerNames;

	playerNames.push_back("Player 1");
	playerNames.push_back("Player 2");

	Board boardGame(10, 10, 3, 8, 10, 30, playerNames);

	boardGame.beginGame();

	cout << "Game has been finished, press ENTER to exit the application." << endl;

	string buffer;
	cin >> buffer;

	return 0;
}

