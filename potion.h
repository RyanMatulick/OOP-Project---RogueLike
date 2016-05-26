#ifndef POTION_H
#define POTION_H
#include <string>
#include "item.h"

//class item;
class character;


class potion : public item
{
public:
    potion();
    potion(string flavourTextIn, string nameIn, string typeIn);

    void use(character * target);
    void place(character * target);

    ~potion();

private:
    bool full;

};
#endif // POTION_H
