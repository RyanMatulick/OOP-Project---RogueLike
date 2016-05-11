#include <iostream>
#include "room.h"
#include "map.h"

//#include "OS_Functions.h" // getch and
#include "map.cpp"
#include "room.cpp"


using namespace std;

int main()
{

	map * theMap;
	theMap = new map(10,10);
	theMap->generateMap();
	theMap->drawMap();

    rMap[1][6]->drawRoom();

	/* getKey Example
	//char key = getKey();
	//cout << "You inputted: " << key << endl;
	//Test Map
	cout << "Before Test Map" << endl;
	map * testMap;
	testMap = new map(10, 10);
	testMap->printTestMap();
	cout << "After TestMap" <<endl;
    */

	//getKey(); // needed on VS to see final output, pauses until keypress
}
