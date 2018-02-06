#include <iostream>

#include <string>

template <class T>
struct node{
  int count; // frequency of a word
  T word; // word
  node* left; // left child
  node* right; // right child

}

template <class T>
class bst{
private:
  node<T> *root; // root of bst
public:
  void bst();
  void insert(T word);
  node* insert(T word, node* t);
  node* deleteNode(T word);
  bool search(T word);
  void inorder(node* n);
  void sort();
  void rangeSearch(T word1, T word2);
}
