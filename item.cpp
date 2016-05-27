<<<<<<< HEAD
#include "item.h"

=======
#include <iostream>
#include "item.h"


>>>>>>> refs/remotes/origin/master
using namespace std;

item::item()
{
    name = "";
    type = "";
    flavourText = "not set";
}

item::item(string flavourTextIn, string nameIn, string typeIn)
{
    flavourText = flavourTextIn;
    name = nameIn;
    type = typeIn;
}

string item::getFlavourText()
{
    return flavourText;
}

string item::getName()
{
    return name;
}

string item::getType()
{
    return type;
}

<<<<<<< HEAD
//these implementations of use and place will be called if the player tries to interact
//with a blank inventory slot. (blank inv. slots are items with unset attributes)
=======
>>>>>>> refs/remotes/origin/master
void item::use(character * target)
{
    cout << "Nothing in that slot" << endl;
}

<<<<<<< HEAD
void item::place(character * target, string dType)
=======
void item::place(character * target)
>>>>>>> refs/remotes/origin/master
{
    cout << "Nothing in that slot" << endl;
}

item::~item()
{

}
