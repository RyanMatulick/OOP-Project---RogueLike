#ifndef ENEMY_H
#define ENEMY_H

#include <string>
class map; // forward declaration
using namespace std;

class enemy :public character
{
private:

public:
	enemy(int Symbol, int xCurrent, int yCurrent,int Health, int AttackD);
	void getTurn(map* Map); // change to room

	~enemy();

};


#endif // !enemy
