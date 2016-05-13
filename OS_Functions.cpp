#ifdef _WIN32
#include <conio.h>
#else// if we are on linux include this
#include <unistd.h>
#include <stdlib.h>
#include <termios.h>
#include <cstdio>
#endif

// Universal Includes
#include <iostream>
#include <cstdlib>

char getKey() { // can be used without assigning return value, e.g. getKey(); or char Key = getKey();
#if _WIN32
	return _getch();
#else
	char buf = 0;
	struct termios old = { 0 };
	fflush(stdout);
	if (tcgetattr(0, &old)<0)
		perror("tcsetattr()");
	old.c_lflag &= ~ICANON;
	old.c_lflag &= ~ECHO;
	old.c_cc[VMIN] = 1;
	old.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSANOW, &old)<0)
		perror("tcsetattr ICANON");
	if (read(0, &buf, 1)<0)
		perror("read()");
	old.c_lflag |= ICANON;
	old.c_lflag |= ECHO;
	if (tcsetattr(0, TCSADRAIN, &old)<0)
		perror("tcsetattr ~ICANON");
	return buf;

#endif
}
void clear_screen()
{
#ifdef WIN32
	std::system("cls");
#else
	// Linux
	std::system("clear");
#endif
}

