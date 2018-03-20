#include <string>
#include <iostream>
#include <iostream>
#include <iostream>
#include <sstream>
#include "entry.h"
#include <fstream>

using namespace std;

class BTree {

 public:
    struct Node{
      Entry* words;
      Node** child;
      Node* parent;
      bool leaf;
      int n;
    };
  
  BTree(){
    Node* temp = new BTree::Node;
    temp->n = 0;
    temp->child = new BTree::Node*[5];
    temp->words = new Entry[4];
    temp->words[0] = Entry();
    temp->leaf = true;
    
    root = temp;
  }
  
  ~BTree(){
      clear(root);
  }

void clear(treeNode* node){

  if(!node->leaf){

    for(int i=0; i<=node->n; i++){

      clear(node->child[i]);

      delete node->child[i];

    }

  }



  delete [] node->words;

  

}
  
  void insert(string word);
  
  Node* newNode(){
    Node* newNode = new BTree::Node;
    newNode->n = 0;
    newNode->child = new BTree::Node*[5];
    newNode->words = new Entry[4];
    newNode->words[0] = Entry();
    newNode->leaf = true;
    return newNode;
  }
  Entry* exist(string word, Node* t);

  bool search(string word);
  bool search(string word, Node* t);
  
  void insertNonFull(Entry* entry, Node* node);
  
  void splitChild(Node* node, int i, Node* child);
  
  
  void remove(string word, Node* t);
  void remove(string word){
      remove(word, root);
  }
  
  void sort(std::ofstream & out);
  void sort(std::ofstream& out, Node* t);

  //range search
  void rangeSearch(string start, string end);
  void rangeSearch(string start, string end, Node* t);

 private:
  Node *root;
};