#include "enemy.h"
#include <math.h>
#include <stdlib.h>
//Creates an Enemy Object
enemy::enemy(int iSymbol, int * Pos,int iHealth, int iAttackD):character(iSymbol, Pos, iHealth, iAttackD,"ENEMY")
{
}

int enemy::Getinput(character *Player)
{

	int PlayerX = Player->getNextX();
	int PlayerY = Player->getNextY();

	int EnemyX = getNextX();
	int EnemyY = getNextY();

	int DistX = PlayerX - EnemyX;
	int DistY = PlayerY - EnemyY;

	int Distance = int(sqrt(DistX*DistX + DistY*DistY)); // Distance between enemy and player

	if (TurnCount == LastTurn)
    {
        return rand() % 4 + 1;// If a move toward the player cannot be found, move randomly } // Check that the Character has moved
    }
    else
    {
        LastMove = -1;
    }
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
