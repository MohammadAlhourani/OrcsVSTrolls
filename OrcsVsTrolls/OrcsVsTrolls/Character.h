#ifndef CHARACTER_H
#define CHARACTER_H

class Character
{
public:
	Character();
	~Character();

	virtual void Stats();

private:

	
protected:

	bool alive = true;

	int health;

	int critChance;

	int strength;

	int mana;
};



#endif // !CHARACTER_H


