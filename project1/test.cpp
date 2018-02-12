#include <iostream>
#include <fstream>
#include <time.h>
#include "bst.h"
#include "hashTable.h"
#include <sstream>

using namespace std;

bool isLetters(const string & input){
    for (size_t i = 0; i < input.size()-1; i++){
        if (! isalpha(input[i]))
            return false;
    }
    
    return true;
}

bool my_predicate(char c){
    return c == '\'' || !isalpha(c);
}

int main(){


    int bug =0;

    // bst t = bst();
    hashTable table = hashTable();
    string name1 ("hotels/beijing/");
    string name2("china_beijing_aloft_beijing_haidian");
    ifstream inf(name1 + name2);
    int count = 0;
    if (!inf){
        cerr << "shit!!!" << endl;
    
    }


    string line;
    while(getline(inf, line)){
        replace_if(line.begin(), line.end(), my_predicate, ' ');
        
        istringstream iss (line);
        string word;
        while(iss >> word)
            // cout << word << endl;
            // t.insert(word);
            // cout << table.getSize() << endl;
            
            table.insertEntry(word);
            
    }
    // t.display();
    // t.remove("you");
    // t.remove("zhong");
    // t.display();
    
    // t.Print();
    table.print();
    cout << table.getSize() << endl;
}