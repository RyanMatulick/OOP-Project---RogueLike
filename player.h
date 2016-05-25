#ifndef PLAYER_H
#define PLAYER_H
#include "item.h"

#include "character.h"

class player :public character
{
private:


public:
    player(int Symbol, int xCurrent, int yCurrent,int Health, int AttackD);
    ~player();

    void displayInventory();


};

#endif // !player
