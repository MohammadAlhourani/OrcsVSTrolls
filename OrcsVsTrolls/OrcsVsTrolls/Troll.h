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

	void defending();

	bool getDefence();

	bool getAlive();

	void focus();

	void reset();

	void death();

private:
	
	int damage = 0;

	bool focused = false;

	bool defence = false;

	int focusTimer = 0;
};
#endif

