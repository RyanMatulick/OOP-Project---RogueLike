#include <iostream>
#include "map.h"
#include "character.h"
#include "player.h"
#include "enemy.h"
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
	player * Player = new player(10, 9, 7,50,12);
	enemy * Enemy = new enemy(10, 1, 1,50,12);
	character * CArray[2];
	CArray[0] = Player;
	CArray[1] = Enemy;

	for (int i = 0; i<2; i++)
    {
        Room->mapUpdate(CArray[i]);
    }
    Room->printTestRoom();

    while(CArray[0]->getState() != "Dead")
    {
        for (int i = 0; i<2; i++)
        {
            CArray[i]->getTurn(Room);
            clear_screen();
            Room->mapUpdate(CArray[i]);
        }
        Room->printTestRoom();
        cout << CArray[0]->TurnCount << endl;
    }
}
