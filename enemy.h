#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"

class enemy :public character
{
private:

public:
	enemy(int Symbol, int * Pos,int Health, int AttackD);
	int Getinput(character *Player);
	int LastMove = -1;
	int LastTurn = -1;
	~enemy();

};

#endif // !enemy
