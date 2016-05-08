//map.cpp
//map generates, updates and displays the game map, whihc is stored as a 80x20 array or characters
//  #=wall  " "=blanck
#include <iostream>
#include "map.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "character.h"


using namespace std;

char * Map[10][10];

map::map(int inWidth, int inHeight)
{
	srand(time(NULL)); //seed the random number generator
	width=inWidth;
	height = inHeight;
	numberOfRooms=0;
}

void map::initializeMap() // initalize Map with blanks
{
	for(int i=0; i<width; i++)
	{
		for(int j=0; j<height; j++)
		{
			Map[i][j] = " ";
		}
	}

	int firstCell = rand()%width; //place # in a random cell in the top row
	Map[0][firstCell] = "#";

	for(int k = firstCell+1; k<width; k++) //fill out top row from the first cell
	{

		if(generateRandomNumber()>3 && Map[0][k-1]=="#")
		{
			Map[0][k] = "#";
			numberOfRooms++;
		}
		else
			Map[0][k] = " ";
	}
}

void map::fillMap()
{
	//# in the map represent rooms, " " are not rooms
	//algorithm fills up the map with randomly generated rooms that touch
	//each other- no isolated rooms
	//this function will exectue until there

	for(int i =1; i<height; i++) //fill out rest of the array
	{
		for(int j = 0; j<width; j++)
		{
			if(j>0) //dont go out of array bounds!
			{
				if(generateRandomNumber()>3 && ((Map[i][j-1]=="#")||(Map[i-1][j]=="#"))) //if a cell to the top or left of the current is a room, possibly v=create a new room
				{
					  Map[i][j] = "#";
					  numberOfRooms++;
				}

			}
			else
			{
				if(generateRandomNumber()>3 && (Map[i-1][j]=="#"))
				{
					Map[i][j] = "#";
					numberOfRooms++;
				}

			}
			if(j<width-1 && i<height-1) //as above, but looking down and to the right
			{
				if(generateRandomNumber()>3 && ((Map[i][j+1]=="#") || (Map[i+1][j]=="#")))
				   {
					   Map[i][j] = "#";
					   numberOfRooms++;
				   }
			}

		}
	}
}
void map::generateMap() //fill map array with # to represent rooms that exist
{
	initializeMap();

	//# in the map represent rooms, " " are not rooms
	//algorithm fills up the map with randomly generated rooms that touch
	//each other- no isolated rooms

	for(int i =1; i<height; i++) //fill out rest of the array
	{
		for(int j = 0; j<width; j++)
		{
			if(j>0) //dont go out of array bounds!
			{
				if(generateRandomNumber()>3 && ((Map[i][j-1]=="#")||(Map[i-1][j]=="#"))) //if a cell to the top or left of the current is a room, possibly v=create a new room
				{
					  Map[i][j] = "#";
					  numberOfRooms++;
				}
				else
					Map[i][j] = " ";
			}
			else
			{
				if(generateRandomNumber()>3 && (Map[i-1][j]=="#"))
				{
					Map[i][j] = "#";
					numberOfRooms++;
				}
				else
					Map[i][j] = " ";
			}

		}
	}

	//once filled out once, repeat until we have enough rooms
	while(numberOfRooms<((width*height)/3)) //fill map until there are at least a third space filled with rooms
	{
		fillMap();
	}

}

//This is the upadate for all Objects (Characters,Items,Traps etc.) on the map
void map::mapUpdate(character * Character )
{
	//Repeat for every Character on the map. currently static 1;
	// will have to iterate through an array of characters
	for(int i = 0; i< 1; i++)
	{
		TestRoom[Character->getY()][Character->getX()] = Character->getGroundSymbol();
		Character->setGroundSymbol(TestRoom[Character->getNextY()][Character->getNextX()]);
		TestRoom[Character->getNextY()][Character->getNextX()] = Character->getSymbol();
	}

}

void map::drawMap()
{
	for(int i =0; i<height; i++)
	{
		for(int j = 0; j<width; j++)
		{
			cout << Map[i][j];
		}
		cout << endl;
	}
}

void map::printTestRoom() // TEMP
{
	for (int i = 0; i<20; i++)
	{
		for (int j = 0; j<40; j++)
		{
			cout << TestRoom[i][j];
		}
		cout << endl;
	}
}

char * map::getMapPtr()
{
	return 0;
}

//private
int map::generateRandomNumber()
{
	return (rand() % 8 + 1); //return a number between 1 and 8
}


map::~map()
{
	delete [] Map;
}
