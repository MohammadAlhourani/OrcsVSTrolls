#include "Troll.h"

Troll::Troll()
{
	Stats();

	alive = true;
}


Troll::~Troll()
{
}

void Troll::Stats()
{
	health = 80;

	mana = 80;

	strength = 5;

	critChance = 10; // percent
}

void Troll::update()
{
	if (health <= 0)
	{
		alive = false;
	}
}

void Troll::hurt(int t_damage)
{
	health -= t_damage;
}

void Troll::heal()
{
	if (mana > 0)
	{
		health += 10;
	}
	else
	{
		std::cout << "out of mana!" << std::endl;
	}
}

int Troll::attack()
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

int Troll::getHealth()
{
	return health;
}

void Troll::focus()
{
	mana += 20;
}
