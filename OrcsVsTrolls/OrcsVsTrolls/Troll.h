#ifndef TROLL_H
#define TROLL_H

#include "Character.h"
#include <iostream> 

class Troll : Character
{
public:
	Troll();
	~Troll();

	void Stats();

	void update();

	void hurt(int t_damage);

	void heal();

	int attack();

	int getHealth();

	void focus();

private:
	
	int damage = 0;
};
#endif

