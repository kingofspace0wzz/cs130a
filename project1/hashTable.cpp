#include "hashTable.h"


using namespace std;

hashTable::~hashTable(){

    //stub
}

int hashTable::hash(string word){   
    StringToLower(word);
    int key = 0; // ASCII value of the string word
    for(int i=0; i<word.size(); ++i){
        key += word[i];
    }
    return key % this->capacity;
}

int hash_double(std::string word){
    StringToLower(word);
    int key = 0; // ASCII value of the string word
    for(int i=0; i<word.size(); ++i){
        key += word[i];
    }
    return 1 + (key % (capacity - 1));
}

void hashTable::insertEntry(string word){

    int index = hash(word);

    return ; // stub
}
void hashTable::deleteEntry(string word){
    
    StringToLower(word);
    int index = searchIndex(word); // index of the word
    if (index < 0){
        cout << "word does not exist" << endl;
        return;  
    }
    // when the word appears multiple times, just simple descrease the number it appears
    if (array[index]->count > 1){
        array[index]->count = array[index]->count - 1;
        return;
    }else{  // if the word appears only once, then delete it and insert dummny entry
        entry* temp = array[index];
        array[index] = dummy;
        this->size--;   // the entry has been deleted, so decrease the current size of the table
        return;
    }

    
}

bool hashTable::search(string word){

    StringToLower(word);
    if(searchIndex(word) >= 0)
        return true;
    else 
        return false; 
}

// search the index of a word, return some negative number if it does not exist
int hashTable::searchIndex(string word){
    StringToLower(word);
    int index = hash(word);
    int offset = hash_double(word);
    
    while( array[index] != nullptr ){
        if (array[index]->word == word)
            return index;

        index = (index + offset) % capacity;
        
    }

    return -1;
}

void hashTable::sort(){

    return; // stub
}
void hashTable::rangeSearch(string startWord, string endWord){

    return; // stub
}


// helper functions
void hashTable::StringToLower(string& word){
  for (int i = 0; i < word.size(); ++i){
    word[i] = tolower(word[i]);
   }
}