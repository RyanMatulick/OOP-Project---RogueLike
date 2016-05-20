#include <iostream>
#include "map.h"
#include "character.h"
#include "player.h"
#include "enemy.h"
#include "OS_Functions.h"
<<<<<<< HEAD
=======
#ifdef WIN32
#include <cstdlib>
#endif // WIN32


>>>>>>> origin/master
void TestUpdate(map * Room);

int main()
{
<<<<<<< HEAD
	srand(time(NULL));
	clear_screen();

=======
	system("mode 350");
	clear_screen();
>>>>>>> origin/master
	map * TestRoom;
	TestRoom = new map(80, 30);
	TestUpdate(TestRoom);
}
<<<<<<< HEAD

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

	while(Player->getState() != "Dead")
	{
		for (int i = 0; i<enemyNum+1; i++) // for size of character array
=======

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
>>>>>>> origin/master
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
<<<<<<< HEAD
		//cout << "Enemy Health: " << Enemy->getHealth() << endl;
=======
		cout << "Enemy Health: " << Enemy->getHealth() << endl;
>>>>>>> origin/master
		//--------------------------------------------------------
	}
}
