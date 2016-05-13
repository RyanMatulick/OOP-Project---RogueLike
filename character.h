#ifndef CHARACTER_H
#define CHARACTER_H
class map;
#include <string>

using namespace std;

class character
{
protected:

	int Symbol;
	int GroundSymbol; // saves the symbol of the space the player is about to move onto;

	int xCurrent;
	int yCurrent;
	int xNext;
	int yNext;

	int Health;
	int AttackD;

	string CharacterState;


public:
	character(int Symbol, int xCurrent, int yCurrent,int Health, int AttackD);
	virtual void getTurn(map* Map); // change to room

	string getState();
	char getSymbol();
	char getGroundSymbol();
	int getX(); // get Characters x coordinate
	int getY(); // get Characters y coordinate
	int getNextX(); // get Characters x coordinate
	int getNextY(); // get Characters y coordinate

	void setState(string State);
	void setGroundSymbol(char GSymbol);
	void setX(int ixLocation);
	void setY(int ixLocation);
	void setNextX(int ixLocation);
	void setNextY(int ixLocation);


	int TurnCount;
	~character();


};


#endif // !CHARACTER_H
