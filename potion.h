#ifndef POTION_H
#define POTION_H
#include <string>
#include "item.h"

<<<<<<< HEAD
=======
//class item;
class character;


>>>>>>> refs/remotes/origin/master
class potion : public item
{
public:
    potion();
    potion(string flavourTextIn, string nameIn, string typeIn);

<<<<<<< HEAD
    void use(character * target); //to drink the potion
    void place(character * target, string dType);//to drop the potion
=======
    void use(character * target);
    void place(character * target);
>>>>>>> refs/remotes/origin/master

    ~potion();

private:
<<<<<<< HEAD
    bool full; //has the potion been drunk?
=======
    bool full;
>>>>>>> refs/remotes/origin/master

};
#endif // POTION_H
