Lab04: main.o PreconditionViolationException.o Test_Stack.o Test.o
	g++ -std=c++11 -g -Wall main.o PreconditionViolationException.o Test_Stack.o Test.o -o Lab04

main.o: main.cpp Stack.h Test_Stack.h Node.h StackInterface.h PreconditionViolationException.h
	g++ -std=c++11 -g -Wall -c main.cpp

PreconditionViolationException.o: PreconditionViolationException.h PreconditionViolationException.cpp 
	g++ -std=c++11 -g -Wall -c PreconditionViolationException.cpp 

Test.o: Test.cpp Test.h 
	g++ -std=c++11 -g -Wall -c Test.cpp

Test_Stack.o: Test_Stack.cpp Test_Stack.h Test.h Stack.h
	g++ -std=c++11 -g -Wall -c Test_Stack.cpp

clean:
	rm *.o Lab04


