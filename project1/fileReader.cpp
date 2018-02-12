#include <dirent.h>
#include <cstring>
#include <iostream>
#include <vector>
#include <memory>
#include <sstream>
#include "bst.h"
#include "hashTable.h"
#include <fstream>
#include <string>

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

int main() {

  bst t = bst();
  hashTable table = hashTable();
  const auto& directory_path = std::string(".");
  const auto& files = GetDirectoryFiles("hotels-small/beijing");
  for (const auto& file : files) {
    if (file == "." || file == "..")
        continue;
    
    std::string fileName (file);
    std::string dir ("hotels-small/beijing/");
    
    std::ifstream inf(dir + fileName);
    std::string line;
    while(getline(inf, line)){
        replace_if(line.begin(), line.end(), my_predicate, ' ');
        
        std::istringstream iss (line);
        std::string word;
        while(iss >> word)
            // cout << word << endl;
            table.insertEntry(word);
            // t.insert(word);
    }
    std::ifstream inf2(dir + fileName);
    std::string line2;
    while(getline(inf2, line2)){
        replace_if(line2.begin(), line2.end(), my_predicate, ' ');
        
        std::istringstream iss (line2);
        std::string word;
        while(iss >> word)
            // cout << word << endl;
            // table.insertEntry(word);
            t.insert(word);
    }
  }

//   const auto& files2 = GetDirectoryFiles("hotels-small/shanghai");
//   for (const auto& file : files2) {
//     std::cout << file << std::endl;
//   }
//   std::cout << "Bst" << std::endl;
  // t.display();
  std::cout << t.size() << std::endl;
  
  std::cout << "hashTable" << std::endl;
  // table.print(); 
  std::cout << table.getSize() << std::endl; 
  return 0;
}