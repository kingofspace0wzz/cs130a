#include <iostream>

#include <string>

//template <class T>
struct node{
  int count; // frequency of a word
  std::string word; // word
  node* left; // left child
  node* right; // right child

}

//template <class T>
class bst{
private:
  node *root; // root of bst
  node* insert(std::string word, node* t);
  node* deleteNode(std::string word);
  node* search(std::string word, node* t);
public:
  void bst();
  void insert(std::string word);
  void deleteNode(std::string word);
  node* search(std::string word);
  void inorder(node* n);
  void sort();
  void rangeSearch(std::string word1, std::string word2);
}
