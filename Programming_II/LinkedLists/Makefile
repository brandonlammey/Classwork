Lab03: main.o Node.o LinkedList.o Test_LinkedList.o Test.o
	g++ -std=c++11 -g -Wall main.o Node.o LinkedList.o Test_LinkedList.o Test.o -o Lab03

main.o: main.cpp Test_LinkedList.h
	g++ -std=c++11 -g -Wall -c main.cpp

Node.o: Node.h Node.cpp 
	g++ -std=c++11 -g -Wall -c Node.cpp

LinkedList.o: LinkedList.h LinkedList.cpp Node.h
	g++ -std=c++11 -g -Wall -c LinkedList.cpp

Test_LinkedList.o: Test_LinkedList.h Test_LinkedList.cpp LinkedList.h Test.h
	g++ -std=c++11 -g -Wall -c Test_LinkedList.cpp

Test.o: Test.h Test.cpp
	g++ -std=c++11 -g -Wall -c Test.cpp

clean:
	rm *.o Lab03
