#include <vector>
#include <iostream>
#include <string>
#include <sstream>

class node{
    int t = 4; //2-5 tree
    std::string* words;
    int* counts;
    node** child;
    int n; // current number of elements in this node
    bool leaf; // true if it is leaf
public:
    node(bool isLeaf);
    node * search(std::string word); // return nullptr if the word is not in the node
    node* insertNode(std::string word); // insert word into the node, if the node is not FULL
    void node* splitChild(int i, node * left);
    void traverse(); 
};

class bTree{
    node* root; // pointer to the root
    int t = 4; // degree
public:
    bTree(int t){
        this->root = nullptr;
        this->t = t;
    }

    // return nullptr if word is not in the tree
    node * search(std::string word) {
        return (root == nullptr) ? nullptr : root->search(word);}
    }

    void insert(std::string word); // insert word into tree
    void display(); // print out all the elements
};