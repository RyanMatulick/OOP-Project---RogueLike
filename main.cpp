#include <iostream>
#include "map.h"
#include "character.h"
#include "OS_Functions.h"


void TestUpdate(map * Room);

int main()
{
    map * TestMap;
    TestMap = new map(2,3);
	map * TestRoom;
	TestMap->drawMap();
	TestRoom = new map(10, 10);
	TestUpdate(TestRoom);
}

void TestUpdate(map * Room)
{
	character * Player = new character('@', 0, 0);
	Room->mapUpdate(Player);
	Room->printTestRoom();
	while(Player->getState() != "Dead")
	{
		Player->getTurn(Room);
		Room->mapUpdate(Player);
		clear_screen();
		Room->printTestRoom();
		cout << Player->TurnCount << endl;
	}
}
