#include <string>
#include <iostream>
#include "potion.h"
#include "item.h"
#include "map.h"
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

void potion::use(character * target, map * Map)
{
    if(!type.compare("health")) //if the type is health potion (compare returns 0 if equal)
    {
        full=false;
        target->setHealth(50);  //set target health to be the maximum
        Map->addMessage("you feel refreshed");
    }
    else if (!type.compare("poison"))
    {
        full=false;
        target->setHealth(-10);
        Map->addMessage("you dont feel so good...");
    }
}

void potion::place(character * target)
{
    target->setGroundSymbol(94);
}

potion::~potion()
{

}
