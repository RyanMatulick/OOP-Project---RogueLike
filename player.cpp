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
<<<<<<< HEAD
        if(Inventory[i]->getName()!="") //ensure we actually have an item in this slot
        {
            cout << i<< ": " << Inventory[i]->getName() <<": "<< Inventory[i]->getType()<< endl;
        }
        else
        {
            cout <<i<<":" <<endl;
        }
=======
        cout << i<< ": " << Inventory[i]->getName() <<": "<< Inventory[i]->getType()<< endl;
>>>>>>> refs/remotes/origin/master
    }
    cout << "-End Inventory-" << endl;
}

<<<<<<< HEAD

=======
>>>>>>> refs/remotes/origin/master
