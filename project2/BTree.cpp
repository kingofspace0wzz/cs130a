#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "entry.h"
#include "BTree.h"

using namespace std;

Entry* BTree::exist(string word, BTree::Node* t){
  int i=0;
  while(i<t->n && word.compare(t->words[i].getWord()) > 0){
    i++;
  }
  if(i < t->n && word.compare(t->words[i].getWord()) == 0){
    return &(t->words[i]);
  }
  if(t->leaf){
    return NULL;
  }
  else{
    return exist(word, t->child[i]);
  }
}

bool BTree::search(string word, BTree::Node* t){
  int i=0;
  while(i<t->n && word.compare(t->words[i].getWord()) > 0){
    i++;
  }
  if(i < t->n && word.compare(t->words[i].getWord()) == 0){
    return true;
  }
  if(t->leaf){
    return false;
  }
  else{
    return search(word, t->child[i]);
  }
}

bool BTree::search(string word){
  return search(word, root);
}

void BTree::sort(ofstream & out){
    sort(out, root);  
}

void BTree::sort(ofstream & out, Node* t){
    int i;
    for (i = 0; i < t->n; i++){
        if (t->leaf == false){
            sort(out, t->child[i]);
        }
        out << t->words[i].getWord() << endl;
    }
    if (t->leaf == false)
        sort(out, t->child[i]);
}

void BTree::rangeSearch(string start, string end, Node* t){
    int i;
    for (i = 0; i < t->n; i++){
        if (t->leaf == false){
            rangeSearch(start, end, t->child[i]);
        }
        if(t->words[i].getWord().compare(start) >= 0 && t->words[i].getWord().compare(end) <= 0)
            cout << t->words[i].getWord() << endl;
    }
    if (t->leaf == false)
        rangeSearch(start, end, t->child[i]);
}

void BTree::rangeSearch(string start, string end){
    rangeSearch(start, end, root);
}

void BTree::insertNonFull(Entry* entry, BTree::Node* node){
  int i = node->n;
  if(node->leaf){ 
    while(i >= 1 &&
	  (entry->getWord().compare(node->words[i].getWord()) < 0 || node->words[i].getWord().length()<1)
	 ){
      if( !(entry->getWord().compare(node->words[i-1].getWord()) < 0) ) break;
      node->words[i] = node->words[i-1];
      node->child[i] = node->child[i-1];
      i--;
     
    }
    Entry newEntry = Entry(entry->getWord(), entry->getCount());
    node->words[i] = newEntry;
    node->n++;
  }
  else{
    while(i >= 1 &&
	  entry->getWord().compare(node->words[i-1].getWord()) < 0)
    {
      i--;
    }
    if(node->child[i]->n == 4){
      splitChild(node, i, node->child[i]);
      if(entry->getWord().compare(node->words[i].getWord()) > 0){
	i++;
      }
    }
    insertNonFull(entry, node->child[i]);
    
  }
  
}

void BTree::splitChild(BTree::Node* node, int index, BTree::Node* child ){
  BTree::Node* child2 = newNode();
  child2->parent = node;
  child2->leaf = child->leaf;
  child2->n = 2;
  for(int j=2; j<4; j++){
    child2->words[j-2] = child->words[j];
    child->words[j] = Entry();
  }
  if(!child->leaf){
    for(int j=2; j<5; j++){
      child2->child[j-2] = child->child[j];
      child->child[j] = NULL;
    }
  }
  child->n = 1;
  for(int j=node->n+1; j>=index+1; j--){
    node->child[j+1] = node->child[j];
  }
  node->child[index+1] = child2;
  for(int j=node->n-1; j>=index; j--){
    node->words[j+1] = node->words[j];
  }
  node->words[index] = child->words[1];
  child->words[1] = Entry();
  node->n += 1;
}


void BTree::insert(string word){
  Entry* result = exist(word, root);
  if(result != NULL){
    result->add();
    return;
  }
  Entry* entry = new Entry(word, 1);
  Node* r = root;
  if(root->n >= 4){
    Node* newRoot = newNode();
    root = newRoot;
    newRoot->leaf = false;
    newRoot->n = 0;
    newRoot->child[0] = r;
    splitChild(root, 0, r);
    insertNonFull(entry, root);
  }
  else{
    insertNonFull(entry, root);
  }
}

void BTree::remove(string word, BTree::Node* t){
  int i = 0;
  while (i <= t->n && word.compare(t->words[i].getWord()) > 0){
    i++;
  }
  if (i <= t->n && word.compare(t->words[i].getWord()) == 0){
    if (t->words[i].getCount() > 1){
      t->words[i].pop();
    }
    if (t->leaf && t->n > 1){
      t->words[i] = Entry();
      t->n--;
    }
    else if (t->child[i]->n > 1){
      Entry temp = t->words[i];
      t->words[i] =  t->child[i]->words[0];
      t->child[i]->words[0] = temp;
      remove(word, t->child[i]);
    }
    else if (t->child[i+1]->n > 1){
      Entry temp = t->words[i];
      t->words[i] =  t->child[i+1]->words[t->child[i+1]->n-1];
      t->child[i+1]->words[t->child[i+1]->n-1] = temp;
      remove(word, t->child[i]);
    }
    else{
      t->child[i]->words[1] = t->words[i];
      t->child[i]->words[2] = t->child[i+1]->words[0];
      t->child[i+1] = NULL;
      t->child[i]->n = 3;
      t->n--;
      remove(word, t->child[i]);
    }
  }
  else{
    if (t->child[i]->n > 1){
      remove(word, t->child[i]);
    }
    else{
      int low = 1;
      int high = 0;
      for (int j = 0; j < 5; j++){
	if (t->child[j]->n > low){
	  low = t->child[j]->n;
	  high = j;
	}
      }
      if (low > 1){
	t->child[i]->words[1] = t->words[i];
	t->words[i] = t->child[high]->words[t->child[high]->n-1];
	t->child[i]->child[2] = t->child[high]->child[t->child[high]->n];
	t->child[i]->n++;
	t->child[high]->n--;
	remove(word, t->child[i]);
      }
      else{
	t->child[i]->words[1] = t->words[i];
	t->child[i]->words[2] = t->child[high]->words[t->child[high]->n-1];
	t->child[high] = NULL;
	t->child[i]->n = 3;
	t->n--;
	remove(word, t->child[i]);
      }
    }
  }
}