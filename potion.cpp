#include <string>
<<<<<<< HEAD
#include "potion.h"
#include "item.h"
=======
#include <iostream>
#include "potion.h"
#include "item.h"
#include "character.h"
//#include "character.h"
>>>>>>> refs/remotes/origin/master

using namespace std;

potion::potion()
{
<<<<<<< HEAD
    full=true; //set full to true on creation so it can be drunk
=======
    full=true;
>>>>>>> refs/remotes/origin/master
}

potion::potion(string flavourTextIn, string nameIn, string typeIn)
{
    flavourText = flavourTextIn;
    name = nameIn;
    type = typeIn;
    full=true;
}

void potion::use(character * target)
{
    cout << "potion::use called" << endl;
<<<<<<< HEAD
    if(!full) //you can only drink it if there's comething there...
=======
    if(!full)
>>>>>>> refs/remotes/origin/master
    {
        cout<<"You already drank that!" << endl;
    }

    else
    {

        if(!type.compare("health")) //if the type is health potion (compare returns 0 if equal)
        {
            full=false;
<<<<<<< HEAD
            target->setHealth(10);  //set target health to be +10
            cout << "you feel refreshed" << endl;
        }
        else if (!type.compare("poison")) //else is a poison potion
        {
            full=false;
            target->setHealth(-10); //take away ten health
=======
            target->setHealth(50);  //set target health to be the maximum
            cout << "you feel refreshed" << endl;
        }
        else if (!type.compare("poison"))
        {
            full=false;
            target->setHealth(-10);
>>>>>>> refs/remotes/origin/master
            cout << "you dont feel so good..." << endl;
        }
    }

}

<<<<<<< HEAD
void potion::place(character * target, string dType)
{
    if(dType=="health")
    {
        target->setGroundSymbol(94); //health potion ground symbol=^
    }
    else if(dType=="poison")
    {
        target->setGroundSymbol(118);//poison potion ground symbol=v
    }
    else {cout<<"Unknown type"<<endl;}
=======
void potion::place(character * target)
{
    target->setGroundSymbol(94);
>>>>>>> refs/remotes/origin/master
}

potion::~potion()
{

}
