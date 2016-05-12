#include "room.h"

using namespace std;

room::room(int xPosIn, int yPosIn, char * worldMapIn[10][10], int height, int width, int roomNumberIn)
{
    char * worldMap[10][10]; //copy of the map
    char * roomLayout[80][40]; //the rooms - what we actually draw

    xPos = xPosIn;
    yPos = yPosIn;
    for(int i = 0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            worldMap[i][j] = worldMapIn[i][j];
        }
    }
    roomNumber = roomNumberIn;

    generateRoom();
}

room::room(const room &old) //reinitialize everything when we copy rooms around
{
    xPos=old.xPos;
    yPos=old.yPos;

    for(int i=0; i<80;i++)
    {
        for(int j=0; j<40; j++)
        {
            roomLayout[i][j] = old.roomLayout[i][j];
        }
    }


    for(int i=0; i<80;i++)
    {
        for(int j=0; j<40; j++)
        {
            worldMap[i][j] = old.worldMap[i][j];
        }
    }

    roomNumber = old.roomNumber;
}


void room::generateRoom()
{
    for(int i=0; i<40;i++)
    {
        for(int j=0; j<80; j++)
        {
            if(i==0 || i==39 || j==0 || j==79)
            {
                *roomLayout[i][j]='#';
            }
            else
            {
                *roomLayout[i][j]='.';
            }
        }
    }
}

void room::drawRoom()
{
    cout << "room number is: " << roomNumber << endl;

    for(int i=0; i<40;i++)
    {
        for(int j=0; j<80; j++)
        {
            cout << roomLayout[i][j];
        }
        cout << endl;
    }
}

int room::getRoomNumber()
{

}

room::~room()
{
    delete worldMap;
}
