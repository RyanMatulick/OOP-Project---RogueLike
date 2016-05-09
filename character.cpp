#include "character.h"
#include "map.h"
#include "OS_Functions.h"

#include <iostream>
#include <string>

using namespace std;
character::character(char iSymbol, int ixLocation, int iyLocation)
{
	Symbol = iSymbol;
	GroundSymbol = 'X'; // Will be placed underneath where the character is initialised

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
	case 72: // Move Up
		if (Map->getTestRoomcell(xCurrent, yNext - 1) != '#') // if the player doesn't hit a wall
		{ 
			TurnCount++;
			yNext--;
			break;
		}  
		cout << "Can't Move there" << endl; // if they hit a wall display message and get another input.
		getTurn(Map);
		break;
	case 80: // Move Down
		if (Map->getTestRoomcell(xCurrent, yNext + 1) != '#') 
		{ 
			yNext++; 
			TurnCount++;
			break;
		} 
		cout << "Can't Move there" << endl;
		getTurn(Map);
		break;

	case 75: // Move Left
		if (Map->getTestRoomcell(xNext - 1, yCurrent) != '#') 
		{
			xNext--;
			TurnCount++;
			break;
		}
		cout << "Can't Move there" << endl;
		getTurn(Map);
		break;
		
	case 77: // Move Right
		if (Map->getTestRoomcell(xNext + 1, yCurrent) != '#') 
		{
			xNext++; 
			TurnCount++;
			break;
		} 
		cout << "Can't Move there" << endl;
		getTurn(Map);
		break;
	case 'd': 
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
