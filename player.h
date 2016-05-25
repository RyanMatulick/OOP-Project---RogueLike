#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"

class player :public character
{
private:

public:
    player(int Symbol, int * Pos,int Health, int AttackD);
    ~player();

};

#endif // !player
