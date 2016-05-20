#include "character.h"
#include "map.h"
#include "OS_Functions.h"

#include <iostream>
#include <string>

using namespace std;
character::character(int iSymbol, int ixLocation, int iyLocation, int iHealth, int iAttackD)
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

}


void character::getTurn(map *Map) // will change to room Need to put in a player class
{

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
