#include <iostream>
#include <fstream>
#include <time.h>
#include "bst.h"
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

    bst t = bst();


    ifstream inf("hotels/beijing/china_beijing_aloft_beijing_haidian");
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
            t.insert(word);
    }
    t.display();
    t.remove("you");
    t.remove("zhong");
    t.display();
    t.exist("you");
    t.exist("zhong");
    t.Print();
}