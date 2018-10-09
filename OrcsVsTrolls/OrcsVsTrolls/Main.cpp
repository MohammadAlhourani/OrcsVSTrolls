//author mohammad alhourani

#include <iostream>
#include <time.h>
#include <string>

#include "Orc.h"
#include "Troll.h"

void gameOver(bool &t_gameOver);

enum PlayerType {ORC , TROLL};

enum ACTION{ ATTACK, DEFEND, RACIAL, HEAL };

struct player
{
	int gold{ 0 };

	PlayerType playertype;
};

int main()
{
	srand((static_cast<int>(time(NULL))));

	bool gameOver = false;
	player m_player;

	std::string m_playerInput = "";
	ACTION playerAction;

	Orc theOrc;
	Troll theTroll;

	int turnCount = 0;

	std::cout << "Since ancient times Orcs and Trolls have waged war against each other." << std::endl;
	std::cout << "Orcs strong and proud fought with vicous anger and strength to topple mountains." << std::endl;
	std::cout << "The Trolls fought with unmatched wits and ancient magics." << std::endl;
	std::cout << "neither side has backed down for over 100 decades now it is time for you to join the fray!" << std::endl;

	std::cout << "now choose your destiny shall you help the Orcs or the Trolls?" << std::endl;

	std::cin >> m_playerInput;

	while (true)
	{
		if (m_playerInput == "Orcs" || m_playerInput == "Trolls")
		{
			break;
		}
		else 
		{
			std::cout << "that is not a correct input" << std::endl;
			std::cin >> m_playerInput;
		}
	}

	if (m_playerInput == "Orcs")
	{
		std::cout << "You have decided to join the mighty Orcs " << std::endl;
		m_player.playertype = PlayerType::ORC;
		m_player.gold = 50;
	}
	else
	{
		std::cout << "You have decided to join the wise Trolls " << std::endl;
		m_player.playertype = PlayerType::TROLL;
		m_player.gold = 100;
	}
	
	std::cout << "you have " << m_player.gold << " gold" << std::endl;

	while (gameOver == false)
	{
		theOrc.update();
		theTroll.update();

		if (m_player.playertype == PlayerType::ORC && theOrc.getAlive() == true)
		{

			std::cout << "ATTACK, DEFEND, ENRAGE, HEAL" << std::endl;

			std::cin >> m_playerInput;

			if (m_playerInput == "ATTACK")
			{
				playerAction = ACTION::ATTACK;
			}
			else if (m_playerInput == "DEFEND")
			{
				playerAction = ACTION::DEFEND;
			}
			else if (m_playerInput == "ENRAGE")
			{
				playerAction = ACTION::RACIAL;
			}
			else if(m_playerInput == "HEAL")
			{
				playerAction = ACTION::HEAL;
			}

			switch (playerAction)
			{
			case 0:
				std::cout << "You are attacking" << std::endl;
				theTroll.hurt(theOrc.attack());
				break;
			case 1:
				std::cout << "You are defending" << std::endl;
				theOrc.defending();
				break;
			case 2:
				std::cout << "You are now Enraged" << std::endl;
				break;
			case 3:
				std::cout << "You have healed 10 hp" << std::endl;
				break;
			default:
				break;
			}
		}

		
	}

	std::system("pause");
	return 0;
}

void gameOver(bool & t_gameOver)
{
	if (t_gameOver == true)
	{
		std::cout << "would you like to restart the game?" << std::endl;
	}
}
