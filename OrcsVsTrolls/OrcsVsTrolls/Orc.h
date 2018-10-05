#pragma once
#include "Character.h"
#include <iostream> 

class Orc : Character
{
public:

	Orc();

	void update();

	void hurt(int t_damage);

	void heal();

	int attack();

private:

	int damage = 0;
	
};