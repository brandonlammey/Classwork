Lab10: main.o NotFoundException.o DictionaryEntry.o
	g++ -g -std=c++11 main.o NotFoundException.o DictionaryEntry.o -o Lab10

main.o: main.cpp BinarySearchTree.h DictionaryEntry.h NotFoundException.h BinaryNode.h
	g++ -g -std=c++11 -c main.cpp
    
NotFoundException.o: NotFoundException.cpp NotFoundException.h
	g++ -g -std=c++11 -c NotFoundException.cpp
	
DictionaryEntry.o: DictionaryEntry.cpp DictionaryEntry.h
	g++ -g -std=c++11 -c DictionaryEntry.cpp

clean:
	rm *.o Lab10
