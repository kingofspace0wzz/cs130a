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

}

int main(){

  // initialize bst and hashTable
  bst t = bst();
  hashTable table = hashTable();

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

          std::ifstream inf(dir + fileName);
          std::string line;
          while (getline(inf, line))
          {
              replace_if(line.begin(), line.end(), my_predicate, ' ');

              std::istringstream iss(line);
              std::string word;
              while (iss >> word)

                  if (!stopWords.search(word))
                      table.insertEntry(word); // insert word into hashTable
                  else
                      continue;
          }

          inf.close();


          std::ifstream inf2(dir + fileName);
          std::string line2;
          while (getline(inf2, line2))
          {
              replace_if(line2.begin(), line2.end(), my_predicate, ' ');

              std::istringstream iss(line2);
              std::string word;
              while (iss >> word)
                  if (!stopWords.search(word))
                      t.insert(word); // insert word into bst
                  else
                      continue;
          }

          inf2.close();

      }
  }

  // cout << t.num_words() << endl;
    
  while(true){

    //cout << "Pree 1 to do seach; Press 2 to do insert; Press 3 to do delete; Press 4 to do sort; Press 5 to do range search; Press 6 to get the size\n";

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

          bool searchBST;
          bool searchTable;

          // using clock
          clock_t t1, t2;
          t1 = clock();
          searchBST = t.search(word);
          t1 = clock() - t1;

          t2 = clock();
          searchTable = table.search(word);
          t2 = clock() - t2;

        if (searchBST && searchTable){
            cout << "true" << endl;
            cout << t1 << endl;
            cout << "BST: " << ((double)t1)/CLOCKS_PER_SEC << " s" << endl;
            cout << "Hash: " << ((double)t2)/CLOCKS_PER_SEC << " s" << endl;
        }else{ 
            cout << "false" << endl;
            cout << "BST: " << ((double)t1)/CLOCKS_PER_SEC << " s" << endl;
            cout << "Hash: " << ((double)t2)/CLOCKS_PER_SEC << " s" << endl;
        }
          continue;
          }
        case 2:  // insert;
          {
          clock_t t1, t2;
          string word;
          cin >> word;
          
          if (!isLetters(word) || stopWords.search(word)) // the inserted word must be alphabetic and non-stop word
            continue;
          else{
            t1 = clock();
            t.insert(word);
            t1 = clock() - t1;

            t2 = clock();
            table.insertEntry(word);
            t2 = clock() - t2;
          
            cout << "BST: " << ((double)t1)/CLOCKS_PER_SEC << " s" << endl;
            cout << "Hash: " << ((double)t2)/CLOCKS_PER_SEC << " s" << endl;

            continue;
           }
          }
        case 3:  // delete;
          {
          clock_t t1, t2;

          string word;
          cin >> word;
          if (!table.search(word) || !t.search(word))
            continue;
          else{
            t1 = clock();
            t.remove(word);
            t1 = clock() - t1;

            t2 = clock();
            table.deleteEntry(word);
            t2 = clock() - t2;

            cout << "BST: " << ((double)t1)/CLOCKS_PER_SEC << " s" << endl;
            cout << "Hash: " << ((double)t2)/CLOCKS_PER_SEC << " s" << endl;
            continue;
          }
          }
        case 4:  // sort;
          {
          
          ofstream out ("sort.txt");
          clock_t t1, t2;

          t1 = clock();
          t.sort(out);
          t1 = clock() - t1;

          out << "\n" << endl;

          t2 = clock();
          vector<string> sorted = table.sortFile(out);
          for (string& s: sorted){
            out << s << endl;
          }
          t2 = clock() - t2;

          out.close();

          cout << "./sort.txt" << endl;

          cout << "BST: " << ((double)t1)/CLOCKS_PER_SEC << " s" << endl;
          cout << "Hash: " << ((double)t2)/CLOCKS_PER_SEC << " s" << endl;
          continue;
          }
        case 5:  // range search;
          {

          string startWord;
          string endWord;
          cin >> startWord;
          cin >> endWord;
          
          if (!t.search(startWord) || !table.search(startWord) || !t.search(endWord) || !table.search(endWord))
            continue;
          else {
            clock_t t1, t2;

            t1 = clock();
            t.Print(startWord, endWord);
            t1 = clock() - t1;

            cout << "\n" << endl;


            t2 = clock();
            table.rangeSearch(startWord, endWord);
            t2 = clock() - t2;



            t2 = clock();
            table.rangeSearch(startWord, endWord);
            t2 = clock() - t2;

            cout << "BST: " << ((double)t1)/CLOCKS_PER_SEC << " s" << endl;
            cout << "Hash: " << ((double)t2)/CLOCKS_PER_SEC << " s" << endl;
            continue;
          }
          }
        case 6:  // get the size
          {
          cout << "size of bst: " << t.size() << endl;
          cout << "size of table: " << table.getSize() << endl;
          }
        
    }  
  }


}
