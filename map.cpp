//map.cpp
#include <iostream>
#include "map.h"
#include "character.h"

#include <stdlib.h>



using namespace std;


map::map(int inWidth, int inHeight, int enemyCount)
{
	width=inWidth;
	height = inHeight;
	enemyNum = enemyCount;
}

void map::generateMap()
{
	int length = 0; // length of corridor

	int tmap[30][80];

	for (int j=0;j<30;j++)
	{
		for (int i=0;i<80;i++)
		{
			tmap[j][i] = 0;
		}
	}

	int pos_x = rand() % (70+1-10) + 10;
	int pos_y = rand() % (20+1-10) + 10;

	int rooms = 0;

	int roomsize_x, roomsize_y, dir;

	bool dirset = false;

	bool goodmap = false;

	int test1 = 0;
	int test2 = 0;

	while (goodmap == false) // whether rooms are across both sides of map
	{

		while (rooms < 14)
		{

			//room generation

			roomsize_x = rand() % (8+1-2) + 2;
			roomsize_y = rand() % (6+1-2) + 2;
			while (roomsize_x > pos_x -2 or roomsize_x > 80 - pos_x -3)
			{
				roomsize_x -= 1;
			}
			while (roomsize_y > pos_y -2 or roomsize_y > 30 - pos_y -3)
			{
				roomsize_y -= 1;
			}

			for(int i=-1*roomsize_x;i<=roomsize_x;i++)
			{
				for(int j=-1*roomsize_y;j<=roomsize_y;j++)
				{
					tmap[pos_y+j][pos_x+i] = 1;
				}
			}
			rooms += 1;

			//corridor generation
			if (dirset == false)
			{
				dir = rand() % 4;
			}

			switch (dir)
			{
				case 0://right
				{
					length = rand() % (30-roomsize_x) + roomsize_x;
					for(int i=0;i<length;i++)
					{
						tmap[pos_y][pos_x+i] = 1;
						if (pos_x+i > 76)
						{
							dir = 1;
							dirset = true;
							length = i;
							break;
						}
						else
						{
							dirset = false;
						}
					}
					pos_x += length;

				}; break;
				case 1://left
				{
					length = -(rand() % (30-roomsize_x) + roomsize_x);
					for(int i=0;i>length;i--)
					{
						tmap[pos_y][pos_x+i] = 1;
						if (pos_x+i < 3)
						{
							dir = 0;
							dirset = true;
							length = i;
							break;
						}
						else
						{
							dirset = false;
						}
					}
					pos_x += length;

				}; break;
				case 2://down
				{
					length = rand() % (30-roomsize_y) + roomsize_y;
					for(int i=0;i<length;i++)
					{
						tmap[pos_y+i][pos_x] = 1;
						if (pos_y+i > 26)
						{
							dir = 3;
							dirset = true;
							length = i;
							break;
						}
						else
						{
							dirset = false;
						}
					}
					pos_y += length;

				}; break;
				case 3://up
				{
					length = -(rand() % (30-roomsize_y) + roomsize_y);
					for(int i=0;i>length;i--)
					{
						tmap[pos_y+i][pos_x] = 1;
						if (pos_y+i < 3)
						{
							dir = 2;
							dirset = true;
							length = i;
							break;
						}
						else
						{
							dirset = false;
						}
					}
					pos_y += length;
				}; break;
			}

			// test if map is good
		}
		for (int j=0;j<30;j++)
		{
			for (int i=0;i<40;i++)
			{
				test1 += tmap[j][i];
			}
			for (int i=40;i<80;i++)
			{
				test2 += tmap[j][i];
			}
		}
		if (test1<150 or test2<150)
		{
			goodmap = false;
			rooms = 0;
			for (int j=0;j<30;j++)
			{
				for (int i=0;i<80;i++)
				{
					tmap[j][i] = 0;
				}

			}
		}
		else
		{
			goodmap = true;
		}
	}


	// walls
	for (int j=0;j<30;j++)
	{
		for (int i=0;i<80;i++)
		{
			if (tmap[j][i] == 1)
			{
				for (int l=-1;l<=1;l++)
				{
					for (int k=-1;k<=1;k++)
					{
						if (tmap[j+l][i+k] == 0)
						{
							tmap[j+l][i+k] = 2;
						}
					}
				}
			}
		}
	}
	for (int j=0;j<30;j++)
	{
		for (int i=0;i<80;i++)
		{
			TestRoom[j][i] = tmap[j][i];
		}
	}
}

int* map::getStartPos()
{
	int pos_x, pos_y,check;
	check = 0;
	static int posArray[2];
	while (check != 1)
	{
		pos_x = rand() % 80;
		pos_y = rand() % 30;
		//cout << "1: " <<pos_x << " " << pos_y << endl;

		check = TestRoom[pos_y][pos_x];
	}
	//cout << "After Loop" << endl;
	posArray[0] = pos_y;
	posArray[1] = pos_x;
	//cout << "2: " << array[0] << " " << array[1] << endl;
	return posArray;


}

void map::setMapTile(int yPos, int xPos, int newTileType)
{
    TestRoom[yPos][xPos] = newTileType;
}

//Ryan's stuff
//This is the upadate for all Objects (Characters,Items,Traps etc.) on the map
void map::mapUpdate(character * Character)
{
	//Repeat for every Character on the map. currently static 1;
	// will have to iterate through an array of characters

	TestRoom[Character->getY()][Character->getX()] = Character->getGroundSymbol();
	Character->setGroundSymbol(TestRoom[Character->getNextY()][Character->getNextX()]);
	TestRoom[Character->getNextY()][Character->getNextX()] = Character->getSymbol();
}

char map::getTestRoomcell(int x, int y) // some form of this is needed to check for collisions and enemies in adjacent squares
{
	return TestRoom[y][x];
}

void map::printTestRoom()
{
	for (int j = 0; j<height; j++)
	{
		for (int i = 0; i<width; i++)
		{
			#ifdef _WIN32
				cout << getCharacter(TestRoom[j][i]);
			#else
				switch(TestRoom[j][i])
				{
					case 0: cout<<' ';break; // empty space
					case 1: cout.write("\u2219",3);break; // ground floor
					case 2: printWall(j,i);break; // basic wall
					case 10: cout.write("\u04EB",3);break; // Player symbol
					case 20: cout.write("\u0416",3);break; // Enemy symbol
       				case 47: cout<<'/';break; //sword
        			case 94: cout<<'^';break; //potion
					default: cout<<'?';break; // has not been defined yet
				}
			#endif
		}
		cout << endl;
	}
}

void map::printWall(int j,int i)
{
	int adj=0; //how many walls are adjacent
	for(int a=-1;a<2;a++)
	{
		for(int b=-1;b<2;b++)
		{
			if (a!=b and a!=b*-1 and TestRoom[j+a][i+b] == 2) {adj+=1;}
		}
	}

	if (adj == 0) {cout.write("\u2550",3);}//H
	else if (adj == 1)
	{
		if (TestRoom[j+1][i] == 2 or TestRoom[j-1][i] == 2) {cout.write("\u2551",3);}//V
		else if (TestRoom[j][i+1] == 2 or TestRoom[j][i-1] == 2) {cout.write("\u2550",3);}//H
	}
	else if (adj == 2)
	{
		if (TestRoom[j+1][i] == 2 and TestRoom[j-1][i] == 2) {cout.write("\u2551",3);}//V
		else if (TestRoom[j][i+1] == 2 and TestRoom[j][i-1] == 2) {cout.write("\u2550",3);}//H
		else if (TestRoom[j+1][i] == 2 and TestRoom[j][i+1] == 2) {cout.write("\u2554",3);}//TL
		else if (TestRoom[j+1][i] == 2 and TestRoom[j][i-1] == 2) {cout.write("\u2557",3);}//TR
		else if (TestRoom[j-1][i] == 2 and TestRoom[j][i-1] == 2) {cout.write("\u255D",3);}//BR
		else if (TestRoom[j-1][i] == 2 and TestRoom[j][i+1] == 2) {cout.write("\u255A",3);}//BL
	}
	else if (adj == 3)
	{
		if (TestRoom[j][i+1] != 2) {cout.write("\u2563",3);}//NR
		else if (TestRoom[j][i-1] != 2) {cout.write("\u2560",3);}//NL
		else if (TestRoom[j+1][i] != 2) {cout.write("\u2569",3);}//NB
		else if (TestRoom[j-1][i] != 2) {cout.write("\u2566",3);}//NT
	}
	else {cout.write("\u256C",3);}//ALL
}


char map::getCharacter(int Representation)
{
	switch(Representation)
	{
		case 0: return ' '; // empty space
		case 1: return '.'; // ground floor
		case 2: return '#'; // basic wall
		case 10: return '@'; // Player symbol
		case 20: return '&'; // Enemy symbol
        case 47: return '/'; //sword
        case 94: return '^'; //potion
		default: return '?'; // has not been defined yet
	}
}

int map::getWidth()
{
	return width;
}
int map::getHeight()
{
	return height;
}
int map::getEnemyNum()
{
	return enemyNum;
}

map::~map()
{
}
