//parent class for all items
#ifndef ITEM_H
#define ITEM_H
#include <string>
#include "character.h"

using namespace std;

class item
{
public:

    item();
    item(string flavourTextIn, string nameIn, string typeIn);

    string getFlavourText();
    string getName();
    string getType();

    virtual void use(character * target);

    ~item();

protected:
    string flavourText; //details on the item
    string name;
    string type;

};

#endif // ITEM_H
