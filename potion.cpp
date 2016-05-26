#include <string>
#include <iostream>
#include "potion.h"
#include "item.h"
#include "character.h"
//#include "character.h"

using namespace std;

potion::potion()
{
    full=true;
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
    if(!full)
    {
        cout<<"You already drank that!" << endl;
    }

    else
    {

        if(!type.compare("health")) //if the type is health potion (compare returns 0 if equal)
        {
            full=false;
            target->setHealth(50);  //set target health to be the maximum
            cout << "you feel refreshed" << endl;
        }
        else if (!type.compare("poison"))
        {
            full=false;
            target->setHealth(-10);
            cout << "you dont feel so good..." << endl;
        }
    }

}

void potion::place(character * target)
{
    target->setGroundSymbol(94);
}

potion::~potion()
{

}
