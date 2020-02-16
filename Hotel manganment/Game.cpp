#include "Game.h"

Game::Game()
{
	m_running = true;
	m_command = 'a';
	m_roomPrice = 35;
	m_RandomHumanGen = 0;
	m_increaseRoomSize = 30;
	m_upgradeHotelSize = (200 * 4) / 2;

	std::cout << "Enter the name of your hotel! \n";
	//std::cin.clear();
	//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, m_name);

	std::cout << "Enter the price of the hotel room! \n";
	std::cin >> m_roomPrice;

	while (std::cin.fail())
	{
		std::cin.clear();
		CleanOutput();

		std::cout << "Try again - ";

		std::cin >> m_roomPrice;
	}

	m_hotels.setName(m_name);
	m_hotels.setRoomPrice(m_roomPrice);
	CleanOutput();
}

void Game::update()
{
	std::cout << "Hotel Management - ";

	std::cin >> m_command;

	while (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cin >> m_command;
	}

	/* Handles user input */
	switch (m_command)
	{
	case 'h':
	case 'H':
		if (m_hotels.player.getMoney() >= m_upgradeHotelSize)
		{
			m_hotels.setHotelSize(m_increaseRoomSize);
			m_increaseRoomSize += 10;
			std::cout << "Your room size is now - " << m_increaseRoomSize << '\n';
			m_hotels.player.removeMoney(m_upgradeHotelSize);
			m_upgradeHotelSize = (200 * m_increaseRoomSize) / 20;
		}
		else
		{
			std::cout << "You need -> " << m_upgradeHotelSize << ". You have -> " << m_hotels.player.getMoney() << '\n';
		}

		CleanOutput();
		break;
	case 't':
	case 'T':
		m_RandomHumanGen = rand() % 2;

		if (m_RandomHumanGen == rand() % 2)
		{
			
			m_hotels.addPeopleToHotel();
			
		}
		else
		{
			std::cout << "\tShool is in session. No one seems to be entering the hotel...\n";
		}
		CleanOutput();
		break;
	case 'c':
	case 'C':
		std::cout << "Your room price is -> " << m_hotels.getRoomPrice() << '\n';
		std::cout << "How much would you like to change it by? Enter here: ";
		std::cin >> m_roomPrice;

		while (std::cin.fail())
		{
			std::cin.clear();
			CleanOutput();

			std::cout << "Try again - ";

			std::cin >> m_roomPrice;
		}

		m_hotels.setRoomPrice(m_roomPrice);

		std::cout << "Your room prices are now -> " << m_roomPrice << '\n';
		CleanOutput();
		break;
	case 'n':
	case 'N':
		std::cout << "Your name is -> " << m_hotels.getHotelName() << '\n';
		std::cout << "What's your new hotel name? Enter here: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::getline(std::cin, m_name);

		std::cout << "Your new and improved hotel name is -> " << m_name << '\n';
		m_hotels.setName(m_name);
		CleanOutput();
		break;
	case 'P':
	case 'p':
		std::cout << "\tCOMMANDS!\n"
			<< "Press 'Q' to quit.\n"
			<< "Press 'T' to wait for people.\n"
			<< "Press 'H' to increase the size of your hotel.\n"
			<< "Press 'C' to change your room price!.\n"
			<< "Press 'N' to change your hotel name!.\n"
			<< "\n\nYour stats are as follows! \n\n";
		std::cout << "Hotel size is = " << m_hotels.getMaxHotelSize() << ". To upgrade it you will need -> " << m_upgradeHotelSize << '\n'
			<< "The money you own is = " << m_hotels.player.getMoney() << '\n' << "Your room pricing is -> " << m_hotels.getRoomPrice() << '\n';

		std::cout << "\n\nResidents of " << m_hotels.getHotelName() << " - " << '\n';

		for (const auto& e : m_hotels.getPeoples())
		{
			std::cout << '\t' << e.getName() << " has " << '$' << e.getMoney() << '\n';
		}

		CleanOutput();
		break;
	case 'q':
	case 'Q':
		m_running = false;
		break;
	default:
		std::cout << "ERROR::GAME::UPDATE NOT A COMMAND! \n";
		CleanOutput();
		break;
	}

}

//I have this cleanOutput function for clearing the data on screen. I have this here because I use the stuff in the body a lot
void Game::CleanOutput()
{
	std::cout << "Press [Enter] to continue...\n";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.ignore();
	system("cls");
}
