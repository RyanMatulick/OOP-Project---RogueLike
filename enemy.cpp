#include "enemy.h"
#include <iostream>
<<<<<<< HEAD
#include <math.h>
//<windows.h>
=======
#include <cmath>
#include <stdlib.h>
>>>>>>> origin/master
//Creates an Enemy Object
enemy::enemy(int iSymbol, int * Pos,int iHealth, int iAttackD):character(iSymbol, Pos, iHealth, iAttackD,"ENEMY")
{

}

int enemy::Getinput(character *Player)
{
<<<<<<< HEAD

=======
>>>>>>> origin/master
	int PlayerX = Player->getNextX();
	int PlayerY = Player->getNextY();

	int EnemyX = getNextX();
	int EnemyY = getNextY();

	int DistX = PlayerX - EnemyX;
	int DistY = PlayerY - EnemyY;

<<<<<<< HEAD
	int Distance = int(sqrt(DistX*DistX + DistY*DistY)); // Distance between enemy and player
	
=======
	int Distance = int(sqrt(pow(DistX,2) + pow(DistY,2))); // Distance between enemy and player

>>>>>>> origin/master
	if (TurnCount != LastTurn) { LastMove = -1; } // Check that the Character has moved

	if (Distance < 6 )
	{
		if (DistX < 0 && LastMove !=3) // Left
		{
			LastMove = 3;
			LastTurn = TurnCount;
			return 3;
		}
		else if (DistX > 0 && LastMove != 4) // right
		{
			LastMove = 4;
			LastTurn = TurnCount;
			return 4;
		}
		else if (DistY < 0 && LastMove != 1) // Up
		{
			LastMove = 1;
			LastTurn = TurnCount;
			return 1;
		}
		else if (DistY > 0 && LastMove != 2) // Down
		{
			LastMove = 2;
			LastTurn = TurnCount;
			return 2;
		}
	}

	return rand() % 4 + 1; // If a move toward the player cannot be found, move randomly
}
enemy::~enemy()
{
}
