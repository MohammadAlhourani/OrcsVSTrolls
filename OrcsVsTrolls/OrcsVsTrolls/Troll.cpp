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
	death();

	if (defence == true)
	{
		defence = false;
	}

	if (focused == true && focusTimer > 2)
	{
		focusTimer++;
	}
	else if (focusTimer == 2)
	{
		focused = false;
	}
}

void Troll::hurt(int t_damage)
{
	health = health - t_damage;

	switch (rand() % 3 + 1)
	{
	case 1:
	{
		std::cout << "The Troll : aaaaaaaarrggghhhh" << std::endl;
		break;
	}
	case 2:
	{
		std::cout << "The Troll : ackkh" << std::endl;
		break;
	}
	case 3:
	{
		std::cout << "The Troll : my disappointment is imeasurable and my day is ruined" << std::endl;
		break;
	}
	default:
	{
		break;
	}

	}
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

		std::cout << "critical hit!" << std::endl;
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

int Troll::getMana()
{
	return mana;
}

void Troll::defending()
{
	defence = true;
}

bool Troll::getDefence()
{
	return defence;
}

bool Troll::getAlive()
{
	return alive;
}

void Troll::focus()
{
	if (focused == false)
	{
		mana += 20;

		focused = true;
	}
}

void Troll::reset()
{
	alive = true;

	health = 80;

	mana = 80;

	focused = false;
}

void Troll::death()
{
	if (health <= 0)
	{
		std::cout << "The Troll has been defeated!!" << std::endl;

		alive = false;
	}
}
