#include "player.h"

player::player(int iSymbol, int ixLocation, int iyLocation,int iHealth, int iAttackD):character(iSymbol, ixLocation, iyLocation, iHealth, iAttackD, "PLAYER")
{

}

player::~player()
{
}

void player::displayInventory()
{
    cout << endl << "Inventory:" <<endl;
    for(int i = 0; i<10; i++)
    {
        if(Inventory[i]->getName()!="") //ensure we actually have an item in this slot
        {
            cout << i<< ": " << Inventory[i]->getName() <<": "<< Inventory[i]->getType()<< endl;
        }
        else
        {
            cout <<i<<":" <<endl;
        }
    }
    cout << "-End Inventory-" << endl;
}


