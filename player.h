#ifndef PLAYER_H
#define PLAYER_H
class map;
#include <string>

using namespace std;

class player :public character
{
private:

public:
	player(int Symbol, int xCurrent, int yCurrent,int Health, int AttackD);
	void getTurn(map* Map); // change to room

	~player();

};


#endif // !player
