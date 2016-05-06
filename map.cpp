//map.cpp
//map generates, updates and displays the game map, whihc is stored as a 80x20 array or characters
//  #=wall  " "=blanck

#include "map.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

char * Map[80][20];

map::map()
{
    srand(time(NULL)); //seed the random number generator
}

void map::initializeMap() //fill map array with .
{
    for(int i =0; i<20; i++)
    {
        for(int j = 0; j<80; j++)
        {
            Map[i][j] = ".";
        }
    }
}

void map::generateMap()
{
    initializeMap();
}

void map::mapUpdate()
{

}

void map::drawMap()
{
    for(int i =0; i<20; i++)
    {
        for(int j = 0; j<80; j++)
        {
            cout << Map[i][j];
        }
        cout << endl;
    }
}

char * map::getMapPtr()
{

}

//private
int map::generateRandomNumber()
{
    return (rand() % 8 + 1); //return a number between 1 and 8
}



map::~map()
{

}
