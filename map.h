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
	void generateMap(); // occurs once per room
	void mapUpdate(character * Character); // update current map from enemy and player inputs. needs input of current player position?
	void drawMap(); // occurs after player input
	char * getMapPtr();
	~map();


	//Ryan Added
	void printTestRoom(); // Displays the current static test room
	char getTestRoomcell(int x, int y);


private:
	char * Map[10][10];
	int generateRandomNumber();
	void initializeMap(); //fill map with blanks
	void fillMap();

	//number of rooms high and wide the map is
	int width;
	int height;


	int numberOfRooms; //number of rooms in the map. count for purpos of ensuring their are sufficient rooms

	//TEMP
	//Only until jack has an awesome random generator! but will be useful for testing.
	char TestRoom[10][10] = {{'.', '.', '.', '.', '.', '#', '.', '.', '.', '.',},
                            { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.',},
                            { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.',},
                            { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.',},
                            { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.',},
                            { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.',},
                            { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.',},
                            { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.',},
                            { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.',},
                            { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.',}};


};


#endif
