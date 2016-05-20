# default target is all

# all - compile the program if any source files have changed
all: app

map.o: map.cpp map.h
	g++ -std=c++11 -Wall -c map.cpp

OS_Functions.o: OS_Functions.cpp OS_Functions.h
	g++ -std=c++11 -Wall -c OS_Functions.cpp

character.o: character.cpp character.h
	g++ -std=c++11 -Wall -c character.cpp
 
player.o: player.cpp player.h
	g++ -std=c++11 -Wall -c player.cpp

enemy.o: enemy.cpp enemy.h
	g++ -std=c++11 -Wall -c enemy.cpp

main.o: main.cpp
	g++ -std=c++11 -Wall -c main.cpp

app: OS_Functions.o character.o map.o main.o player.o enemy.o
	g++ -std=c++11 -Wall player.o enemy.o OS_Functions.o character.o map.o main.o -o app

# clean - delete the compiled version of your program and
# any object files or other temporary files created during compilation.
clean:
	rm -f *.o app
