#include <iostream>
#include "map.h"
#include "character.h"
#include "OS_Functions.h" // getch and 
//#include "map.cpp"

using namespace std;
void TestUpdate(map * Room);


int main()
{
	/*
	map * theMap;
	theMap = new map(10,10);
	theMap->generateMap();
	theMap->drawMap();
	*/


	
	//Test Map
	//cout << "Before Test Room" << endl;
	map * TestRoom;
	TestRoom = new map(10, 10);
	//TestRoom->printTestRoom();
	//cout << "After Test Room" <<endl;

	//getKey();
	
	TestUpdate(TestRoom);
	
	getKey(); // needed on VS to see final output, pauses until keypress
	//getKey();
}

void TestUpdate(map * Room)
{
	
	//cout << "Before Test Move" << endl;
	
	character * Player = new character('@', 0, 0);
	Room->mapUpdate(Player);
	Room->printTestRoom();
	for (int i = 0; i < 30; i++)
	{
		Player->getTurn();
		Room->mapUpdate(Player);
		clear_screen();
		Room->printTestRoom();
		
	}
	//cout << "After Test Move" << endl;
	
}