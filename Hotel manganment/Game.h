#pragma once

#include "Hotel.h"


/* This class handles the commands and upgrade menus */

class Game
{
private:

	bool m_running;
	char m_command;
	int m_roomPrice;
	int m_increaseRoomSize;

	int m_upgradeHotelSize;

	std::string m_name;

	int m_RandomHumanGen;

	Hotel m_hotels;
public:
	Game();

	const bool& isRunning() const { return m_running; }

	//Setters
	

	//Functions
	void update();
	void CleanOutput();

};

