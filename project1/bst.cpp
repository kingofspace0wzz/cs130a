#include "bst.h"
#include <iostream>
#include <iostream>
#include <sstream>

using namespace std;

bst::bst(){
  root = nullptr;
}

node* bst::minNode(node* t){
  if (t == nullptr)
    return nullptr;
  if (t->left == nullptr)
    return t;
  else
    return minNode(t->left);
}

node* bst::maxNode(node* t){
  if (t == nullptr)
    return nullptr;
  if (t->right == nullptr)
    return t;
  else
    return maxNode(t->right);
}
node * bst::insert(string word, node* t){
  if (t == nullptr){
    t = new node;
    t->count = 1;
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
  if (search(word)){
    node* temp = search(word, this->root);
    temp->count = temp->count + 1;
  }
  else
  {
  root = insert(word, root);
  }
}

node * bst::deleteNode(string word, node* t){
  node* temp;
  if (t == nullptr)
    return nullptr;
  else if (t->word.compare(word) > 0)
    t->left = deleteNode(word, t->left);
  else if (t->word.compare(word) < 0)
    t->right = deleteNode(word, t->right);
  else if (t->left != nullptr && t->right != nullptr){
    temp = minNode(t->right);
    t->word = temp->word;
    t->count = temp->count;
    t->right = deleteNode(t->word, t->right);
  } else {
    temp = t;
    if (t->left == nullptr)
      t = t->right;
    else if (t->right == nullptr)
      t= t->left;
    delete temp;
  }
  return t;
}

void bst::deleteNode(string word){
  root = deleteNode(string word, root);   
}

node* bst::search(string word, node* t){
  if (t == nullptr) 
    return nullptr;
  if (t->word.compare(word) > 0)
    return search(word, t->left);
  else if (t->word.compare(word) < 0)
    return search(word, t->right);
  else 
    return t;
}

bool bst::search(string word){
  if(search(word, root) == nullptr)
    return false;
  eles
    return true;
}
  
