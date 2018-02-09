#include <iostream>
#include <string>

using namespace std;

void to_lower(string& str){
  int length = str.size();
	for (int i = 0; i < length; ++i)
{
    str[i] = tolower(str[i]);
}
  
}

int main(){
	string str1 = "ABC";
	to_lower(str1);
  cout << str1 << endl;
	return 0;
}
