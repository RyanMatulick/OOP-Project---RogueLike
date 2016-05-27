//map.h

#ifndef MAP_H
#define MAP_H
#include <iostream>
#include <string>
using namespace std;
class character;

class map
{
public:

	map(int inWidth, int inHeight, int NumofEnemies);
	void drawMap(); // occurs after player input
	~map();


	//Ryan Added
	void printTestRoom(); // Displays the current static test room
	char getTestRoomcell(int x, int y);
	void mapUpdate(character * Character); // update current map from enemy and player inputs. needs input of current player position?
	char getCharacter(int Representation);
	int getEnemyNum();
	int getWidth();
	int getHeight();

	void generateMap();
	int* getStartPos();
	void printWall(int j,int i);
	int enemyNum;
	void setMapTile(int yPos, int xPos, int newTileType);
	void addMessage(string Message);

	string * Messages = new string [3];

private:

	//number of rooms high and wide the map is
	int width;
	int height;



	//TEMP
	//Only until jack has an awesome random generator! but will be useful for testing.
	int TestRoom[30][80];

};


#endif
