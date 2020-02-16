#pragma once

#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <sstream>

class Human
{
private:
	std::vector<std::string> m_names { "Joe", "Bob", "Frank", "Billy", "Adien", "NamelessBrown", "Mia", "Madison", "Chole", "Orion", "Marlon", "Chris", "Reggie", "CodePrime8", "TheFatRat", "Laura_Brehm", "Jonathon_Hills", "Mr.Butts", "Physical_Gamerz", "Mr.Miss", "Ariana", "Squidward", "Spongeboob", "Patrick", "Sandy", "Miss.Puff" };
	std::string m_name;
	int m_money;
public:
	Human();

	//getters
	const std::string& getName() const { return m_name; }
	const int& getMoney() const { return m_money; }

	//Some setters also returns money
	int removeMoney(int removeMoney);

	//functions
	
};

struct Player
{
private:
	int m_money = 5;
public:
	//setters
	void setMoney(int plusMoney) { m_money += plusMoney; }
	void removeMoney(int removeMoney) { m_money -= removeMoney; }

	//getter
	const int& getMoney() const { return m_money; }
}; 

