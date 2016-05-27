#ifndef CHARACTER_H
#define CHARACTER_H
<<<<<<< HEAD
class map;
class item;
#include "item.h"
#include "potion.h"
=======
#include "map.h"
#include "item.h"
class potion;
>>>>>>> refs/remotes/origin/master
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
<<<<<<< HEAD

	string CharacterState;
=======
>>>>>>> refs/remotes/origin/master

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
<<<<<<< HEAD
private:
    bool pickupItem(int iSpot, int iItemNo);
=======
	
	int virtual Getinput(character *Player);
>>>>>>> refs/remotes/origin/master

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
<<<<<<< HEAD
	int getHealth();
	int getAttackD();

	void setState(string State);
	void setGroundSymbol(int iSymbol);
=======
	int getHealth(); // get Characters Health
	int getAttackD();


	void setState(string State);
	void setSymbol(int Symbol);
	void setGroundSymbol(char GSymbol);
>>>>>>> refs/remotes/origin/master
	void setX(int ixLocation);
	void setY(int ixLocation);
	void setNextX(int ixLocation);
	void setNextY(int ixLocation);
	void setAttackD(int extraAttack);

	void setHealth(int newHealth);  //externally update the player health.

<<<<<<< HEAD
	void useItem();     //use an item in your inventory
	void placeItem();   //drop an item in your inventory
=======
	void setAttackD(int extraAttack);

	void setHealth(int newHealth);  //externally update the player health.

	void useItem();     //use an item in your inventory
	void placeItem();   //drop an item in your inventory

>>>>>>> refs/remotes/origin/master

	int TurnCount;
	~character();


};


#endif // !CHARACTER_H
