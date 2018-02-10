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
            cout << word << endl;
    }


    // while(inf){
    //     bool alpha = true;
    //     string strInput;

    //     inf >> strInput;



    //     strInput.erase(remove_if(strInput.begin(),strInput.end(),[](char c) {return !isalpha(c);}), strInput.end());
    //     cout << strInput << endl;
    //     // if (isLetters(strInput)){
    //     //     if (!isalpha(strInput[strInput.size()-1])){
    //     //         string temp (strInput.begin(), strInput.begin()+strInput.size()-1);
    //     //         strInput = temp;
    //     //     }
    //     //     cout << strInput << endl;   
    //     //     count++;
    //     // }else
    //     //     continue;
    // }
}