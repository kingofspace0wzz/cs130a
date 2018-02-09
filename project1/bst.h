#include <iostream>

#include <string>

//template <class T>
struct node{
  int count; // frequency of a word
  std::string word; // word
  node* left; // left child
  node* right; // right child

};

//template <class T>
class bst{
private:
  node *root; // root of bst
  node* insert(std::string word, node* t);
  node* deleteNode(std::string word, node* t);
  node* search(std::string word, node* t);
  node* minNode(node* t);
  node* maxNode(node* t);
public:
  bst();
  void insert(std::string word);
  void remove(std::string word);
  bool search(std::string word);
  void inorder(node* t);
  void display();
  void sort();
  void rangeSearch(std::string word1, std::string word2);

  void exist(std::string word);
};
