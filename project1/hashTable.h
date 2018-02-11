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

    bool flag = false; // true if the entry here has been deleted, don't forget to set it back to true if something is inserted here.

    // constructor of the entry
    entry(int key, string word){
        this->word = word;
        this->key = key;
        this->count = 1;
    }
};

class hashTable{
    
    entry** array;
    
    entry* dummy;  // dummy is a dead entry with key value less than 0
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

        dummy = new entry(-1, "dummy");
    }

    ~hashTable();

    // function for linear probing
    int hash(std::string word);


    // functions for double hashing
    // int hash(int key, int index){
    //     return (hash_one(key) + index*hash_double(key)) % capacity;
    // }

    // int hash_one(int key){
    //     return key % capacity;
    // }

    int hash_double(std::string word);

    void insertEntry(std::string word);
    void deleteEntry(std::string word);
    bool search(std::string word);

    void sort();
    void rangeSearch(std::string startWord, std::string endWord);

    
    // helper functions
    void StringToLower(std::string& word);

}