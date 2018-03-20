#ifndef ENTRY_H
#define ENTRY_H

#include <string>

using namespace std;

class Entry {
 private:
  string word;
  int count;
 public:

  Entry(string word, int count) {
    this->word = word;
    this->count = count;
  }

  Entry(){
    word = "";
    count = 0;
  }

  string getWord(){
    return word;
  }

  int getCount(){
    return count;
  }

  void add(){ count += 1; }
  void pop(){ count -= 1; }

};

#endif