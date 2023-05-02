
all: main

main: connection.o memory.o
	g++ connection.o  memory.o -std=c++20 -o main

connection.o: 
	g++ -c src/connection.cpp include/connection.hpp include/program.hpp -std=c++20

memory.o:
	g++ -c src/memory.cpp -std=c++20

clean: 
	rm -rf *.o main