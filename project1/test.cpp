#include <iostream>
#include <fstream>
#include <time.h>
#include "bst.h"

using namespace std;

bool isLetters(const string & input){
    for (size_t i = 0; i < input.size()-1; i++){
        if (! isalpha(input[i]))
            return false;
    }
    
    return true;
}

int main(){

    bst t = bst();


    ifstream inf("hotels/beijing/china_beijing_aloft_beijing_haidian");
    int count = 0;
    if (!inf){
        cerr << "shit!!!" << endl;
    
    }
    while(inf){
        bool alpha = true;
        std::string strInput;
        inf >> strInput;
        if (isLetters(strInput)){
            if (!isalpha(strInput[strInput.size()-1])){
                string temp (strInput.begin(), strInput.begin()+strInput.size()-1);
                strInput = temp;
            }
            cout << strInput << endl;   
            count++;
        }else
            continue;
    }
}