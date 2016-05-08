#ifndef CHARACTER_H
#define CHARACTER_H

class character
{
private:
	
	char Symbol;
	char GroundSymbol; // saves the symbol of the space the player is about to move onto;

	int xCurrent;
	int yCurrent;
	int xNext;
	int yNext;
	

public:
	character(char Symbol, int xCurrent, int yCurrent);
	void getTurn();

	
	char getSymbol();
	char getGroundSymbol();
	int getX(); // get Characters x coordinate
	int getY(); // get Characters y coordinate
	int getNextX(); // get Characters x coordinate
	int getNextY(); // get Characters y coordinate
	void setGroundSymbol(char GSymbol);
	void setX(int ixLocation);
	void setY(int ixLocation);
	void setNextX(int ixLocation);
	void setNextY(int ixLocation);

	~character();


};


#endif // !CHARACTER_H
