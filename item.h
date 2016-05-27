//parent class for all items
#ifndef ITEM_H
#define ITEM_H
#include <string>
#include "character.h"

using namespace std;

class item
{
public:

    //Constructor. flavourText is a little anecdote which is not used, name is the class (potion or sword)
    //and type is the type of each sub class- dagger or longsword, health or poison
    item();
    item(string flavourTextIn, string nameIn, string typeIn);

    //attribute getters
    string getFlavourText();
    string getName();
    string getType();

    virtual void use(character * target);  //virtual function for doing something with an item
    virtual void place(character * target, string dType);  //put an item on the floor

    ~item();

protected:
    string flavourText; //details on the item. used by child classes
    string name;
    string type;

};

#endif // ITEM_H
