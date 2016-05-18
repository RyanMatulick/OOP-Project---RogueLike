//map.cpp
//map generates, updates and displays the game map, whihc is stored as a 80x20 array or characters
//  #=wall  " "=blanck
#include <iostream>
#include "map.h"
#include "character.h"



using namespace std;

map::map(int inWidth, int inHeight)
{
	width=inWidth;
	height = inHeight;
}

//Ryan's stuff
//This is the upadate for all Objects (Characters,Items,Traps etc.) on the map
void map::mapUpdate(character * Character)
{
	//Repeat for every Character on the map. currently static 1;
	// will have to iterate through an array of characters
	for (int i = 0; i< 1; i++)
	{
		TestRoom[Character->getY()][Character->getX()] = Character->getGroundSymbol();
		Character->setGroundSymbol(TestRoom[Character->getNextY()][Character->getNextX()]);
		TestRoom[Character->getNextY()][Character->getNextX()] = Character->getSymbol();
	}
}

char map::getTestRoomcell(int x, int y) // some form of this is needed to check for collisions and enemies in adjacent squares
{
	return TestRoom[y][x];
}

void map::printTestRoom() // TEMP Show jack the skits stuff
{
	for (int i = 0; i<height; i++)
	{
		for (int j = 0; j<width; j++)
		{
			cout << getCharacter(TestRoom[i][j]);
		}
		cout << endl;
	}
}

char map::getCharacter(int Representation)
{
    switch(Representation)
    {
        case 1: return '.'; // ground floor
        case 2: return '#'; // basic wall
        case 10: return '@'; // Player symbol
        case 20: return '&'; // Enemy Symbol
        case 100: return 'X'; // player start pos
        default: return '?'; // has not been defined yet
    }
}

int map::getWidth()
{
    return width;
}
int map::getHeight()
{
    return height;
}

map::~map()
{
}
