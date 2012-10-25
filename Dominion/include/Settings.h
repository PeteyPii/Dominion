#pragma once

#include <map>
#include <string>

class Settings
{
public:
	static std::map<std::string, int> settings;

	static void loadSettings();

private:
	Settings();
	~Settings();
};
