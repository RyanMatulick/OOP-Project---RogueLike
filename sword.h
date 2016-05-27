#ifndef SWORD_H
#define SWORD_H
#include <string>
#include "item.h"

using namespace std;

class sword : public item
{
public:
    sword();
    sword(string flavourTextIn, string nameIn, string typeIn);

    void use(character * target); //wield or unwield the sword
<<<<<<< HEAD
    void place(character * target, string dType); //to drop

    static int isAnythingWielded; //do we have any weapons in hand? 0=none, 1=one dagger, 2=longsword, 2 daggers
=======
    void place(character * target);

    static int isAnythingWielded; //do we have any weapons in hand? 0=none, 1=one etc.

    ~sword();
>>>>>>> refs/remotes/origin/master

private:
    bool isThisWielded; //is this particular sword in had?

};
#endif // SWORD_H
