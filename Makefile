# default target is all

# all - compile the program if any source files have changed
all: app

map.o: map.cpp map.h
	g++ -Wall -c map.cpp

main.o: main.cpp
	g++ -Wall -c main.cpp

app: map.o main.o
	g++ -Wall map.o main.o -o app

# clean - delete the compiled version of your program and
# any object files or other temporary files created during compilation.
clean:
	rm -f *.o app
