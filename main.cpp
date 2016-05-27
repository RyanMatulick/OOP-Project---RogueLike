#include <iostream>
#include "map.h"
#include "character.h"
#include "player.h"
#include "enemy.h"
#include "OS_Functions.h"
<<<<<<< HEAD

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
=======

#include <ctime>
#include <stdlib.h>
void GameLoop(map * Room);

int main()
{
	int seed;
	cout << "seed: ";
	cin >> seed; // gets seed
	if (seed > 0) {srand(seed);} // 0 generates random seed
	else {srand(time(NULL));} // set the random seed
	clear_screen(); // Clear the current terminal
	//system("mode 350"); // Windows Only for full screen

	map * Room; // declare First Room
	Room = new map(80, 30, rand() % 1 + 3); // Y Size,X Size, Number of Enemies
	GameLoop(Room); // Main Game Loop
}

void GameLoop(map * Room)
{
	Room->generateMap();// Generate a random map

	player * Player = new player(10,Room->getStartPos(),50,12); // Initialise the Player

	character * CArray[11];//maximum 10 enemies + player
	CArray[0] = Player; // Place Player in First Spot
	Room->mapUpdate(CArray[0]); // Place Player on Map

	for (int i=1; i<Room->getEnemyNum()+1;i++)
	{
		enemy * Enemy = new enemy(20,Room->getStartPos(),30,7); // Initialise the Enemies
		CArray[i] = Enemy; // Place Enemy in Array of Characters
		Room->mapUpdate(CArray[i]); // Place Enemy on Map
	}
>>>>>>> refs/remotes/origin/master

	Room->printTestRoom(); //print Start State
    int EnemysRemaining = Room->getEnemyNum();
	while(Player->getState() != "Dead") // Main Loop
	{
<<<<<<< HEAD
		for (int i = 0; i<enemyNum+1; i++) // for size of character array
=======
		for (int i = 0; i<Room->getEnemyNum()+1; i++) // for Every Character in game
>>>>>>> refs/remotes/origin/master
		{
			//If the Character has No Health and is not already dead
			if(CArray[i]->getHealth() <= 0 && CArray[i]->getState() != "Dead")
			{
				CArray[i]->setState("Dead"); // set state to DEAD
				CArray[i]->setSymbol(CArray[i]->getGroundSymbol()); // Update his symbol to be that of what he is standing on
				Room->mapUpdate(CArray[i]); //Update the map
				EnemysRemaining--;
			}
			if(CArray[i]->getState() != "Dead") // If Character is Not Dead
			{
				CArray[i]->getTurn(Room,CArray); // Get Characters Turn
				Room->mapUpdate(CArray[i]); // Update the Map State

			}
			clear_screen(); // Clear the Screen ready for Print
		}
		// For Somthing to be displayed it must be placed here -----------
<<<<<<< HEAD
		Room->printTestRoom();
		cout << "Turn Count: " << CArray[0]->TurnCount << endl;
		cout << "Player Health: " << Player->getHealth() << endl;
		cout << "Player attack damage: " << Player->getAttackD() << endl;
		Player->displayInventory();
=======
		Room->printTestRoom(); // Prints out the Maps Updated State
		//Print Player Info
		cout << "Player Health: " << Player->getHealth() << " Turn Count: " << CArray[0]->TurnCount << endl;
		cout << "Player attack damage: " << Player->getAttackD() << endl;
		Player->displayInventory();
		for (int i = 1; i<Room->getEnemyNum()+1; i++) // for size of character array
		{
			//Display Enemy Info DEBUGGING
			cout << "Enemy #" << i << " Health: " << CArray[i]->getHealth() << " Turn Count: " << CArray[i]->TurnCount <<endl;
		}
		if (EnemysRemaining == 0)
        {
            cout << "YOU WIN" << endl;
        }
>>>>>>> refs/remotes/origin/master
		//--------------------------------------------------------
	}
	//If program is here the player has died
	clear_screen();
	cout << "You Lose" << endl;

}
