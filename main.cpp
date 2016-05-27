#include <iostream>
#include "map.h"
#include "character.h"
#include "player.h"
#include "enemy.h"
#include "OS_Functions.h"

#include <ctime>
#include <stdlib.h>

void GameLoop(map * Room);
int seed;
using namespace std;
int main()
{

	cout << "seed: ";
	cin >> seed; // gets seed
	if (seed <= 0) {seed = time(NULL);} // 0 generates random seed
	srand(seed);  // set the random seed
	clear_screen(); // Clear the current terminal
	#ifdef _WIN32
        system("mode 350"); // Windows Only for full screen
    #endif

	map * Room; // declare First Room
	Room = new map(80, 30, rand() % 7 + 3); // Y Size,X Size, Number of Enemies
	GameLoop(Room); // Main Game Loop
}

void GameLoop(map * Room)
{
	Room->generateMap();// Generate a random map

	player * Player = new player(10,Room->getStartPos(),50,7); // Initialise the Player

	character * CArray[11];//maximum 10 enemies + player
	CArray[0] = Player; // Place Player in First Spot
	Room->mapUpdate(CArray[0]); // Place Player on Map

	for (int i=1; i<Room->getEnemyNum()+1;i++)
	{
		enemy * Enemy = new enemy(20,Room->getStartPos(),20,8); // Initialise the Enemies
		CArray[i] = Enemy; // Place Enemy in Array of Characters
		Room->mapUpdate(CArray[i]); // Place Enemy on Map
	}

    int EnemysRemaining = Room->getEnemyNum();
	while(Player->getState() != "Dead") // Main Loop
	{
	    // For Somthing to be displayed it must be placed here ------------------------
	    cout << seed << endl;
		Room->printTestRoom(); // Prints out the Maps Updated State
		//Print Player Info
		cout << "Player Health: " << Player->getHealth() << " Turn Count: " << CArray[0]->TurnCount << endl;
		cout << "Player attack damage: " << Player->getAttackD() << "\n" << endl;
		cout << "Message Log:" << endl;
		for (int i = 0; i<3; i++)
        {
            cout << Room->Messages[i] << endl;
        }
		Player->displayInventory();
		//------------------------------------------------------------------------

		for (int i = 0; i<Room->getEnemyNum()+1; i++) // for Every Character in game
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
		if (EnemysRemaining == 0)
        {
            break;
        }
	}
	//If program is here the player has died or won the game
	clear_screen();
	if (EnemysRemaining == 0)
    {
        cout << "YOU WIN" << endl;
    }
	else
    {
        cout << "You Lose" << endl;
	}
    //delete *CArray;
    delete Room;
    getKey();
}
