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
	if (health <= 0)
	{
		alive = false;
	}
}

void Orc::hurt(int t_damage)
{
	health -= t_damage;
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
	if ((rand() % 100 + 1) <= critChance)
	{
		damage = strength * 2;

		if (angery == true)
		{
			damage = strength * 4;
		}
	}
	else
	{
		damage = strength;

		if (angery == true)
		{
			damage = strength * 2;
		}
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

int Orc::getHealth()
{
	return health;
}
