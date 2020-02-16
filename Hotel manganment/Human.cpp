#include "Human.h"

Human::Human()
{
	unsigned name_chance = rand() % m_names.size();

	m_name = m_names[name_chance];

	m_money = rand() % 1500 + 1; //This will make everyone money dymanic..
} 

int Human::removeMoney(int removeMoney)
{
	 
	m_money -= removeMoney;


	if (m_money < 0)
	{
		std::cout << m_name << " had to sell both Kidneys to repay you. Thanks Obama. \n";
	}


	return m_money;
}
