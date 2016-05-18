#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"

class enemy :public character
{
private:

public:
	enemy(int Symbol, int xCurrent, int yCurrent,int Health, int AttackD);
	~enemy();

};

#endif // !enemy
