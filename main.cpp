#include <iostream>
#include "map.h"
#include "map.cpp"

using namespace std;

int main()
{
    map * theMap;
    theMap = new map();
    theMap->generateMap();
    theMap->drawMap();
}
