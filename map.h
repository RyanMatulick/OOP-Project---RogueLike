//map.h

#ifndef MAP_H
#define MAP_H
//#include "character.h"
using namespace std;
class character;

class map
{
public:

	map(int inWidth, int inHeight);
	void drawMap(); // occurs after player input
	~map();


	//Ryan Added
	void printTestRoom(); // Displays the current static test room
	char getTestRoomcell(int x, int y);
	void mapUpdate(character * Character); // update current map from enemy and player inputs. needs input of current player position?

private:

	//number of rooms high and wide the map is
	int width;
	int height;

	//TEMP
	//Only until jack has an awesome random generator! but will be useful for testing.
	char TestRoom[10][10] = {{'.', '.', '.', '.', '.', '#', '.', '.', '.', '.',},
                            { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.',},
                            { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.',},
                            { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.',},
                            { '.', '.', 'i', '.', '.', '.', '.', '.', '.', '.',},
                            { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.',},
                            { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.',},
                            { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.',},
                            { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.',},
                            { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.',}};

    int TestMap[3][2] ={{0,0},
                        {1,0},
                        {1,1}};



};


#endif
