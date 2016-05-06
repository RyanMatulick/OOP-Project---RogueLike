//map.h

#ifndef MAP_H
#define MAP_H
using namespace std;

class map
{
public:

    map();
    void generateMap(); // occurs once per room
    void mapUpdate(); // update current map from enemy and player inputs. needs input of current player position?
    void drawMap(); // occurs after player input
    char * getMapPtr();
    ~map();


private:
    char * Map[20][80];
    int generateRandomNumber();
    void initializeMap(); //fill map with blanks
};
#endif
