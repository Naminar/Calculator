
all: main

main: connection.o memory.o calc.o
	g++ connection.o  memory.o calc.o `wx-config --cxxflags --libs` -std=c++20 -o main
	rm -rf *.o *.gch

calc.o:
	g++ -c src/calc.cpp include/calc.hpp include/connection.hpp include/program.hpp include/memory.hpp `wx-config --cxxflags --libs` -std=c++20

connection.o: 
	g++ -c src/connection.cpp include/connection.hpp include/program.hpp -std=c++20

memory.o:
	g++ -c src/memory.cpp -std=c++20

clean: 
	rm -rf *.o main
