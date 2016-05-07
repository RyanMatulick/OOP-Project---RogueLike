#include <iostream>
#include <unistd.h>   //_getch
#include <termios.h>  //_getch
#include <cstdio> // getch
#include <cstdlib> // clear screen

char getch();
void clear_screen();

using namespace std;

int main()
{
	char Answer = getch();
	cout << "You're input is: " << Answer << endl;
	char Answer2 = getch();
	clear_screen();
	cout << "You're input is: " << Answer2 << endl;
}


char getch(){
    
    char buf=0;
    struct termios old={0};
    fflush(stdout);
    if(tcgetattr(0, &old)<0)
        perror("tcsetattr()");
    old.c_lflag&=~ICANON;
    old.c_lflag&=~ECHO;
    old.c_cc[VMIN]=1;
    old.c_cc[VTIME]=0;
    if(tcsetattr(0, TCSANOW, &old)<0)
        perror("tcsetattr ICANON");
    if(read(0,&buf,1)<0)
        perror("read()");
    old.c_lflag|=ICANON;
    old.c_lflag|=ECHO;
    if(tcsetattr(0, TCSADRAIN, &old)<0)
        perror ("tcsetattr ~ICANON");
    return buf;
 }


void clear_screen()
{
#ifdef WINDOWS
    std::system("cls");
#else
    // Assume POSIX
    std::system ("clear");
#endif
}