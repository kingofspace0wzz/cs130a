#include <dirent.h>
#include <cstring>
#include <iostream>
#include <vector>
#include <memory>
#include <sstream>

#include "BTree.cpp"
#include "hashTable.h"
#include <fstream>
#include <string>
#include <time.h>
#include <ctime>
#include <chrono>

using namespace std;


namespace {
  std::vector<std::string> GetDirectoryFiles(const std::string& dir) {
  std::vector<std::string> files;
  std::shared_ptr<DIR> directory_ptr(opendir(dir.c_str()), [](DIR* dir){ dir && closedir(dir); });
  struct dirent *dirent_ptr;
  if (!directory_ptr) {
    std::cout << "Error opening : " << std::strerror(errno) << dir << std::endl;
    return files;
  }
 
  while ((dirent_ptr = readdir(directory_ptr.get())) != nullptr) {
    files.push_back(std::string(dirent_ptr->d_name));
  }
  return files;
}
}  // namespace
 
bool isLetters(const std::string & input){
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

  // initialize bst and hashTable
 
  BTree bt = BTree();

  // read the stopWords file and store stopWords into a hast table
  hashTable stopWords = hashTable(); // hash table to store stop words
  ifstream inf("stopWords.txt");
  while (inf)
  {
      string word;
      inf >> word;
      stopWords.insertEntry(word);
  }

  inf.close();
  // processFiles(t, table);

  vector<string> subfile = {"beijing", "chicago", "dubai", "las-vegas", "london", "montreal", "new-delhi", "new-york-city", "san-francisco", "shanghai"};
  for (vector<string>::iterator it = subfile.begin(); it != subfile.end(); ++it)
  {
      string path = "hotels-small/" + *it;
      const auto &files = GetDirectoryFiles(path);
      for (const auto &file : files)
      {
          if (file == "." || file == "..")
              continue;

          std::string fileName(file);
          std::string dir = path + "/";

          
          std::string line;
          
          


          std::ifstream inf2(dir + fileName);
          std::string line2;
          while (getline(inf2, line2))
          {
              replace_if(line2.begin(), line2.end(), my_predicate, ' ');

              std::istringstream iss(line2);
              std::string word;
              
              iss >> word;
              if(!stopWords.search(word))
                bt.insert(word);
              while (iss >> word){
                  
                
                  if (!stopWords.search(word)){
                       
                      bt.insert(word);
                  }else
                      continue;
              }
          }

          inf2.close();

      }
  }
  while(true){
      int index;
    cin >> index;

    // ignore all the inputs that are not 0 to 5
    if (cin.good() == false || index > 5 || index <= 0){
      //cout << "Type an integer from 1 to 6" << endl;
      continue;
    }
    
    
    switch(index)
    {
        case 1:  // search;
          {
              string word;
                cin >> word; // for user to type the word to be searched
              bool search = bt.exist();
              cout << search << endl;
          }
    }
  }
  return 0;
}