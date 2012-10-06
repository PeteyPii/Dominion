#include "DominionApp.h"


DominionApp* DominionApp::dominionApp;

DominionApp::DominionApp()
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
