//author mohammad alhourani

#include <iostream>
#include <time.h>
#include <string>

#include "Orc.h"
#include "Troll.h"


enum PlayerType {ORC , TROLL};

enum ACTION{ ATTACK, DEFEND, RACIAL, HEAL };

struct player
{
	int gold{ 0 };

	PlayerType playertype;
};

void GameOver(bool &t_gameOver, player &t_type, Orc &t_Orc, Troll &t_Troll, std::string &t_playerInput);

int main()
{
	srand((static_cast<int>(time(NULL))));

	bool gameOver = false;
	bool win = false;
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

	if (m_player.playertype == PlayerType::ORC)
	{
		std::cout << "An enemy Troll Attacks!!" << std::endl;
	}
	else
	{
		std::cout << "An enemy Orc Attacks!!" << std::endl;
	}
	
	std::cout << "you have " << m_player.gold << " gold" << std::endl;

	while (gameOver == false && win == false)
	{
		
		theOrc.update();
		theTroll.update();

		if (m_player.playertype == PlayerType::ORC && theTroll.getAlive() == false)
		{
			win = true;
		}
		else if (m_player.playertype == PlayerType::TROLL && theOrc.getAlive() == false)
		{
			win = true;
		}

		 GameOver(gameOver, m_player,theOrc,theTroll,m_playerInput);

		//IF THE PLAYER IS A ORC
		if (m_player.playertype == PlayerType::ORC && theOrc.getAlive() == true && theTroll.getAlive() == true)
		{
			std::cout << "you have " << theOrc.getHealth() << " health" << std::endl;
			std::cout << "you have " << theOrc.getMana() << " Mana" << std::endl;

			if (theTroll.getDefence() == true)
			{
				std::cout << "the Troll braces itself" << std::endl;
			}

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
				

				if (theTroll.getDefence() == true)
				{
					theOrc.hurt(theTroll.attack());

					std::cout << "the Troll retaliates!" << std::endl;
					std::cout << "The Troll hits you for " << theTroll.attack();
				}
				else
				{
					theTroll.hurt(theOrc.attack());
					std::cout << "you deal " << theOrc.attack() << " damage" << std::endl;
				}

				break;
			case 1:
				std::cout << "You are defending" << std::endl;
				theOrc.defending();
				break;
			case 2:
				std::cout << "You are now Enraged" << std::endl;
				theOrc.enrage();
				break;
			case 3:
				std::cout << "You have healed 10 hp" << std::endl;
				theOrc.heal();
				break;
			default:
				break;
			}
		}

		//IF THE PLAYER IS A TROLL
		if (m_player.playertype == PlayerType::TROLL && theTroll.getAlive() == true && theOrc.getAlive() == true)
		{
			std::cout << "you have " << theTroll.getHealth() << " health" << std::endl;
			std::cout << "you have " << theTroll.getMana() << " Mana" << std::endl;

			if (theOrc.getDefence() == true)
			{
				std::cout << "The Orc braces itself" << std::endl;
			}

			std::cout << "ATTACK, DEFEND, FOCUS, HEAL" << std::endl;

			std::cin >> m_playerInput;

			if (m_playerInput == "ATTACK")
			{
				playerAction = ACTION::ATTACK;
			}
			else if (m_playerInput == "DEFEND")
			{
				playerAction = ACTION::DEFEND;
			}
			else if (m_playerInput == "FOCUS")
			{
				playerAction = ACTION::RACIAL;
			}
			else if (m_playerInput == "HEAL")
			{
				playerAction = ACTION::HEAL;
			}

			switch (playerAction)
			{
			case 0:
				std::cout << "You are Attacking" << std::endl;
				

				if (theOrc.getDefence() == true)
				{
					theOrc.hurt(theTroll.attack());

					std::cout << "the Orc retaliates!" << std::endl;
					std::cout << "The Orc hits you for " << theOrc.attack();
				}
				else
				{
					theOrc.hurt(theTroll.attack());
					std::cout << "you deal " << theTroll.attack() << " damage" << std::endl;
				}

				break;
			case 1:
				std::cout << "You are Defending" << std::endl;
				theTroll.defending();
				break;
			case 2:
				std::cout << "You are now Focused" << std::endl;
				theTroll.focus();
				break;
			case 3:
				std::cout << "You have Healed 10 hp" << std::endl;
				theTroll.heal();
				break;
			default:
				break;
			}
		}

		//if the enemy is a orc
		if (m_player.playertype != PlayerType::ORC && theOrc.getAlive() == true)
		{
			switch (rand() % 4)
			{
			case 0:
				std::cout << "The Orc attacks!" << std::endl;
				

				if (theTroll.getDefence() == true)
				{
					theOrc.hurt(theTroll.attack());

					std::cout << "You retaliate!" << std::endl;
					std::cout << "you hit the Orc for " << theTroll.attack();
				}
				else
				{
					theTroll.hurt(theOrc.attack());
					std::cout << "the Orc deals " << theOrc.attack() << " damage to you" << std::endl;
				}

				break;
			case 1:
				theOrc.defending();
				break;
			case 2:
				
				std::cout << "the Orc is now Enraged" << std::endl;
				theOrc.enrage();
				break;
			case 3:
				std::cout << "The Orc licks its wounds" << std::endl;
				theOrc.heal();
				break;
			default:
				break;
			}
		}
		
		//if the enemy is a troll
		if (m_player.playertype != PlayerType::TROLL && theTroll.getAlive() == true)
		{
			switch (rand() % 4)
			{
			case 0:
				std::cout << "The Troll attacks!" << std::endl;


				if (theOrc.getDefence() == true)
				{
					theTroll.hurt(theOrc.attack());

					std::cout << "You retaliate!" << std::endl;
					std::cout << "you hit the Troll for " << theTroll.attack();
				}
				else
				{
					theOrc.hurt(theTroll.attack());
					std::cout << "the Troll deals " << theTroll.attack() << " damage to you" << std::endl;
				}

				break;
			case 1:
				theTroll.defending();
				break;
			case 2:
				std::cout << "the Troll is now Focused" << std::endl;
				theTroll.focus();
				break;
			case 3:
				std::cout << "The Troll seals its wounds with magical energy" << std::endl;
				theTroll.heal();
				break;
			default:
				break;
			}
		}
	}
	
	if (m_player.playertype == PlayerType::ORC && theTroll.getAlive() == false)
	{
		std::cout << "Well Done the Troll has been defeated!" << std::endl;
	}
	else if (m_player.playertype == PlayerType::TROLL && theOrc.getAlive() == false)
	{
		std::cout << "Well Done the Orc has been defeated!" << std::endl;
	}
	
	std::system("pause");
	return 0;
}

void GameOver(bool & t_gameOver, player &t_type, Orc &t_Orc, Troll &t_Troll, std::string &t_playerInput)
{
	
	if (t_type.playertype == PlayerType::ORC && t_Orc.getAlive() == false)
	{
		t_gameOver = true;
	}

	if (t_type.playertype == PlayerType::TROLL && t_Troll.getAlive() == false)
	{
		t_gameOver = true;
	}

	if (t_gameOver == true )
	{
		std::cout << "would you like to restart the game?" << std::endl;

		std::cin >> t_playerInput;

		if (t_playerInput == "YES")
		{
			t_Orc.reset();
			t_Troll.reset();
		}
	}
}
