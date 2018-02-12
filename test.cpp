#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void to_lower(string& str){
  int length = str.size();
	for (int i = 0; i < length; ++i)
{
    str[i] = tolower(str[i]);
}
  
}

int main(){
	string strInput = "(ABC).Yes";
	strInput.erase(remove_if(strInput.begin(),strInput.end(),[](char c) {return !isalpha(c);}), strInput.end());
  cout << strInput << endl;
	return 0;
}
