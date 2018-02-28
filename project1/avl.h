#include <iostream>
#include <algorithm>
#include <string>

//template <class T>
struct node
{
    int count;        // frequency of a word
    std::string word; // word
    node *left;       // left child
    node *right;      // right child

    int height; // height of the current node
};

//template <class T>
class avl
{
private:
    node *root;    // root of bst
    int num = 0;   // total number of words
    int sizes = 0; // total numer of nodes
    node *insert(std::string word, node *t);
    node *deleteNode(std::string word, node *t);
    node *search(std::string word, node *t);
    node *minNode(node *t);
    node *maxNode(node *t);

    void sort(node *t, std::ofstream &out);

public:
    avl();
    ~avl();
    void free(node *t); // help desctructor free memory

    void insert(std::string word);
    void remove(std::string word);
    bool search(std::string word);
    void inorder(node *t);
    void display();

    // avl utility functions
    int balance(node * t);
    int height(node * t);
    node* leftRotate(node * y);
    node* rightRotate(node * y);


    void sort(std::ofstream &out);

    void rangeSearch(std::string word1, std::string word2, node *t);
    void Print(std::string startWord, std::string endWord);

    void exist(std::string word);

    void StringToLower(std::string &word);

    int size() { return this->sizes; }

    int num_words() { return this->num; }
};
