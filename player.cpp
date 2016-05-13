#include "character.h"
#include "map.h"
#include "player.h"
#include "OS_Functions.h"
#include <iostream>

player::player(int iSymbol, int ixLocation, int iyLocation,int iHealth, int iAttackD):character(iSymbol, ixLocation, iyLocation, iHealth, iAttackD)
{
}

void player::getTurn(map *Map) // will change to room Need to put in a player class
{
	char Move = getKey();
	yCurrent = yNext;
	xCurrent = xNext;
	switch (Move)
	{
	case 'w': // Move Up
		if (Map->getTestRoomcell(xCurrent, yNext - 1) != 2 && yNext >0) // if the player doesn't hit a wall
		{
			TurnCount++;
			yNext--;
			break;
		}
		cout << "Can't Move there" << endl; // if they hit a wall display message and get another input.
		getTurn(Map);
		break;
	case 's': // Move Down
		if (Map->getTestRoomcell(xCurrent, yNext + 1) != 2 && yNext <Map->getHeight()-1)
		{
			yNext++;
			TurnCount++;
			break;
		}
		cout << "Can't Move there" << endl;
		getTurn(Map);
		break;

	case 'a': // Move Left
		if (Map->getTestRoomcell(xNext - 1, yCurrent) != 2 && xNext > 0)
		{
			xNext--;
			TurnCount++;
			break;
		}
		cout << "Can't Move there" << endl;
		getTurn(Map);
		break;

	case 'd': // Move Right
		if (Map->getTestRoomcell(xNext + 1, yCurrent) != 2 && xNext <Map->getWidth()-1)
		{
			xNext++;
			TurnCount++;
			break;
		}
		cout << "Can't Move there" << endl;
		getTurn(Map);
		break;
	case 'p':
		CharacterState = "Dead";
		break;

	default: break;
	}
}

player::~player()
{
}