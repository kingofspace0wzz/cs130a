
CXX = g++

CXXFLAGS = -Wall -g



main: main.o hashTable.o bst.o

	$(CXX) $(CXXFLAGS) -o main main.o hashTable.o bst.o



main.o: main.cpp hashTable.h bst.h

	$(CXX) $(CXXFLAGS) -c main.cpp



hashTable.o: hashTable.h 


bst.o: bst.h



clean:

	rm -rf *.o main