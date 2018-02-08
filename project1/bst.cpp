#include "bst.h"
#include <iostream>
#include <iostream>
#include <sstream>

using namespace std;

bst::bst(){
  root = nullptr;
}

node * bst::insert(string word, node* t){
  if (t == nullptr){
    t = new node;
    t->count++;
    t->word = word;
    t->left = t->right = nullptr;
  }
  else if(x < t->data)
    t->left = insert(x, t->left);

  else if(x > t->data)
    t->right = insert(x, t->right);
  
  return t;
}

void bst::insert(string word){
  root = insert(word, root);
}

node * bst::deleteNode(string word, node* t){
  
}

void bst::deleteNode(string word){
  root = deleteNode(string word, root);  
}

node* bst::search(string word, node* t){
  if (t == nullptr) 
    return nullptr;
  if (t->word.compare(word) < 0)
    return search(word, t->left);
  else if (t->word.compare(word) > 0)
    return search(word, t->right);
  else 
    return t;
}

bool bst::search(string word){
  if(search(word, root) == nullptri)
    return false;
  eles
    return true;
}
  
