#include "Settings.h"

#include <exception>
#include <fstream>
#include <sstream>

using namespace std;

std::map<std::string, int> Settings::settings;

Settings::Settings()
{

}
Settings::~Settings()
{

}
void Settings::loadSettings()
{
	ifstream settingsFile;
	settingsFile.open("settings.txt");

	while(settingsFile.good())
	{
		char line[64];
		settingsFile.getline(line, 64);

		if(line[0] == '\0' || line[0] == ' ' || line[0] == '\n')
		{
			continue;
		}

		string strLine(line), key, mapValue;

		size_t equalSign = strLine.find_first_of('=');

		if(equalSign == string::npos)
		{
			throw exception("Bad settings file");
		}

		key = strLine.substr(0, equalSign);
		mapValue = strLine.substr(equalSign + 1, strLine.size() - key.size() - 1);

		int number;
		stringstream converter;
		converter << mapValue;

		if(!(converter >> mapValue))
		{
			throw exception("Bad settings value");
		}

		settings.insert(pair<string, int>(key, number));
	}

	map<string, int> defaultSettings;

	defaultSettings.insert(pair<string, int>("textOnly", 0));
}
