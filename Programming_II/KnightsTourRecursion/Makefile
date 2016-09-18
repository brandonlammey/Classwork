Lab07: main.o KnightsTour.o
	g++ -std=c++11 -g -Wall main.o KnightsTour.o -o Lab07

main.o: main.cpp KnightsTour.h
	g++ -std=c++11 -g -Wall -c main.cpp

KnightsTour.o: KnightsTour.h KnightsTour.cpp 
	g++ -std=c++11 -g -Wall -c KnightsTour.cpp 

clean:
	rm *.o Lab07


