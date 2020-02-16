#include "Hotel.h"

Hotel::Hotel(int roomPrice, std::string hotelName, int maxHotelSize)
	:m_roomPrice(roomPrice), m_hotelName(hotelName), m_maxHotelSize(maxHotelSize)
{
	m_roomTaken = 0;
	m_DoesHotelHaveRoom = true;
	m_hotelSize = 0;
}

const bool Hotel::DoesHaveRoom() const
{
	return m_hotelSize < m_roomTaken;
}

void Hotel::setName(std::string name)
{
	m_hotelName = name;
}

void Hotel::setRoomPrice(int roomPrice)
{
	m_roomPrice = roomPrice;
}

void Hotel::setHotelSize(int maxhotelSize)
{
	m_maxHotelSize = maxhotelSize;
}

void Hotel::addPeopleToHotel()
{
	if (m_hotelSize < m_maxHotelSize && m_people.size() < m_maxHotelSize)
	{
		m_hotelSize++;
		m_people.push_back(Human());

		for (unsigned i = 0; i < m_people.size(); i++)
		{
			if (m_people[i].getMoney() > 0)
			{
				std::cout << m_people[i].getName() << " has " << m_people[i].getMoney() << " money!\n\n";

				std::cout << m_people[i].getName() << " has paid - " << m_roomPrice << "\n\n";
				player.setMoney(m_roomPrice);
				std::cout << m_people[i].getName() << " Now has - " << m_people[i].removeMoney(m_roomPrice) << "\n\n";
				std::cout << "\n\nYou have this many rooms left " << m_hotelSize << '/' << m_maxHotelSize << '\n';

				std::cout << "Press [Enter] to continue to the next person...\n";
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cin.ignore();
				system("cls");
			}
		}

	}
	else
	{
		std::cout << "Increase you size cap! \n";
		std::cout << "\n\nYou don't have any rooms left " << m_hotelSize << '/' << m_maxHotelSize << '\n';
		std::cout << "Press [Enter] to continue...\n";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin.ignore();
		system("cls");
	}

	removePeopleFromHotel();
}

void Hotel::removePeopleFromHotel()
{
	/* Human iterator that removes the right person that is below the roomPrice or 0 */

	std::vector<Human>::iterator iter;

	for (iter = m_people.begin(); iter != m_people.end();)
	{
		if (iter->getMoney() < m_roomPrice)
		{
			std::cout << iter->getName() << " has left the hotel. \n";
			iter = m_people.erase(iter);

			m_hotelSize = m_people.size();
		}
		else
		{
			iter++;
		}
	}

}
