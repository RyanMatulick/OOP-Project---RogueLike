#ifndef PLAYER_H
#define PLAYER_H
#include "item.h"
#include "character.h"

class player :public character
{
private:

public:
	player(int Symbol, int * Pos,int Health, int AttackD);
	int Getinput(character *Player);
	~player();

    void displayInventory();

};

#endif // !player
