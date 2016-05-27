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
    char getCharacter(int Representation);
    int getWidth();
    int getHeight();

	void generateMap();
	int* getStartPos();

    void setMapTile(int yPos, int xPos, int newTileType);


private:

	//number of rooms high and wide the map is
	int width;
	int height;

    int TestRoom[30][80]; //the map array

};


#endif
