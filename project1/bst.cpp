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
  else if(t->word.compare(word) >= 0)
    t->left = insert(word, t->left);

  else if(t->word.compare(word) < 0)
    t->right = insert(word, t->right);

  return t;
}

void bst::insert(string word){
  StringToLower(word);
  if (search(word)){
    node* temp = search(word, this->root);
    temp->count = temp->count + 1;
  }
  else
  {
  root = insert(word, root);
  this->num = this->num + 1;
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

void bst::remove(string word){
  StringToLower(word);
  if (search(word)){
    root = deleteNode(word, root);
    this->num = this->num - 1; 
  }else
    cout << word << " does not exist" << endl;
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
  StringToLower(word);
  if(search(word, root) == nullptr){
    return false;
  }else
    return true;
}

void bst::exist(string word){

  if (search(word))
    cout << word << " " << "exists" << endl;
  else
    cout << word << " " << "does not exist" << endl;
}

void sort(){
  return;
}

void bst::inorder(node* t){
  if (t == nullptr)
    return;
  inorder(t->left);
  cout << t->word << ": " << t->count << ", " << endl;
  inorder(t->right);
}

void bst::display(){
  inorder(root);
}


// helper functions
void bst::StringToLower(string& word)
{
  for (int i = 0; i < word.size(); ++i)
{
    word[i] = tolower(word[i]);
}
}


int main(){
  string str1 = "Carlos";
  string str2 = "Gerardo";
  string str3 = "Kamilo";
  string str4 = "Angel";
  string str5 = "Bosco";
  string str6 = "prince";
  string str7 = "Prince";

  bst t = bst();
  t.insert(str1);
  t.insert(str2);
  t.insert(str3);
  t.insert(str4);
  t.insert(str5);
  t.insert(str6);
  t.insert(str7);

  t.insert(str2);
  t.insert(str3);
  t.insert(str4);

  t.display();
  printf("the size is: %d", t.size());
  return 0;
}
