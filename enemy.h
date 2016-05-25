#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"

class enemy :public character
{
private:

public:
	enemy(int Symbol, int * Pos,int Health, int AttackD);
	~enemy();

};

#endif // !enemy
