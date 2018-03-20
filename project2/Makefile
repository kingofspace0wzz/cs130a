CXX = g++
CXXFLAGS = -Wall -g

main: main.o hashTable.o BTree.o avl.o
	$(CXX) $(CXXFLAGS) -o main main.o hashTable.o BTree.o avl.o

main.o: main.cpp hashTable.h BTree.h avl.h
	$(CXX) $(CXXFLAGS) -c main.cpp

hashTable.o: hashTable.h 

BTree.o: BTree.h

avl.o: avl.h

clean:
	rm -rf *.o main