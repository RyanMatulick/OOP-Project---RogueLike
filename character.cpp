#include "character.h"
#include "OS_Functions.h"
#include<iostream>
character::character(char iSymbol, int ixLocation, int iyLocation)
{
	Symbol = iSymbol;
	GroundSymbol = 'X';

	xNext = ixLocation;
	xCurrent = ixLocation;
	yNext = iyLocation;
	yCurrent = iyLocation;
	
}
using namespace std;

void character::getTurn()
{
	char Move = getKey();
	yCurrent = yNext;
	xCurrent = xNext;
	//std::cout << "Player Move : " << Move << std::endl;
	switch (Move)
	{
	case 'w': // Move Up
		yNext--; 
		break; 

	case 's': // Move Down
		yNext++;
		break; 

	case 'a': // Move Left
		xNext--;
		break;
		
	case 'd': // Move Right
		xNext++;
		break;
		
	default: break;
	}
	cout << "Current Position: (" << xCurrent << "," << yCurrent << ")" << endl;
	cout << "Next Position: (" << xNext << "," << yNext << ")" << endl;
}







// getters and setters ---------------------------
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

//--------------------------------------



character::~character()
{
}
