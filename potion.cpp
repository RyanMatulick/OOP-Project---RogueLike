#include <string>
#include "potion.h"
#include "item.h"

using namespace std;

potion::potion()
{
    full=true; //set full to true on creation so it can be drunk
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
    if(!full) //you can only drink it if there's comething there...
    {
        cout<<"You already drank that!" << endl;
    }

    else
    {

        if(!type.compare("health")) //if the type is health potion (compare returns 0 if equal)
        {
            full=false;
            target->setHealth(10);  //set target health to be +10
            cout << "you feel refreshed" << endl;
        }
        else if (!type.compare("poison")) //else is a poison potion
        {
            full=false;
            target->setHealth(-10); //take away ten health
            cout << "you dont feel so good..." << endl;
        }
    }

}

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
}

potion::~potion()
{

}
