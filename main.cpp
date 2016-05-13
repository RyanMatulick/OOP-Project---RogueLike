#include <iostream>
#include "map.h"
#include "character.h"
#include "OS_Functions.h"
#include <conio.h>
#include <cstdlib>
void TestUpdate(map * Room);

int main()
{
    system("mode 350");

    map * TestMap;
    TestMap = new map(2,3);
    //TestMap->drawMap();

	map * TestRoom;
	TestRoom = new map(80, 30);
	TestUpdate(TestRoom);
}

void TestUpdate(map * Room)
{
	character * Player = new character(10, 9, 7,50,12);
	Room->mapUpdate(Player);
	Room->printTestRoom();
	while(Player->getState() != "Dead")
	{
		Player->getTurn(Room);
		clear_screen();
		Room->mapUpdate(Player);
		cout << "Once" << endl;
		Room->printTestRoom();
		cout << Player->TurnCount << endl;
	}
}
