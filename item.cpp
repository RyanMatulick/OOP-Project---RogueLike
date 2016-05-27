#include <iostream>
#include "item.h"
#include "map.h"

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

void item::use(character * target, map* Map)
{
    cout << "Nothing in that slot" << endl;
}

void item::place(character * target)
{
    cout << "Nothing in that slot" << endl;
}

item::~item()
{

}
