
all: main

main: connection.o memory.o
	g++ connection.o  memory.o -std=c++20 -o main

connection.o: 
	g++ -c connection.cpp connection.hpp program.hpp

memory.o:
	g++ -c memory.cpp -std=c++20

clean: 
	rm -rf *.o main