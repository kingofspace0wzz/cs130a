#include "btree.h"

using namespace std;

node::node(bool leaf){
    this->leaf = leaf;
    this->words = new string[4];
    this->counts = new int[4];
    this->child new node * [5];
    
    this->n = 0; // number of current words is initilized to 0
}

node* node::search(string word){
    int i = 0;
    while (i < this->n && word.compare(this->words[i]) > 0)
        i++;
    if (word.compare(this->words[i]) == 0)
        return this;
    if (leaf == true)
        return nullptr;
    return this->child[i]->search(word);
}

void node::splitChild(int i, node* left){
    node* right = new node(left->leaf);
    node* temp = new node(left->leaf);
    temp = left;

    for (int j = this->n-1; j >= i; --j){
        // move all the elements after i one ahead
        this->words[j+1] = this->words[j];
        this->counts[j+1] = this->words[j];
    }
    this->words[i] = left->words[2];    // copy the third element in the child into position i
    this->counts[i] = left->counts[2];

    delete left;
    right->words[3] = temp->words[3];
    right->counts[3] = temp->counts[3];
    
    for (int j = 0; j<2; ++j){
        left->words[j] = temp->words[j];
        left->counts[j] = temp->word[j];
    }

    if (!temp->leaf) {
        // if the FULL child is not leaf
        for (int j = 0; j<3; ++j){
            left->child[j] = temp->child[j];
        } 
        right->child[0] = temp->child[3];
        right->child[1] = temp->child[4];
    }

    for (int j = this->n; j >= i+1; j--){
        this->child[j+1] = this->child[j];
    }
    this->child[i] = left;
    this->child[i+1] = right;


    this->n++;
}

// the node must be non full
node* node::insertNode(string word){
    int i = this->n - 1; // index of the rightmost element
    if(this->leaf){
        // when inserting into the leaf
        while(i>=0 && this->words[i].compare(word) > 0){
            this->words[i+1] = this->words[i];
            i--;
        }
        this->words[i+1] = word;
        this->n++;
    } else {
        // when inserting into non Leaf node
        // insert the word into the child of the current node
        while(i>=0 && this->words[i].compare(word) > 0)
            // find the approriate child to insert
            i--;
        if (this->child[i+1]->n == 4){
            // if child is FULL
            // split the child and store the mid element into the i+1 location of its parent
            splitChild(i+1, this->child[i+1]);
            if (this->words[i+1].compare(word) < 0)
                i++;
        }
        this->child[i+1]->insertNode(word);
    }
}

void node::traverse(){
    for (int i = 0; i < n; ++i){
        if (!this->leaf){
            // if this is not the leaf
            this->child[i]->traverse();
        }
        // if this is the leaf
        cout << " " << this->words[i];
    }
    if (!this->leaf) // print out the last child
        this->child[n]->traverse();
    cout << endl;
}

void bTree::display(){
    if (root != nullptr)
        root->traverse();
}

void bTree::insert(string word){
    if (root == nullptr){
        root = new node(true);
        root->words[0] = word;
        root->counts[0] = 1;
        root->n = 1;
        return;
    }
    if (root->n == 4){
        // when the root is full
        node* newRoot = new node(false);
        newRoot->child[0] = root;
        newRoot->splitChild(0, root);   // split the original root and store one word into newRoot

        int i = 0;
        if (newRoot->words[0].compare(word) < 0)
            i++;
        newRoot->child[i]->insertNode(word);
    } else {
        // when the root is not full
        // simply insert the word into the root node
        root->insertNode(word);
    }
}

