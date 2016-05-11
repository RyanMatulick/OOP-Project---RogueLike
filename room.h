
#ifndef ROOM_H
#define ROOM_H
using namespace std;

class room
{
public:
    room(int xPosIn, int yPosIn, char * worldMapIn[10][10], int height, int width, int roomNumberIn);
    void generateRoom(); // fill the room up with stuff
    void drawRoom();
    void printRoom(int roomNumber);
    int getRoomNumber();

    int xPos, yPos; //map coordinates
    char * worldMap[10][10]; //copy of the map

    char * roomMap[80][40]; //the rooms - what we actually draw

    int roomNumber;

    room(const room &old);

    ~room();

private:

};
#endif
