//parent class for all items
#ifndef ITEM_H
#define ITEM_H
#include <string>

class character;
class player;


using namespace std;

class item
{
public:

    item();
    item(string flavourTextIn, string nameIn, string typeIn);

    string getFlavourText();
    string getName();
    string getType();

    virtual void use(character * target);  //virtual function for doing something with an item
    virtual void place(character * target);  //put an item on the floor

    ~item();

protected:
    string flavourText; //details on the item
    string name;
    string type;

};

#endif // ITEM_H
