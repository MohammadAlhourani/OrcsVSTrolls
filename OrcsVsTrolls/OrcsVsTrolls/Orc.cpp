#include "Orc.h"

Orc::Orc()
{

	alive = true;

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
	health - t_damage;
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
	}
	else
	{
		damage = strength;
	}
	
	
	return damage;
}
