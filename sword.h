#ifndef SWORD_H
#define SWORD_H
#include <string>
#include "item.h"
#include "map.h"

using namespace std;

class sword : public item
{
public:
    sword();
    sword(string flavourTextIn, string nameIn, string typeIn);

    void use(character * target,map * Map); //wield or unwield the sword
    void place(character * target);

    static int isAnythingWielded; //do we have any weapons in hand? 0=none, 1=one etc.

    ~sword();

private:
    bool isThisWielded; //is this particular sword in hand?

};
#endif // SWORD_H
