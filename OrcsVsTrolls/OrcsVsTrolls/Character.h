#pragma once

class Character
{
public:
	Character();
	~Character();

private:

	
protected:

	bool alive = true;

	int health;

	int critChance;

	int strength;

	int mana;
};

Character::Character()
{
}

Character::~Character()
{
}


