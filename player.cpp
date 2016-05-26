#include "player.h"
#include "OS_Functions.h"

player::player(int iSymbol, int * Pos,int iHealth, int iAttackD):character(iSymbol, Pos, iHealth, iAttackD, "PLAYER")
{
}
int player::Getinput(character *Player)
{
	return int(getKey());
}
player::~player()
{
}
