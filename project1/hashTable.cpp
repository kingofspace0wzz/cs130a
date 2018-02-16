#include "hashTable.h"
#include <algorithm>
#include <vector>

using namespace std;

hashTable::~hashTable(){

    delete [] array;
    // delete dummy;
}

int hashTable::hash(string word){   
    StringToLower(word);
    int key = 0; // ASCII value of the string word
    for(unsigned int i=0; i<word.size(); ++i){
        key += word[i];
    }
    return key % this->capacity;
}

int hashTable::hash_double(std::string word){
    StringToLower(word);
    int key = 0; // ASCII value of the string word
    for(unsigned int i=0; i<word.size(); ++i){
        key += word[i];
    }
    return 1 + (key % (capacity - 1));
}

void hashTable::insertEntry(string word){


    StringToLower(word);
    int index = hash(word);
    // int offset = hash_double(word);

    while (array[index] != nullptr && array[index]->flag >= 0 && array[index]->word != word){
        index++;
        index %= this->capacity;  
        
    }
    
    if (array[index] == nullptr || array[index]->flag == -1){
        this->size++;   // increase the table size
        array[index] = new entry(1, word);
    }else
        array[index]->count++;
        
    // while (array[index] != nullptr){
    //     if ()    
    //         index++;
    //         index %= this->capacity;  
        
    // }
    
    // if (array[index] == nullptr || array[index]->flag == -1){
    //     this->size++;   // increase the table size
    //     array[index] = new entry(1, word);
    // }else
    //     array[index]->count++;
        

    return ; 
}

void hashTable::deleteEntry(string word){
    
    StringToLower(word);
    int index = searchIndex(word); // index of the word
    if (index < 0){
        cout << word << " does not exist" << endl;
        return;  
    }
    // when the word appears multiple times, just simple descrease the number it appears
    if (array[index]->count > 1){
        array[index]->count = array[index]->count - 1;
        return;
    }else{  // if the word appears only once, then delete it and insert dummny entry

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
    // int offset = hash_double(word);
    
    while( array[index] != nullptr ){
        if (array[index]->word == word)
            return index;
        index++;
        index %= capacity;
        
    }

    return -1;
}

void hashTable::sortHash(){
    vector<string> elements;
    for(int i = 0; i<this->capacity; ++i){
        if (array[i] != nullptr && array[i]->flag >= 0)
            elements.push_back(array[i]->word);
    }
    sort(elements.begin(), elements.end());
    for (string &s : elements){
        cout << s << endl;
    }
    return; 
}
void hashTable::rangeSearch(string startWord, string endWord){
    StringToLower(startWord);
    StringToLower(endWord);
    
    if (startWord.compare(endWord) <= 0){
        for(int i = 0; i<this->capacity; ++i){
            if (array[i] != nullptr && array[i]->flag >= 0 && array[i]->word.compare(startWord) >= 0 && array[i]->word.compare(endWord) <= 0)
                cout << array[i]->word << endl;
        }
    
        return;
    } else {
        for (int i = 0; i < this->capacity; ++i)
        {
            if (array[i] != nullptr && array[i]->flag >= 0 && array[i]->word.compare(endWord) >= 0 && array[i]->word.compare(startWord) <= 0)
                cout << array[i]->word << endl;
        }
    }

}


// helper functions
void hashTable::StringToLower(string& word){
  for (unsigned int i = 0; i < word.size(); ++i){
    word[i] = tolower(word[i]);
   }
}

void hashTable::print(){
    for (int i = 0; i<this->capacity; ++i){
        if (array[i] != nullptr && array[i]->flag >= 0){
            cout << array[i]->word << ", " << array[i]->count << endl;
        }
    }
    return;
}

int hashTable::getSize(){
    return this->size;
}


// test

// int main(){
//     string str1 = "Carlos";
//     string str2 = "Gerardo";
//     string str3 = "Kamilo";
//     string str4 = "Angel";
//     string str5 = "Bosco";
//     string str6 = "prince";
//     string str7 = "Prince";

//     hashTable table = hashTable();
//     table.insertEntry(str1);
//     table.insertEntry(str2);
//     table.insertEntry(str3);
//     table.insertEntry(str4);
//     table.insertEntry(str5);
//     table.insertEntry(str6);
//     table.insertEntry(str7);
//     table.insertEntry("abc");
//     table.insertEntry("bac");
//     table.insertEntry("acb");
//     table.insertEntry("bca");
//     table.insertEntry("cab");
//     table.insertEntry("cba");
    

//     table.print();

//     table.deleteEntry("prince");
//     cout << "now we delete prince" << endl;
//     table.print();
//     cout << "Does Prince exist?, " << table.search("Prince") << endl;

//     table.deleteEntry("Prince");
//     cout << "delete another prince" << endl;
//     table.print();
//     cout << "Does Prince still exist?, " << table.search("Prince") << endl;

//     return 0;
// }