#include "Orc.h"

Orc::Orc()
{
	Stats();

	alive = true;
}

void Orc::Stats()
{
	health = 100;

	mana = 50;

	strength = 10;

	critChance = 5; // percent 
}

void Orc::update()
{
	death();

	if (defence == true)
	{
		defence = false;
	}

	if (angery == true && enrageTimer > 2)
	{
		enrageTimer++;
	}
	else if (enrageTimer == 2)
	{
		angery = false;
		enrageTimer = 0;
	}
}

void Orc::hurt(int t_damage)
{
	health = health - t_damage;

	switch (rand() % 3 + 1)
	{
		case 1:
		{
			std::cout << "The Orc : uuuuuuuuurrggghhhh" << std::endl;
			break;
		}
		case 2:
		{
			std::cout << "The Orc : oooooooogghhh" << std::endl;
			break;
		}
		case 3:
		{
			std::cout << "The Orc : oof" << std::endl;
			break;
		}
		default:
		{
			break;
		}

	}

}

void Orc::defending()
{	
	defence = true;
}

bool Orc::getDefence()
{
	return defence;
}

void Orc::heal()
{
	if (mana > 0)
	{
		health + 10;
		mana -= 10;
	}
	else
	{
		std::cout << "out of mana!" << std::endl;
	}
}

int Orc::attack()
{
	damage = strength;

	if ((rand() % 100 + 1) <= critChance)
	{
		damage = strength * 2;

		if (angery == true)
		{
			damage = strength * 4;
		}

		std::cout << "critical hit!" << std::endl;
	}

	if (angery == true)
	{
		damage = strength * 2;
	}
	
	return damage;
}

void Orc::enrage()
{
	if (angery == false)
	{
		angery = true;
	}
}

bool Orc::getAlive()
{
	return alive;
}

bool Orc::getEnrage()
{
	return angery;
}

void Orc::death()
{
	if (health <= 0)
	{
		std::cout << "The Orc has been defeated!!" << std::endl;

		alive = false;
	}
}

void Orc::reset()
{
	health = 100;

	mana = 50;

	alive = true;

	angery = false;
}
