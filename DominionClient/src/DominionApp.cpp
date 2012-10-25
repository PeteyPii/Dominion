#include "DominionApp.h"

DominionApp* DominionApp::dominionApp;

DominionApp::DominionApp()
	: window(sf::VideoMode(800, 600, 32), "Dominion")
{
	dominionApp = this;
}
DominionApp::~DominionApp()
{

}
void DominionApp::begin()
{
	mainMenuState.runState();
}
