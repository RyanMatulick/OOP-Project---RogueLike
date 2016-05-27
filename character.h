#ifndef CHARACTER_H
#define CHARACTER_H
#include "map.h"
#include "item.h"
class potion;
#include <string>
#include <iostream>

using namespace std;

class character
{
protected:

	int Symbol; // Symbol of Character
	int GroundSymbol; // saves the symbol of the space the player is about to move onto;

	int xCurrent; // Current X position
	int yCurrent; // Current Y position
	int xNext; // X position to move too
	int yNext; // Y position to move too

	int Health; // Characters Health
	int AttackD; // Characters Attack Damage

	item * Inventory[10];

	string CharacterState; // Characters state
	string Type; // Type of Character

	void Attack(character *Target); // Basic Attack Function
	bool Move(map *Map,character **Character,int inputX, int inputY,int Target); // Move or Attack

	enum MOVES
	{
		UP_INTERACTION,
		DOWN_INTERACTION,
		LEFT_INTERACTION,
		RIGHT_INTERACTION,
		NO_MOVE,
		USE_ITEM,
		PLACE_ITEM,
	};

	int virtual Getinput(character *Player) = 0;

	void useItem();     //use an item in your inventory
	void placeItem();   //drop an item in your inventory
	bool pickupItem(int iSpot, int iItemNo);

public:

	character(int Symbol, int * Pos,int Health, int AttackD,string Type);
    void getTurn(map* Map, character **Character); // change to room


	string getState(); // get Characters State
	char getSymbol(); // get Characters Symbol
	char getGroundSymbol(); // get symbol underneath the player
	int getX(); // get Characters x coordinate
	int getY(); // get Characters y coordinate
	int getNextX(); // get Characters x coordinate
	int getNextY(); // get Characters y coordinate
	int getHealth(); // get Characters Health
	int getAttackD();


	void setState(string State);
	void setSymbol(int Symbol);
	void setGroundSymbol(char GSymbol);
	void setX(int ixLocation);
	void setY(int ixLocation);
	void setNextX(int ixLocation);
	void setNextY(int ixLocation);

	void setAttackD(int extraAttack);

	void setHealth(int newHealth);  //externally update the player health.


	int TurnCount;
	~character();


};


#endif // !CHARACTER_H
