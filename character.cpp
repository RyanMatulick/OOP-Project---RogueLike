#include "character.h"
#include "map.h"
#include "OS_Functions.h"
#include "stdlib.h" // for rand
#include <iostream>
#include <string>

using namespace std;
character::character(int iSymbol, int ixLocation, int iyLocation, int iHealth, int iAttackD,string iType)
{
	Symbol = iSymbol;
	GroundSymbol = 1; // Will be placed underneath where the character is initialised
    Health = iHealth;
    AttackD = iAttackD;


	xNext = ixLocation;
	xCurrent = ixLocation;
	yNext = iyLocation;
	yCurrent = iyLocation;
	TurnCount = 0;
	CharacterState = "Alive";
	Type = iType;

}


void character::getTurn(map *Map, character **Characters) // will change to room Need to put in a player class
{
	MOVES Moves = NO_MOVE;
	int Input;
	int Target;
	if(Type == "PLAYER")
	{
		Target = 20; // HARDCODED current enemy
		Input = int(getKey());
		switch(Input)
		{
			case 119: Moves = UP_INTERACTION; break;   // ascii 'w'
			case 115: Moves = DOWN_INTERACTION; break; // ascii 's'
			case 97:  Moves = LEFT_INTERACTION; break; // ascii 'a'
			case 100: Moves = RIGHT_INTERACTION; break;// ascii 'd'
			default: break;
		}
	}
	else if(Type == "ENEMY")
	{
		Target = 10; // HARDCODED current player
		Input = rand() % 4 + 1;
		//Input = 5;
		switch(Input)
		{
			case 1: Moves = UP_INTERACTION; break;
			case 2: Moves = DOWN_INTERACTION; break;
			case 3:  Moves = LEFT_INTERACTION; break;
			case 4: Moves = RIGHT_INTERACTION; break;
			default: break;
		}
	}
	yCurrent = yNext;
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
	case NO_MOVE:  // If Invalid key is pressed, get another.
		cout <<"Invalid Key" << endl;
		//getTurn(Map,Characters);
		break;
	}
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


void character::setState(string State)
{
	CharacterState = State;
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

//-------------------------------------------------------------------------------------------------

void character::Attack(character *Target)
{
	Target->Health -= AttackD;
}


bool character::Move(map *Map,character **Characters,int inputX, int inputY, int Target)
{
	if (Map->getTestRoomcell(inputX, inputY) < 2) // if the player doesn't hit a wall
	{
		TurnCount++; // we will either move or attack;
		if(Map->getTestRoomcell(inputX, inputY) == Target) // if the next move is onto an enemy
		{
			for (int i = 0; i< 2; i++) // check all charcters in array to find the one that is in target square
			{
				if (Characters[i]->getX() == inputX)
				{
					if(Characters[i]->getY() == inputY)
					{
						Attack(Characters[i]);
						return false; // do not move the player
					}
				}
			}
		}
		else
		{
			return true; // Move Player
		}

	}
	else
	{
		cout << "Can't Move there" << endl; // if they hit a wall display message
		getTurn(Map,Characters); //  get another input, as previous was un-playable
		return false; // do not move the player
	}

}


character::~character()
{
}
