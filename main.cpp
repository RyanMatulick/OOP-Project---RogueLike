#include <iostream>
#include "map.h"
#include "character.h"
#include "player.h"
#include "enemy.h"
#include "OS_Functions.h"
void TestUpdate(map * Room);

int main()
{
	srand(time(NULL));
	clear_screen();

	map * TestRoom;
	TestRoom = new map(80, 30);
	TestUpdate(TestRoom);
}

void TestUpdate(map * Room)
{
	
	Room->generateMap();

	
	
	player * Player = new player(10,*(Room->getStartPos()+1),*(Room->getStartPos()),50,12);
	int enemyNum = rand() % 7 + 3;
	character * CArray[11];//maximum 10 enemies + player
	CArray[0] = Player;

	for (int i=0; i<enemyNum;i++)
	{
		enemy * Enemy = new enemy(20,*(Room->getStartPos()+1),*(Room->getStartPos()),50,12);
		CArray[i+1] = Enemy;
	}



	for (int i = 0; i<enemyNum+1; i++)
    {
        Room->mapUpdate(CArray[i]);
    }
    Room->printTestRoom(); //print first frame

    while(CArray[0]->getState() != "Dead")
    {
        for (int i = 0; i<enemyNum+1; i++)
        {
            CArray[i]->getTurn(Room);
            clear_screen();
            Room->mapUpdate(CArray[i]);
        }
        Room->printTestRoom();
        cout << CArray[0]->TurnCount << endl;
    }
}
