#include "item.h"

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

//these implementations of use and place will be called if the player tries to interact
//with a blank inventory slot. (blank inv. slots are items with unset attributes)
void item::use(character * target)
{
    cout << "Nothing in that slot" << endl;
}

void item::place(character * target, string dType)
{
    cout << "Nothing in that slot" << endl;
}

item::~item()
{

}
