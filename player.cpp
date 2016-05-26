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

void player::displayInventory()
{
    cout << endl << "Inventory:" <<endl;
    for(int i = 0; i<10; i++)
    {
        cout << i<< ": " << Inventory[i]->getName() <<": "<< Inventory[i]->getType()<< endl;
    }
    cout << "-End Inventory-" << endl;
}

