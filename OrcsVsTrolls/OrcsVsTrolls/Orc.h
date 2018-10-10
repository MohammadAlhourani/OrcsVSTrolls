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

	void defending();

	bool getDefence();

	void heal();

	int attack();

	void enrage();

	bool getAlive();

	bool getEnrage();

	void death();

	void reset();

private:

	int damage = 0;

	bool angery = false;

	int enrageTimer = 0;
	
};

#endif