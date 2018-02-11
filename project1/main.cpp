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
#include <time.h>


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



void processFiles(bst t, hashTable table){

  // Beijing
  const auto& files_beijing = GetDirectoryFiles("hotels-small/beijing");
  for (const auto& file : files_beijing) {
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
            
            table.insertEntry(word);  // insert word into hashTable
            
    }
    std::ifstream inf2(dir + fileName);
    std::string line2;
    while(getline(inf2, line2)){
        replace_if(line2.begin(), line2.end(), my_predicate, ' ');
        
        std::istringstream iss (line2);
        std::string word;
        while(iss >> word)
            
            t.insert(word);   // insert word into bst
    }
  }

  // // Chicago
  // const auto& files_chicago = GetDirectoryFiles("hotels-small/chicago");
  // for (const auto& file : files_chicago) {
  //   if (file == "." || file == "..")
  //       continue;
    
  //   std::string fileName (file);
  //   std::string dir ("hotels-small/chicago/");
    
  //   std::ifstream inf(dir + fileName);
  //   std::string line;
  //   while(getline(inf, line)){
  //       replace_if(line.begin(), line.end(), my_predicate, ' ');
        
  //       std::istringstream iss (line);
  //       std::string word;
  //       while(iss >> word)
            
  //           table.insertEntry(word);  // insert word into hashTable
            
  //   }
  //   std::ifstream inf2(dir + fileName);
  //   std::string line2;
  //   while(getline(inf2, line2)){
  //       replace_if(line2.begin(), line2.end(), my_predicate, ' ');
        
  //       std::istringstream iss (line2);
  //       std::string word;
  //       while(iss >> word)
            
  //           t.insert(word);   // insert word into bst
  //   }
  // }

  // // dubai
  // const auto& files_dubai = GetDirectoryFiles("hotels-small/dubai");
  // for (const auto& file : files_dubai) {
  //   if (file == "." || file == "..")
  //       continue;
    
  //   std::string fileName (file);
  //   std::string dir ("hotels-small/dubai/");
    
  //   std::ifstream inf(dir + fileName);
  //   std::string line;
  //   while(getline(inf, line)){
  //       replace_if(line.begin(), line.end(), my_predicate, ' ');
        
  //       std::istringstream iss (line);
  //       std::string word;
  //       while(iss >> word)
            
  //           table.insertEntry(word);  // insert word into hashTable
            
  //   }
  //   std::ifstream inf2(dir + fileName);
  //   std::string line2;
  //   while(getline(inf2, line2)){
  //       replace_if(line2.begin(), line2.end(), my_predicate, ' ');
        
  //       std::istringstream iss (line2);
  //       std::string word;
  //       while(iss >> word)
            
  //           t.insert(word);   // insert word into bst
  //   }
  // }

  // // las-vegas
  // const auto& files_las = GetDirectoryFiles("hotels-small/las-vegas");
  // for (const auto& file : files_las) {
  //   if (file == "." || file == "..")
  //       continue;
    
  //   std::string fileName (file);
  //   std::string dir ("hotels-small/las-vegas/");
    
  //   std::ifstream inf(dir + fileName);
  //   std::string line;
  //   while(getline(inf, line)){
  //       replace_if(line.begin(), line.end(), my_predicate, ' ');
        
  //       std::istringstream iss (line);
  //       std::string word;
  //       while(iss >> word)
            
  //           table.insertEntry(word);  // insert word into hashTable
            
  //   }
  //   std::ifstream inf2(dir + fileName);
  //   std::string line2;
  //   while(getline(inf2, line2)){
  //       replace_if(line2.begin(), line2.end(), my_predicate, ' ');
        
  //       std::istringstream iss (line2);
  //       std::string word;
  //       while(iss >> word)
            
  //           t.insert(word);   // insert word into bst
  //   }
  // }

  // // london
  // const auto& files_london = GetDirectoryFiles("hotels-small/london");
  // for (const auto& file : files_london) {
  //   if (file == "." || file == "..")
  //       continue;
    
  //   std::string fileName (file);
  //   std::string dir ("hotels-small/london/");
    
  //   std::ifstream inf(dir + fileName);
  //   std::string line;
  //   while(getline(inf, line)){
  //       replace_if(line.begin(), line.end(), my_predicate, ' ');
        
  //       std::istringstream iss (line);
  //       std::string word;
  //       while(iss >> word)
            
  //           table.insertEntry(word);  // insert word into hashTable
            
  //   }
  //   std::ifstream inf2(dir + fileName);
  //   std::string line2;
  //   while(getline(inf2, line2)){
  //       replace_if(line2.begin(), line2.end(), my_predicate, ' ');
        
  //       std::istringstream iss (line2);
  //       std::string word;
  //       while(iss >> word)
            
  //           t.insert(word);   // insert word into bst
  //   }
  // }

  // // montreal
  // const auto& files_montreal = GetDirectoryFiles("hotels-small/montreal");
  // for (const auto& file : files_montreal) {
  //   if (file == "." || file == "..")
  //       continue;
    
  //   std::string fileName (file);
  //   std::string dir ("hotels-small/montreal/");
    
  //   std::ifstream inf(dir + fileName);
  //   std::string line;
  //   while(getline(inf, line)){
  //       replace_if(line.begin(), line.end(), my_predicate, ' ');
        
  //       std::istringstream iss (line);
  //       std::string word;
  //       while(iss >> word)
            
  //           table.insertEntry(word);  // insert word into hashTable
            
  //   }
  //   std::ifstream inf2(dir + fileName);
  //   std::string line2;
  //   while(getline(inf2, line2)){
  //       replace_if(line2.begin(), line2.end(), my_predicate, ' ');
        
  //       std::istringstream iss (line2);
  //       std::string word;
  //       while(iss >> word)
            
  //           t.insert(word);   // insert word into bst
  //   }
  // }

  // // new-delhi
  // const auto& files_delhi = GetDirectoryFiles("hotels-small/new-delhi");
  // for (const auto& file : files_delhi) {
  //   if (file == "." || file == "..")
  //       continue;
    
  //   std::string fileName (file);
  //   std::string dir ("hotels-small/new-delhi/");
    
  //   std::ifstream inf(dir + fileName);
  //   std::string line;
  //   while(getline(inf, line)){
  //       replace_if(line.begin(), line.end(), my_predicate, ' ');
        
  //       std::istringstream iss (line);
  //       std::string word;
  //       while(iss >> word)
            
  //           table.insertEntry(word);  // insert word into hashTable
            
  //   }
  //   std::ifstream inf2(dir + fileName);
  //   std::string line2;
  //   while(getline(inf2, line2)){
  //       replace_if(line2.begin(), line2.end(), my_predicate, ' ');
        
  //       std::istringstream iss (line2);
  //       std::string word;
  //       while(iss >> word)
            
  //           t.insert(word);   // insert word into bst
  //   }
  // }

  // // new-york-city
  // const auto& files_ny = GetDirectoryFiles("hotels-small/new-york-city");
  // for (const auto& file : files_ny) {
  //   if (file == "." || file == "..")
  //       continue;
    
  //   std::string fileName (file);
  //   std::string dir ("hotels-small/new-york-city/");
    
  //   std::ifstream inf(dir + fileName);
  //   std::string line;
  //   while(getline(inf, line)){
  //       replace_if(line.begin(), line.end(), my_predicate, ' ');
        
  //       std::istringstream iss (line);
  //       std::string word;
  //       while(iss >> word)
            
  //           table.insertEntry(word);  // insert word into hashTable
            
  //   }
  //   std::ifstream inf2(dir + fileName);
  //   std::string line2;
  //   while(getline(inf2, line2)){
  //       replace_if(line2.begin(), line2.end(), my_predicate, ' ');
        
  //       std::istringstream iss (line2);
  //       std::string word;
  //       while(iss >> word)
            
  //           t.insert(word);   // insert word into bst
  //   }
  // }

  // // san-francisco
  // const auto& files_sf = GetDirectoryFiles("hotels-small/san-francisco");
  // for (const auto& file : files_sf) {
  //   if (file == "." || file == "..")
  //       continue;
    
  //   std::string fileName (file);
  //   std::string dir ("hotels-small/san-francisco/");
    
  //   std::ifstream inf(dir + fileName);
  //   std::string line;
  //   while(getline(inf, line)){
  //       replace_if(line.begin(), line.end(), my_predicate, ' ');
        
  //       std::istringstream iss (line);
  //       std::string word;
  //       while(iss >> word)
            
  //           table.insertEntry(word);  // insert word into hashTable
            
  //   }
  //   std::ifstream inf2(dir + fileName);
  //   std::string line2;
  //   while(getline(inf2, line2)){
  //       replace_if(line2.begin(), line2.end(), my_predicate, ' ');
        
  //       std::istringstream iss (line2);
  //       std::string word;
  //       while(iss >> word)
            
  //           t.insert(word);   // insert word into bst
  //   }
  // }

  // // shanghai
  // const auto& files_shanghai = GetDirectoryFiles("hotels-small/shanghai");
  // for (const auto& file : files_shanghai) {
  //   if (file == "." || file == "..")
  //       continue;
    
  //   std::string fileName (file);
  //   std::string dir ("hotels-small/shanghai/");
    
  //   std::ifstream inf(dir + fileName);
  //   std::string line;
  //   while(getline(inf, line)){
  //       replace_if(line.begin(), line.end(), my_predicate, ' ');
        
  //       std::istringstream iss (line);
  //       std::string word;
  //       while(iss >> word)
            
  //           table.insertEntry(word);  // insert word into hashTable
            
  //   }
  //   std::ifstream inf2(dir + fileName);
  //   std::string line2;
  //   while(getline(inf2, line2)){
  //       replace_if(line2.begin(), line2.end(), my_predicate, ' ');
        
  //       std::istringstream iss (line2);
  //       std::string word;
  //       while(iss >> word)
            
  //           t.insert(word);   // insert word into bst
  //   }
  // }
}




int main(){
  
  clock_t t1,t2; // clock to measure the running time of each operation


  // initialize bst and hashTable
  bst t = bst();
  hashTable table = hashTable();

  // processFiles(t, table);

  // process to read files and build bst & hash table
  const auto& files_beijing = GetDirectoryFiles("hotels-small/beijing");
  for (const auto& file : files_beijing) {
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
            
            table.insertEntry(word);  // insert word into hashTable
            
    }
    std::ifstream inf2(dir + fileName);
    std::string line2;
    while(getline(inf2, line2)){
        replace_if(line2.begin(), line2.end(), my_predicate, ' ');
        
        std::istringstream iss (line2);
        std::string word;
        while(iss >> word)
            
            t.insert(word);   // insert word into bst
    }
  }

  // Chicago
  const auto& files_chicago = GetDirectoryFiles("hotels-small/chicago");
  for (const auto& file : files_chicago) {
    if (file == "." || file == "..")
        continue;
    
    std::string fileName (file);
    std::string dir ("hotels-small/chicago/");
    
    std::ifstream inf(dir + fileName);
    std::string line;
    while(getline(inf, line)){
        replace_if(line.begin(), line.end(), my_predicate, ' ');
        
        std::istringstream iss (line);
        std::string word;
        while(iss >> word)
            
            table.insertEntry(word);  // insert word into hashTable
            
    }
    std::ifstream inf2(dir + fileName);
    std::string line2;
    while(getline(inf2, line2)){
        replace_if(line2.begin(), line2.end(), my_predicate, ' ');
        
        std::istringstream iss (line2);
        std::string word;
        while(iss >> word)
            
            t.insert(word);   // insert word into bst
    }
  }

  // dubai
  const auto& files_dubai = GetDirectoryFiles("hotels-small/dubai");
  for (const auto& file : files_dubai) {
    if (file == "." || file == "..")
        continue;
    
    std::string fileName (file);
    std::string dir ("hotels-small/dubai/");
    
    std::ifstream inf(dir + fileName);
    std::string line;
    while(getline(inf, line)){
        replace_if(line.begin(), line.end(), my_predicate, ' ');
        
        std::istringstream iss (line);
        std::string word;
        while(iss >> word)
            
            table.insertEntry(word);  // insert word into hashTable
            
    }
    std::ifstream inf2(dir + fileName);
    std::string line2;
    while(getline(inf2, line2)){
        replace_if(line2.begin(), line2.end(), my_predicate, ' ');
        
        std::istringstream iss (line2);
        std::string word;
        while(iss >> word)
            
            t.insert(word);   // insert word into bst
    }
  }

  // las-vegas
  const auto& files_las = GetDirectoryFiles("hotels-small/las-vegas");
  for (const auto& file : files_las) {
    if (file == "." || file == "..")
        continue;
    
    std::string fileName (file);
    std::string dir ("hotels-small/las-vegas/");
    
    std::ifstream inf(dir + fileName);
    std::string line;
    while(getline(inf, line)){
        replace_if(line.begin(), line.end(), my_predicate, ' ');
        
        std::istringstream iss (line);
        std::string word;
        while(iss >> word)
            
            table.insertEntry(word);  // insert word into hashTable
            
    }
    std::ifstream inf2(dir + fileName);
    std::string line2;
    while(getline(inf2, line2)){
        replace_if(line2.begin(), line2.end(), my_predicate, ' ');
        
        std::istringstream iss (line2);
        std::string word;
        while(iss >> word)
            
            t.insert(word);   // insert word into bst
    }
  }

  // london
  const auto& files_london = GetDirectoryFiles("hotels-small/london");
  for (const auto& file : files_london) {
    if (file == "." || file == "..")
        continue;
    
    std::string fileName (file);
    std::string dir ("hotels-small/london/");
    
    std::ifstream inf(dir + fileName);
    std::string line;
    while(getline(inf, line)){
        replace_if(line.begin(), line.end(), my_predicate, ' ');
        
        std::istringstream iss (line);
        std::string word;
        while(iss >> word)
            
            table.insertEntry(word);  // insert word into hashTable
            
    }
    std::ifstream inf2(dir + fileName);
    std::string line2;
    while(getline(inf2, line2)){
        replace_if(line2.begin(), line2.end(), my_predicate, ' ');
        
        std::istringstream iss (line2);
        std::string word;
        while(iss >> word)
            
            t.insert(word);   // insert word into bst
    }
  }

  // montreal
  const auto& files_montreal = GetDirectoryFiles("hotels-small/montreal");
  for (const auto& file : files_montreal) {
    if (file == "." || file == "..")
        continue;
    
    std::string fileName (file);
    std::string dir ("hotels-small/montreal/");
    
    std::ifstream inf(dir + fileName);
    std::string line;
    while(getline(inf, line)){
        replace_if(line.begin(), line.end(), my_predicate, ' ');
        
        std::istringstream iss (line);
        std::string word;
        while(iss >> word)
            
            table.insertEntry(word);  // insert word into hashTable
            
    }
    std::ifstream inf2(dir + fileName);
    std::string line2;
    while(getline(inf2, line2)){
        replace_if(line2.begin(), line2.end(), my_predicate, ' ');
        
        std::istringstream iss (line2);
        std::string word;
        while(iss >> word)
            
            t.insert(word);   // insert word into bst
    }
  }

  // new-delhi
  const auto& files_delhi = GetDirectoryFiles("hotels-small/new-delhi");
  for (const auto& file : files_delhi) {
    if (file == "." || file == "..")
        continue;
    
    std::string fileName (file);
    std::string dir ("hotels-small/new-delhi/");
    
    std::ifstream inf(dir + fileName);
    std::string line;
    while(getline(inf, line)){
        replace_if(line.begin(), line.end(), my_predicate, ' ');
        
        std::istringstream iss (line);
        std::string word;
        while(iss >> word)
            
            table.insertEntry(word);  // insert word into hashTable
            
    }
    std::ifstream inf2(dir + fileName);
    std::string line2;
    while(getline(inf2, line2)){
        replace_if(line2.begin(), line2.end(), my_predicate, ' ');
        
        std::istringstream iss (line2);
        std::string word;
        while(iss >> word)
            
            t.insert(word);   // insert word into bst
    }
  }

  // new-york-city
  const auto& files_ny = GetDirectoryFiles("hotels-small/new-york-city");
  for (const auto& file : files_ny) {
    if (file == "." || file == "..")
        continue;
    
    std::string fileName (file);
    std::string dir ("hotels-small/new-york-city/");
    
    std::ifstream inf(dir + fileName);
    std::string line;
    while(getline(inf, line)){
        replace_if(line.begin(), line.end(), my_predicate, ' ');
        
        std::istringstream iss (line);
        std::string word;
        while(iss >> word)
            
            table.insertEntry(word);  // insert word into hashTable
            
    }
    std::ifstream inf2(dir + fileName);
    std::string line2;
    while(getline(inf2, line2)){
        replace_if(line2.begin(), line2.end(), my_predicate, ' ');
        
        std::istringstream iss (line2);
        std::string word;
        while(iss >> word)
            
            t.insert(word);   // insert word into bst
    }
  }

  // san-francisco
  const auto& files_sf = GetDirectoryFiles("hotels-small/san-francisco");
  for (const auto& file : files_sf) {
    if (file == "." || file == "..")
        continue;
    
    std::string fileName (file);
    std::string dir ("hotels-small/san-francisco/");
    
    std::ifstream inf(dir + fileName);
    std::string line;
    while(getline(inf, line)){
        replace_if(line.begin(), line.end(), my_predicate, ' ');
        
        std::istringstream iss (line);
        std::string word;
        while(iss >> word)
            
            table.insertEntry(word);  // insert word into hashTable
            
    }
    std::ifstream inf2(dir + fileName);
    std::string line2;
    while(getline(inf2, line2)){
        replace_if(line2.begin(), line2.end(), my_predicate, ' ');
        
        std::istringstream iss (line2);
        std::string word;
        while(iss >> word)
            
            t.insert(word);   // insert word into bst
    }
  }

  // shanghai
  const auto& files_shanghai = GetDirectoryFiles("hotels-small/shanghai");
  for (const auto& file : files_shanghai) {
    if (file == "." || file == "..")
        continue;
    
    std::string fileName (file);
    std::string dir ("hotels-small/shanghai/");
    
    std::ifstream inf(dir + fileName);
    std::string line;
    while(getline(inf, line)){
        replace_if(line.begin(), line.end(), my_predicate, ' ');
        
        std::istringstream iss (line);
        std::string word;
        while(iss >> word)
            
            table.insertEntry(word);  // insert word into hashTable
            
    }
    std::ifstream inf2(dir + fileName);
    std::string line2;
    while(getline(inf2, line2)){
        replace_if(line2.begin(), line2.end(), my_predicate, ' ');
        
        std::istringstream iss (line2);
        std::string word;
        while(iss >> word)
            
            t.insert(word);   // insert word into bst
    }
  }


  
  
  
  
  
  while(true){

    cout << "Pree 1 to do seach; Press 2 to do insert; Press 3 to do delete; Press 4 to do sort; Press 5 to do range search; Press 6 to get the size\n";

    int index;
    cin >> index;
    if (cin.good() == false || index > 6 || index <= 0){
      cout << "Type an integer from 1 to 6" << endl;
      continue;
    }
    switch(index)
    {
        case 1:  // search;
          {
            string word;
          cin >> word; // for user to type the word to be searched
          if (t.search(word) && table.search(word))
            cout << "true" << endl;
          else 
            cout << "false" << endl;
          continue;
          }
        case 2:  // insert;
          {
          string word;
          cin >> word;
          t.insert(word);
          table.insertEntry(word);
          continue;
          }
        case 3:  // delete;
          {
          string word;
          cin >> word;
          t.remove(word);
          table.deleteEntry(word);
          continue;
          }
        case 4:  // sort;
          {
          t.sort();
          table.sortHash();
          continue;
          }
        case 5:  // range search;
          {
          string startWord;
          string endWord;
          cin >> startWord;
          cin >> endWord;
          t.Print(startWord, endWord);
          table.rangeSearch(startWord, endWord);
          continue;
          }
        case 6:  // get the size
          {
          cout << "size of bst: " << t.size() << endl;
          cout << "size of table: " << table.getSize() << endl;
          }
        
    }  
  }


}