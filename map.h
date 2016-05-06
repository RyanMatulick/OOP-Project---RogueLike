//map.h

#ifndef MAP_H
#define MAP_H
using namespace std;

class map
{
public:

    map();
    void GenerateMap(); // occurs once per room
    void MapUpdate(); // update current map from enemy and player inputs
    void DrawMap(); // occurs after player input
    ~map();

private:
    char * Map[80][20];
};
#endif
