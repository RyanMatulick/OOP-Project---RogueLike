//map.cpp
//map generates, updates and displays the game map, whihc is stored as a 80x20 array or characters
//  #=wall  " "=blanck
#include <iostream>
#include "map.h"
#include "character.h"


using namespace std;


map::map(int inWidth, int inHeight)
{
	width=inWidth;
	height = inHeight;
}

void map::generateMap()
{
	//srand(seed); // set the random seed - good seed 1463547505

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
			while (roomsize_x > pos_x -1 or roomsize_x > 80 - pos_x -2)
			{
				roomsize_x -= 1;
			}
			while (roomsize_y > pos_y -1 or roomsize_y > 30 - pos_y -2)
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
	int array[2] = {0,0};
	while (check != 1)
	{
		pos_x = rand() % 80;
		pos_y = rand() % 30;
		check = TestRoom[pos_y][pos_x];
	}
	array[0] = pos_y;
	array[1] = pos_x;
	return &array[0];

	
}


//Ryan's stuff
//This is the upadate for all Objects (Characters,Items,Traps etc.) on the map
void map::mapUpdate(character * Character)
{
	//Repeat for every Character on the map. currently static 1;
	// will have to iterate through an array of characters
	for (int i = 0; i< 1; i++)
	{
		TestRoom[Character->getY()][Character->getX()] = Character->getGroundSymbol();
		Character->setGroundSymbol(TestRoom[Character->getNextY()][Character->getNextX()]);
		TestRoom[Character->getNextY()][Character->getNextX()] = Character->getSymbol();
	}
}

char map::getTestRoomcell(int x, int y) // some form of this is needed to check for collisions and enemies in adjacent squares
{
	return TestRoom[y][x];
}

void map::printTestRoom() // TEMP Show jack the skits stuff
{
	for (int i = 0; i<height; i++)
	{
		for (int j = 0; j<width; j++)
		{
			cout << getCharacter(TestRoom[i][j]);
		}
		cout << endl;
	}
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
        case 100: return 'X'; // player start pos
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

map::~map()
{
}
