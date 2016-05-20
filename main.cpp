#include <iostream>
#include "map.h"
#include "character.h"
#include "player.h"
#include "enemy.h"
#include "OS_Functions.h"
#ifdef WIN32
#include <cstdlib>
#endif // WIN32


void TestUpdate(map * Room);

int main()
{
	system("mode 350");
	clear_screen();
	map * TestRoom;
	TestRoom = new map(80, 30);
	TestUpdate(TestRoom);
}

void TestUpdate(map * Room)
{ 
	player * Player = new player(10, 9, 7,50,12); // Display Symbol, x position, y position, Health, damage;
	enemy * Enemy = new enemy(20, 30,16,20,7);
	character * CArray[2];
	CArray[0] = Player;
	CArray[1] = Enemy;

	for (int i = 0; i<2; i++) // for size of character array
	{
		Room->mapUpdate(CArray[i]);
	}
	Room->printTestRoom();

	while(Player->getState() != "Dead")
	{
		for (int i = 0; i<2; i++) // for size of character array
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
		cout << "Enemy Health: " << Enemy->getHealth() << endl;
		//--------------------------------------------------------
	}
}
