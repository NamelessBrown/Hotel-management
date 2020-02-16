#pragma once

#include "Human.h"

/* This is the hotel class! This stores the people, size, room, and a bool that I don't even need */
class Hotel
{
private:
	int m_roomPrice;
	std::string m_hotelName;
	unsigned int m_hotelSize;
	unsigned int m_maxHotelSize;
	unsigned int m_roomTaken;
	bool m_DoesHotelHaveRoom;

	std::vector<Human> m_people;

public:
	Hotel(int roomPrice = 50, std::string hotelName = "Hotel", int hotelSize = 10);

	//getters
	const std::string& getHotelName() { return m_hotelName; }
	const int& getRoomPrice() const { return m_roomPrice; }
	const unsigned int& getHotelSize() const { return m_hotelSize; }
	const unsigned int& getMaxHotelSize() const { return m_maxHotelSize; }
	const bool DoesHaveRoom() const;
	const std::vector<Human>& getPeoples() const { return m_people; }

	//public
	Player player;

	//setters
	void setName(std::string name);
	void setRoomPrice(int roomPrice);


	//functions
	void setHotelSize(int maxhotelSize);
	void addPeopleToHotel();
	void removePeopleFromHotel();

};

