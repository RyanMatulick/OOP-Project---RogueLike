# default target is all

# all - compile the program if any source files have changed
all: app

map.o: map.cpp map.h
	g++ -Wall -c map.cpp

OS_Functions.o: OS_Functions.cpp OS_Functions.h
	g++ -Wall -c OS_Functions.cpp

character.o: character.cpp character.h
	g++ -Wall -c character.cpp 

main.o: main.cpp
	g++ -Wall -c main.cpp

app: OS_Functions.o character.o map.o main.o 
	g++ -Wall OS_Functions.o character.o map.o main.o -o app

# clean - delete the compiled version of your program and
# any object files or other temporary files created during compilation.
clean:
	rm -f *.o app
