#include "InstructionsState.h"

#include "CommonFunctions.h"
#include "DominionApp.h"
#include "MainMenuState.h"
#include "Settings.h"
#include <exception>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

InstructionsState::InstructionsState()
{
	app = DominionApp::dominionApp;

	leftButtonDown = false;

	if(!Settings::isGameTextOnly())
	{
		background.setTexture(app->resources.backgroundCastle);
		background.setPosition(0, 0);
		background.setScale(app->window->getView().getSize().x / app->resources.backgroundCastle.getSize().x, 
			app->window->getView().getSize().y / app->resources.backgroundCastle.getSize().y);

		titleText.setFont(app->resources.deutschFont);
		titleText.setString("Instructions");
		titleText.setCharacterSize(app->window->getSize().y / 11);
		titleText.setPosition(sf::Vector2f(0.05f * app->window->getSize().x, 0.05f * app->window->getSize().y));

		backText = ClickableText("Back", 
			sf::Vector2f(0.05f * app->window->getSize().x, 0.85f * app->window->getSize().y), 
			app->window->getSize().y / 27, 
			&DominionApp::dominionApp->resources.deutschFont);

		instructionsTextBox = TextBox("",
			sf::Vector2f(0.3f * app->window->getSize().x, -0.05f * app->window->getSize().y), 
			sf::Vector2f(1.0f * app->window->getSize().x, 1.1f * app->window->getSize().y),
			&app->resources.deutschFont,
			app->window->getSize().y / 28);

		ifstream instructionsFile("resources/data/instructions.txt");

		if(!instructionsFile.is_open())
		{
			throw exception("Could not find the instructions file");
		}

		while(instructionsFile)
		{
			string line;
			getline(instructionsFile, line);
			instructionsTextBox.text.setString(instructionsTextBox.text.getString() + line + '\n');
		}

		instructionsFile.close();

		instructionsTextBox.text.setPosition(instructionsTextBox.background.getPosition().x + 0.015f * app->window->getSize().x, 0);
	}
}
InstructionsState::~InstructionsState()
{

}
void InstructionsState::runTextOnly()
{
	CommonFunctions::clearScreen();

	cout << "|--- Instructions ---|" << endl;
	cout << "Press ENTER to keep scrolling." << endl;

	ifstream instructionsFile("resources/data/instructions.txt");

	if(!instructionsFile.is_open())
	{
		throw exception("Could not find the instructions file");
	}

	while(instructionsFile)
	{
		string buffer;
		getline(cin, buffer);	// Press ENTER to continue

		string line;
		getline(instructionsFile, line);
		cout << line;
	}

	instructionsFile.close();

	cout << "\nPress ENTER to return to the main menu.";

	string buffer;
	getline(cin, buffer);	// Press ENTER to continue
}
void InstructionsState::step()
{

}
void InstructionsState::draw()
{
	app->window->draw(background);

	app->window->draw(titleText);
	app->window->draw(backText);
	app->window->draw(instructionsTextBox);

	app->window->display();
}
void InstructionsState::eventMouseMoved(sf::Event mouseEvent)
{
	updateButton(app->window->convertCoords(sf::Vector2i(mouseEvent.mouseMove.x, mouseEvent.mouseMove.y)), leftButtonDown);
}
void InstructionsState::eventMouseButtonPressed(sf::Event mouseEvent)
{
	if(mouseEvent.mouseButton.button == sf::Mouse::Left)
		leftButtonDown = true;

	updateButton(app->window->convertCoords(sf::Vector2i(mouseEvent.mouseButton.x, mouseEvent.mouseButton.y)), leftButtonDown);
}
void InstructionsState::eventMouseButtonReleased(sf::Event mouseEvent)
{
	if(mouseEvent.mouseButton.button == sf::Mouse::Left)
		leftButtonDown = false;

	updateButton(app->window->convertCoords(sf::Vector2i(mouseEvent.mouseButton.x, mouseEvent.mouseButton.y)), leftButtonDown);
}
void InstructionsState::eventMouseWheelMoved(sf::Event mouseEvent)
{
	instructionsTextBox.text.setPosition(instructionsTextBox.background.getPosition().x + 0.015f * app->window->getSize().x, mouseEvent.mouseWheel.delta * 0.004f * app->window->getSize().y + instructionsTextBox.text.getPosition().y);
}
void InstructionsState::eventKeyPressed(sf::Event keyEvent)
{
	if(keyEvent.key.code == sf::Keyboard::Escape)
	{
		back();
	}
}
void InstructionsState::updateButton(sf::Vector2f mousePosition, bool isLeftButtonPressed)
{
	if(backText.updateAndGetClicked(mousePosition, isLeftButtonPressed))
		back();
}
void InstructionsState::back()
{
	backText.resetStates();
	app->currentState = app->mainMenuState;
}
