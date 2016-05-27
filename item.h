//parent class for all items
#ifndef ITEM_H
#define ITEM_H
#include <string>
<<<<<<< HEAD
#include "character.h"
=======

class character;
class player;

>>>>>>> refs/remotes/origin/master

using namespace std;

class item
{
public:

<<<<<<< HEAD
    //Constructor. flavourText is a little anecdote which is not used, name is the class (potion or sword)
    //and type is the type of each sub class- dagger or longsword, health or poison
    item();
    item(string flavourTextIn, string nameIn, string typeIn);

    //attribute getters
=======
    item();
    item(string flavourTextIn, string nameIn, string typeIn);

>>>>>>> refs/remotes/origin/master
    string getFlavourText();
    string getName();
    string getType();

    virtual void use(character * target);  //virtual function for doing something with an item
<<<<<<< HEAD
    virtual void place(character * target, string dType);  //put an item on the floor
=======
    virtual void place(character * target);  //put an item on the floor
>>>>>>> refs/remotes/origin/master

    ~item();

protected:
<<<<<<< HEAD
    string flavourText; //details on the item. used by child classes
=======
    string flavourText; //details on the item
>>>>>>> refs/remotes/origin/master
    string name;
    string type;

};

#endif // ITEM_H
