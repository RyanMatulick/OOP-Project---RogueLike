#include <iostream>
#include <string>
#include "sword.h"
#include "character.h"
#include "map.h"

#define DAGGERDAMAGE 3
#define LONGSWORDDAMAGE 5

using namespace std;

int sword::isAnythingWielded=0;

sword::sword()
{
    isThisWielded=false;
}

sword::sword(string flavourTextIn, string nameIn, string typeIn)
{
    flavourText = flavourTextIn;
    name = nameIn;
    type = typeIn;
    isThisWielded = false;
}

void sword::use(character * target,map * Map)
{
    if(isThisWielded == true) //if you have this weapon on, take it off
    {
        Map->addMessage("You take off your "+ name + ": " + type);
        //reset attack damage
        if(type == "dagger")
        {
            target->setAttackD(-DAGGERDAMAGE);
        }
        else if(type == "longsword")
        {
            target->setAttackD(-LONGSWORDDAMAGE);
        }
        //know we're not wielding it anymore
        isThisWielded = false;
        //reduce our total wield count
        if(type=="dagger")
        {
            isAnythingWielded--;
        }
        else if (type=="longsword")
        {
            isAnythingWielded = isAnythingWielded-2;
        }
    }
    else //if you dont have this weapon on, put it on
    {
        //for dagger
        if(type=="dagger")
        {
            if(isAnythingWielded<2)
            {
                //put dagger on
                Map->addMessage("you put on your " + name + ": " + type);
                target->setAttackD(DAGGERDAMAGE);
                isThisWielded=true;
                isAnythingWielded++;
            }
            else //cant wield another weapon
            {
                Map->addMessage("you can't wield another weapon. You can only wield 2 daggers or one longsword");
            }

        }
        //for longsword
        else if(type=="longsword")
        {
            if(isAnythingWielded==0)
            {
                //put longsword on
                Map->addMessage("you put on your " + name + ": " + type);
                target->setAttackD(LONGSWORDDAMAGE);
                isThisWielded=true;
                isAnythingWielded = isAnythingWielded+2;
            }
            else
            {
                Map->addMessage("you cant wield another weapon. You can only wield 2 daggers or one longsword");
            }

        }
        else{Map->addMessage("unrecognized sword type: ");}

    }
}

void sword::place(character * target)
{
    target->setGroundSymbol(47);
}

sword::~sword()
{

}
