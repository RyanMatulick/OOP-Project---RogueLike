#include <iostream>
#include "map.h"
#include "map.cpp"

using namespace std;

int main()
{
    map * theMap;
    theMap = new map(10,10);
    theMap->generateMap();
    theMap->drawMap();
}
