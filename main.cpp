#include <iostream>
#include "map.h"
#include "character.h"
#include "player.h"
#include "enemy.h"
#include "OS_Functions.h"

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
	player * Player = new player(10,PosArray[1],PosArray[0],1,12);
	Room->enemyNum = rand() % 7 + 3;
	//int enemyNum = 3;
	character * CArray[11];//maximum 10 enemies + player
	CArray[0] = Player;

	for (int i=0; i<Room->enemyNum;i++)
	{
	    PosArray = Room->getStartPos();
	    cout << PosArray[0] << " " << PosArray[1] << endl;
		enemy * Enemy = new enemy(20,PosArray[1],PosArray[0],30,7);
		CArray[i+1] = Enemy;
	}

    cout << "Made all characters" << endl;

	for (int i = 0; i<Room->enemyNum+1; i++)
    {
        Room->mapUpdate(CArray[i]);
    }
    cout << "updated the room" << endl;
    Room->printTestRoom(); //print first frame

	while(Player->getState() != "Dead")
	{
		for (int i = 0; i<Room->enemyNum+1; i++) // for size of character array
		{
			//cout << CArray[i]->Health << endl;
			if(CArray[i]->getHealth() <= 0 && CArray[i]->getState() != "Dead")
            {
                //CArray[i] = NULL;
                CArray[i]->setState("Dead");
                CArray[i]->Type = "Dead";
                CArray[i]->setSymbol(CArray[i]->getGroundSymbol());
                Room->mapUpdate(CArray[i]);
            }
            if(CArray[i]->getState() != "Dead")
            {
                CArray[i]->getTurn(Room,CArray);
                Room->mapUpdate(CArray[i]);
            }


			clear_screen();


		}
		// For Somthing to be displayed it must be placed here -----------
		Room->printTestRoom();
		cout << "Turn Count: " << CArray[0]->TurnCount << endl;
		cout << "Player Health: " << Player->getHealth() << endl;
		for (int i = 1; i<Room->enemyNum+1; i++) // for size of character array
		{
			//Display Enemy Health
			cout << "Enemy #" << i << "Health: " << CArray[i]->getHealth() << " Turn Count: " << CArray[i]->TurnCount <<endl;
		}
		cout << CArray[0]->getX() << " " << CArray[0]->getY() << endl;
		//cout << "Enemy Health: " << Enemy->getHealth() << endl;
		//--------------------------------------------------------
	}
	clear_screen();
	cout << "You Lose" << endl;

}
