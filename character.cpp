#include "character.h"
#include "map.h"
#include "OS_Functions.h"

#include <iostream>
#include <string>

using namespace std;
character::character(int iSymbol, int ixLocation, int iyLocation, int iHealth, int iAttackD)
{
	Symbol = iSymbol;
	GroundSymbol = 100; // Will be placed underneath where the character is initialised
    Health = iHealth;
    AttackD = iAttackD;


	xNext = ixLocation;
	xCurrent = ixLocation;
	yNext = iyLocation;
	yCurrent = iyLocation;
	TurnCount = 0;
	CharacterState = "Alive";

}


void character::getTurn(map *Map) // will change to room Need to put in a player class
{
	char Move = getKey();
	yCurrent = yNext;
	xCurrent = xNext;
	switch (Move)
	{
	case 'w': // Move Up
		if (Map->getTestRoomcell(xCurrent, yNext - 1) != 2 && yNext >0) // if the player doesn't hit a wall
		{
			TurnCount++;
			yNext--;
			break;
		}
		cout << "Can't Move there" << endl; // if they hit a wall display message and get another input.
		getTurn(Map);
		break;
	case 's': // Move Down
		if (Map->getTestRoomcell(xCurrent, yNext + 1) != 2 && yNext <Map->getHeight()-1)
		{
			yNext++;
			TurnCount++;
			break;
		}
		cout << "Can't Move there" << endl;
		getTurn(Map);
		break;

	case 'a': // Move Left
		if (Map->getTestRoomcell(xNext - 1, yCurrent) != 2 && xNext > 0)
		{
			xNext--;
			TurnCount++;
			break;
		}
		cout << "Can't Move there" << endl;
		getTurn(Map);
		break;

	case 'd': // Move Right
		if (Map->getTestRoomcell(xNext + 1, yCurrent) != 2 && xNext <Map->getWidth()-1)
		{
			xNext++;
			TurnCount++;
			break;
		}
		cout << "Can't Move there" << endl;
		getTurn(Map);
		break;
	case 'p':
		CharacterState = "Dead";
		break;

	default: break;
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



character::~character()
{
}
