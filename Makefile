# default target is all

# all - compile the program if any source files have changed
all: app

OS_Functions.o: OS_Functions.cpp OS_Functions.h
	g++ -std=c++11 -Wall -c OS_Functions.cpp

map.o: map.cpp map.h
	g++ -std=c++11 -Wall -c map.cpp

character.o: character.cpp character.h
	g++ -std=c++11 -Wall -c character.cpp
 
player.o: player.cpp player.h
	g++ -std=c++11 -Wall -c player.cpp

enemy.o: enemy.cpp enemy.h
	g++ -std=c++11 -Wall -c enemy.cpp

item.o: item.cpp item.h
	g++ -std=c++11 -Wall -c item.cpp

potion.o: potion.cpp potion.h
	g++ -std=c++11 -Wall -c potion.cpp

sword.o: sword.cpp sword.h
	g++ -std=c++11 -Wall -c sword.cpp

main.o: main.cpp
	g++ -std=c++11 -Wall -c main.cpp

app: OS_Functions.o map.o character.o player.o enemy.o item.o potion.o sword.o main.o
	g++ -std=c++11 -Wall OS_Functions.o map.o character.o player.o enemy.o item.o potion.o sword.o main.o -o app

# clean - delete the compiled version of your program and
# any object files or other temporary files created during compilation.
clean:
	rm -f *.o app
