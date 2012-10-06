#pragma once

class PacketID
{
private:
	PacketID();
	~PacketID();

public:
	static const unsigned short GAME_OVER;
	static const unsigned short STANDARD_MESSAGE;
	static const unsigned short CLEAR_SCREEN;
};

