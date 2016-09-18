Lab06: main.o PVE.o 
	g++ -std=c++11 -g -Wall main.o PVE.o -o Lab06

main.o: main.cpp Stack.h Node.h StackInterface.h PVE.h
	g++ -std=c++11 -g -Wall -c main.cpp

PVE.o: PVE.h PVE.cpp 
	g++ -std=c++11 -g -Wall -c PVE.cpp 

clean:
	rm *.o Lab06


