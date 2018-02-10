#ifndef hashTable_h
#define hashTable_h

#include <iostream>
#include <string>
#include <sstream>

class entry
{
    std::string word;
    int count; // frequency of the word

    int key; 

    // constructor of the entry
    entry(int key, string word){
        this->word = word;
        this->key = key;
        this->count = 1;
    }
};

class hashTable{
    
    entry** array;

    int capacity; // largest size of hashTable
    int size; // current size

public:
    hashTable(){
        capacity = 10000;
        size = 0;
        array = new entry[capacity];
        for(int i = 0; i<capacity; ++i){
            array[i] = nullptr;
        }
    }

    ~hashTable();

    int hash(int key, int index){
        return (hash_one(key) + index*hash_double(key)) % capacity;
    }

    int hash_one(int key){
        return key % capacity;
    }

    int hash_double(int key){
        return 1 + (key % (capacity - 1));
    }

    void insertEntry(std::string word);
    void deleteEntry(std::string word);
    bool search(std::string word);

    void sort();
    void rangeSearch(std::string startWord, std::string endWord);

    
}