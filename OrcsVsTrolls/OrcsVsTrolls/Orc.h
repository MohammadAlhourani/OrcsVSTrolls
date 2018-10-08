#ifndef ORC_H
#define ORC_H
#include "Character.h"
#include <iostream> 

class Orc : Character
{
public:

	Orc();

	void Stats();
	
	void update();

	void hurt(int t_damage);

	void heal();

	int attack();

	void enrage();

	int getHealth();

private:

	int damage = 0;

	bool angery = false;
	
};

#endif