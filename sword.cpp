<<<<<<< HEAD
#include <string>
#include "sword.h"
=======
#include <iostream>
#include <string>
#include "sword.h"
#include "character.h"
>>>>>>> refs/remotes/origin/master

#define DAGGERDAMAGE 3
#define LONGSWORDDAMAGE 5

using namespace std;

<<<<<<< HEAD
int sword::isAnythingWielded=0; //do we have any weapons wielded?
=======
int sword::isAnythingWielded=0;
>>>>>>> refs/remotes/origin/master

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

void sword::use(character * target)
{
<<<<<<< HEAD
=======
    cout << "sword::use called" << endl;
>>>>>>> refs/remotes/origin/master
    if(isThisWielded == true) //if you have this weapon on, take it off
    {
        cout << "You are take off your "<< name << ": " << type << endl;

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
                cout << "you put on your " << name << ": " << type << endl;
                target->setAttackD(DAGGERDAMAGE);
                isThisWielded=true;
                isAnythingWielded++;
            }
            else //cant wield another weapon
            {
                cout << "you can't wield another weapon. You can only wield 2 daggers or one longsword" << endl;
            }

        }
        //for longsword
        else if(type=="longsword")
        {
            if(isAnythingWielded==0)
            {
                //put longsword on
                cout << "you put on your " << name << ": " << type << endl;
                target->setAttackD(LONGSWORDDAMAGE);
                isThisWielded=true;
                isAnythingWielded = isAnythingWielded+2;
            }
            else
            {
                cout << "you cant wield another weapon. You can only wield 2 daggers or one longsword" << endl;
            }

        }
        else{ cout << "unrecognized sword type: "<< type<<endl;}

    }
}

<<<<<<< HEAD
void sword::place(character * target, string dType)
{
    if(dType=="longsword")
    {
        target->setGroundSymbol(47);
    }
    else if(dType=="dagger")
    {
        target->setGroundSymbol(96);
    }
    else {cout<<"Unknown type"<<endl;}
=======
void sword::place(character * target)
{
    target->setGroundSymbol(47);
>>>>>>> refs/remotes/origin/master
}

sword::~sword()
{

}
