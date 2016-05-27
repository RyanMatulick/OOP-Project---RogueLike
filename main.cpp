#include <iostream>
#include "map.h"
#include "character.h"
#include "player.h"
#include "enemy.h"
#include "OS_Functions.h"

#ifdef WIN32
#include <cstdlib>
#endif // WIN32

#include "map.cpp"
#include "character.cpp"
#include "player.cpp"
#include "enemy.cpp"
#include "item.cpp"
#include "potion.cpp"
#include "OS_Functions.cpp"
#include "sword.cpp"


#include <ctime>
#include <stdlib.h>
void TestUpdate(map * Room);

int main()
{
	srand(time(NULL));
	clear_screen();
	system("mode 350"); // Windows Only

	map * TestRoom;
	TestRoom = new map(80, 30);
	TestUpdate(TestRoom);
}

void TestUpdate(map * Room)
{

	Room->generateMap();

    int * PosArray;
    PosArray = Room->getStartPos();
	player * Player = new player(10,PosArray[1],PosArray[0],50,12);
	int enemyNum = rand() % 7 + 3;
	//int enemyNum = 3;
	character * CArray[11];//maximum 10 enemies + player
	CArray[0] = Player;

	for (int i=0; i<enemyNum;i++)
	{
	    PosArray = Room->getStartPos();
	    cout << PosArray[0] << " " << PosArray[1] << endl;
		enemy * Enemy = new enemy(20,PosArray[1],PosArray[0],50,12);
		CArray[i+1] = Enemy;
	}

    cout << "Made all characters" << endl;

	for (int i = 0; i<enemyNum+1; i++)
    {
        Room->mapUpdate(CArray[i]);
    }
    cout << "updated the room" << endl;
    Room->printTestRoom(); //print first frame

	while(Player->getState() != "Dead")
	{
		for (int i = 0; i<enemyNum+1; i++) // for size of character array
		{
			//cout << CArray[i]->Health << endl;
			CArray[i]->getTurn(Room,CArray);
			clear_screen();
			Room->mapUpdate(CArray[i]);

		}
		// For Somthing to be displayed it must be placed here -----------
		Room->printTestRoom();
		cout << "Turn Count: " << CArray[0]->TurnCount << endl;
		cout << "Player Health: " << Player->getHealth() << endl;
		cout << "Player attack damage: " << Player->getAttackD() << endl;
		Player->displayInventory();
		//--------------------------------------------------------
	}
}
