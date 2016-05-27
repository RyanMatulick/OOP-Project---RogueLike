#include "character.h"
#include "map.h"
#include "item.h"
#include "OS_Functions.h"
#include "potion.h"
#include "sword.h"
#include "stdlib.h" // for rand
#include <iostream>
#include <string>
#include <math.h>

using namespace std;
character::character(int iSymbol, int * Pos, int iHealth, int iAttackD,string iType)
{
	Symbol = iSymbol; // The Characters Symbol
	GroundSymbol = 1; // Will be placed underneath where the character is initialised
	Health = iHealth;  // Health of Character
	AttackD = iAttackD; // Attack Damage of Character

	xNext = Pos[1]; // X position Character is moving too
	xCurrent = Pos[1]; // Current X position of Character
	yNext = Pos[0]; // Y positoin Character is moving too
	yCurrent = Pos[0]; // Current Y position of Character
	TurnCount = 0; // How many turns the character has had
	CharacterState = "Alive"; // Current state of the Character
	Type = iType; // Type of Character e.g Player/Enemy

	//initialize an inventory full of potions and weapons
    for (int i=0; i<5; i++)
    {
        Inventory[i] = new potion("A tasty health potion", "potion", "health");
    }
    for (int i=5; i<7; i++)
    {
        Inventory[i] = new potion("A poison potion", "potion", "poison");
    }
    Inventory[7] = new sword("sharp dagger", "sword", "dagger");
    Inventory[8] = new sword("sharp dagger", "sword", "dagger");
    Inventory[9] = new sword("shiny longsword", "sword", "longsword");

}

void character::setHealth(int newHealth)
{
    Health = Health + newHealth; //add on how much new health we want
    if(Health>50) //max 50
    {
        Health=50;
    }
}

void character::useItem()
{
    cout << "enter which item you want to use" << endl;
    int itemToUse = getKey();
    cout << itemToUse << endl;

    itemToUse = itemToUse - 48;
    if(itemToUse<10 && itemToUse>-1)
    {
        Inventory[itemToUse]->use(this);
    }
    else {cout << "Not an item number!";}
}

void character::placeItem()
{
    cout << "enter which item you want to place" << endl;
    int itemToPlace = getKey();
    cout << itemToPlace << endl;

    itemToPlace = itemToPlace - 48;
    if(itemToPlace<10 && itemToPlace>-1)
    {
        Inventory[itemToPlace]->place(this);
        Inventory[itemToPlace] = new item("","","");
    }
    else {cout << "Not an item number!";}
}

void character::getTurn(map *Map, character **Characters) // will change to room Need to put in a player class
{
	MOVES Moves = NO_MOVE;
	int Input; // Player Input or Enemy Generated Input
	int Target; // Enemy of current Character
	if(Type == "PLAYER")
	{
		Target = 20; // HARDCODED current enemy
		Input = Getinput(Characters[0]);
		switch(Input)
		{
			case 119: Moves = UP_INTERACTION; break;   // ascii 'w'
			case 115: Moves = DOWN_INTERACTION; break; // ascii 's'
			case 97:  Moves = LEFT_INTERACTION; break; // ascii 'a'
			case 100: Moves = RIGHT_INTERACTION; break;// ascii 'd'
			case 105: Moves = USE_ITEM; break;         // ascii 'i'
			case 112: Moves = PLACE_ITEM; break;        // ascii 'p'
			default: break;
		}
	}
	else if(Type == "ENEMY")
	{
		Target = 10; // HARDCODED current player
		Input = Getinput(Characters[0]); // AI Turn
		switch(Input)
		{
			case 1: Moves = UP_INTERACTION; break;
			case 2: Moves = DOWN_INTERACTION; break;
			case 3: Moves = LEFT_INTERACTION; break;
			case 4: Moves = RIGHT_INTERACTION; break;
			default: break;
		}
	}
	yCurrent = yNext; // Reset From Last Turn
	xCurrent = xNext;
	switch (Moves)
	{
	case UP_INTERACTION: // Move or Attack Up
		if(Move(Map,Characters,xCurrent,yNext -1, Target)==true){yNext--;}
		break;
	case DOWN_INTERACTION: // Move or Attack Down
		if(Move(Map,Characters,xCurrent,yNext + 1, Target)==true){yNext++;}
		break;
	case LEFT_INTERACTION: // Move or Attack Left
		if(Move(Map,Characters,xNext - 1 ,yCurrent, Target)==true){xNext--;}
		break;
	case RIGHT_INTERACTION: // Move or Attack Right
		if(Move(Map,Characters,xNext + 1,yCurrent, Target)==true){xNext++;}
		break;
    case USE_ITEM:
        useItem();
        break;
    case PLACE_ITEM:
        placeItem();
        break;
	case NO_MOVE:  // If Invalid key is pressed, get another.
		cout <<"Invalid Key" << endl;
		getTurn(Map,Characters);
		break;
	}
}


int character::Getinput(character *Player)
{
	return 0;
}

// getters and setters -----------------------------------------------------------
string character::getState()
{
	return CharacterState;
}

char character::getSymbol()
{
	return Symbol;
}

char character::getGroundSymbol()
{
	return GroundSymbol;
}

int character::getX()
{
	return xCurrent;
}

int character::getY()
{
	return yCurrent;
}
int character::getNextX()
{
	return xNext;
}

int character::getNextY()
{
	return yNext;
}

int character::getHealth()
{
	return Health;
}

int character::getAttackD()
{
    return AttackD;
}


void character::setState(string State)
{
	CharacterState = State;
}
void character::setSymbol(int iSymbol)
{
	Symbol = iSymbol;
}
void character::setGroundSymbol(char iSymbol)
{
	GroundSymbol = iSymbol;
}

void character::setX(int ixLocation)
{
	xCurrent = ixLocation;
}

void character::setY(int iyLocation)
{
	yCurrent = iyLocation;
}
void character::setNextX(int ixLocation)
{
	xNext = ixLocation;
}

void character::setNextY(int iyLocation)
{
	yNext = iyLocation;
}

void character::setAttackD(int extraAttack)
{
    AttackD = AttackD + extraAttack;
}

//-------------------------------------------------------------------------------------------------

void character::Attack(character *Target) // Implement Basic Attack
{
	Target->Health -= AttackD;
}

//put an item into the inventory in place iSopt of typek iItemNo
bool character::pickupItem(int iSpot, int iItemNo)
{
    if(Inventory[iSpot]->getName()=="")//if selected slot is empty
    {
        switch(iItemNo)
        {
            case 47:
            Inventory[iSpot] = new sword("shiny longsword", "sword", "longsword");
            return true;
            break;
            case 96:
            Inventory[iSpot] = new sword("sharp dagger", "sword", "dagger");
            return true;
            break;
            case 94:
            Inventory[iSpot] = new potion("A tasty health potion", "potion", "health");
            return true;
            break;
            case 118:
            Inventory[iSpot] = new potion("A poison potion", "potion", "poison");
            return true;;
            break;
            default:
            return false;
        }

    }
    else
    {
        cout<<"this spot already contains a: " << Inventory[iSpot]->getName() <<": " <<Inventory[iSpot]->getType()<<endl;
        return false;
    }
}

bool character::Move(map *Map,character **Characters,int inputX, int inputY, int Target)
{
	// If the Character does not hit a wall, or Character of the same type
	if (Map->getTestRoomcell(inputX, inputY) != 2 && Map->getTestRoomcell(inputX, inputY) != Symbol && (Map->getTestRoomcell(inputX,inputY)!=94 && Map->getTestRoomcell(inputX,inputY)!=47 && Map->getTestRoomcell(inputX,inputY)!=96 && Map->getTestRoomcell(inputX,inputY)!=118))
	{
		TurnCount++; // we will either move or attack;
		if(Map->getTestRoomcell(inputX, inputY) == Target) // if the next move is onto an enemy
		{
			for (int i = 0; i< Map->enemyNum+1; i++) // check all charcters in array to find the one that is in the target square
			{
				if (Characters[i]->getNextY() == inputY)
				{
					if(Characters[i]->getNextX() == inputX)
					{
						Attack(Characters[i]); // Attack the Target
						return false; // do not move the Character
					}
				}
			}
			cout << "Couldnt find target" << endl; // Should never occur, but for Debugging
			return false;
		}
		else
		{
			return true; // Move Player
		}

	}
	//if the player is going over an item (94= healthpotion, 47=longsword, 96 = dagger, 118 poison potion)
	else if(Map->getTestRoomcell(inputX,inputY)==94 || Map->getTestRoomcell(inputX,inputY)==47 || Map->getTestRoomcell(inputX,inputY)==96 || Map->getTestRoomcell(inputX,inputY)==118)
	{
	    cout << "enter which inventory spot you would like to put that in" << endl;
	    int spot= getKey();
	    spot = spot -48; //convert from ascii code to actual number

	    if(spot < 10 && spot >-1) //if a valid inventory spot
        {
            if(pickupItem(spot, Map->getTestRoomcell(inputX,inputY))) //all the pickup logic (put into inventory)
            {
                //set the square under the player to be a .
                Map->setMapTile(inputY, inputX, 1);
            }
        }
        return true; //move onto item

	}

	else //player hit a wall
	{
		if (Type== "PLAYER"){cout << "Can't Move there" << endl;} // if they hit a wall display a message
		getTurn(Map,Characters); //  get another input, as previous was un-playable
		return false; // do not move the Character
	}

}


character::~character()
{
    delete Inventory;
}
