#ifndef POTION_H
#define POTION_H
#include <string>
#include "item.h"

class potion : public item
{
public:
    potion();
    potion(string flavourTextIn, string nameIn, string typeIn);

    void use(character * target); //to drink the potion
    void place(character * target, string dType);//to drop the potion

    ~potion();

private:
    bool full; //has the potion been drunk?

};
#endif // POTION_H
