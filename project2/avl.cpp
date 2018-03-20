#include "avl.h"
#include <iostream>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

int maxHeight(int a, int b){
    if (a >= b)
        return a;
    else
        return b;
}

int avl::getheight(node * t){
    if (t == nullptr)
        return 0;
    return t->height;
}
avl::avl(){
  root = nullptr;
}

avl::~avl(){
  free(root);
}

void avl::free(node* t){
  if (t->left != nullptr)
    free(t->left);
  if (t->right != nullptr)
    free(t->right);
  delete t;
}

node* avl::minNode(node* t){
  if (t == nullptr)
    return nullptr;
  if (t->left == nullptr)
    return t;
  else
    return minNode(t->left);
}

node* avl::maxNode(node* t){
  if (t == nullptr)
    return nullptr;
  if (t->right == nullptr)
    return t;
  else
    return maxNode(t->right);
}


node* avl::rightRotate(node* y){
    node* x = y->left;
    node* z = x->right;

    x->right = y;
    y->left = z;
    
    // x->parent = y->parent;
    // y->parent = x;
    // z->parent = y;

    return x;
   
}

node* avl::leftRotate(node* y){
    node *x = y->right;
    node *z = x->left;

    x->left = y;
    y->right = z;

    // x->parent = y->parent;
    // y->parent = x;
    // z->parent = y;
    return x;
}


node* avl::rebalance(node* t){
  
    
    
  t->height = 1 + maxHeight(getheight(t->left), getheight(t->right));
  
  if (getheight(t->left) >= 2 + getheight(t->right)){
    if (getheight(t->left->left) >= getheight(t->left->right)){
      t = rightRotate(t);
    }else{
      t->left = leftRotate(t->left);
      t = rightRotate(t);
    }
  } else if (getheight(t->right) >= 2 + getheight(t->left)){
    if (getheight(t->right->right) >= getheight(t->right->left)){
      t = leftRotate(t);
    }else{
      t->right = rightRotate(t->right);
      t = leftRotate(t);
    }
  }


  return t;
}


node* avl::insert(string word, node* t){
  if (t == nullptr){
    t = new node(word);
    t->left = t->right = nullptr;
    // t->parent = this;
    
  }
  else if(t->word.compare(word) > 0){
    t->left = insert(word, t->left);
    t = rebalance(t);
  }else if(t->word.compare(word) <= 0){
    t->right = insert(word, t->right);
    t = rebalance(t);
  }
  return t;
}

void avl::insert(string word){
  StringToLower(word);
  if (search(word)){
    node* temp = search(word, this->root);
    temp->count = temp->count + 1;
    this->num = this->num + 1;
    return;
  }
  else
  {
    if(this->root == nullptr){
      this->root = new node(word);
      root->left = root->right = nullptr;
      this->sizes = 1;
      // root->parent = nullptr;
    }else{
      this->root = insert(word, root);
      this->num = this->num + 1;
      this->sizes++;

      }    
  }
}

node * avl::deleteNode(string word, node* t){
  node* temp;
  if (t == nullptr)
    return nullptr;
  else if (t->word.compare(word) > 0){
    t->left = deleteNode(word, t->left);
    t = rebalance(t);
  }
  else if (t->word.compare(word) < 0){
    t->right = deleteNode(word, t->right);
    t = rebalance(t);
  }
  else if (t->left != nullptr && t->right != nullptr){
    if (t->count > 1)
      t->count = t->count - 1;  
    else{
      temp = minNode(t->right);
      t->word = temp->word;
      t->count = temp->count;
      temp->count--;
      t->right = deleteNode(t->word, t->right);
      t = rebalance(t);
    }
  } else {
    if (t->count > 1)
      t->count = t->count - 1;
    else {
      temp = t;
      
      if (t->left == nullptr)
        t = t->right;
      else if (t->right == nullptr)
        t= t->left;
      delete temp;
      this->sizes--;
    }
  }
  return t;
}

void avl::remove(string word){
  StringToLower(word);
  if (search(word)){
    root = deleteNode(word, root);
    this->num = this->num - 1; 
  }else
    return;
}

int avl::count(string word){
  StringToLower(word);
  node* temp = search(word, root);
  if (temp == nullptr){
    return 0;
  }
  
  return temp->count;
}

node* avl::search(string word, node* t){
  if (t == nullptr)
    return nullptr;
  if (t->word.compare(word) > 0)
    return search(word, t->left);
  else if (t->word.compare(word) < 0)
    return search(word, t->right);
  else
    return t;
}

bool avl::search(string word){
  StringToLower(word);
  if(search(word, root) == nullptr){
    return false;
  }else
    return true;
}

void avl::exist(string word){

  if (search(word))
    cout << word << " " << "exists" << endl;
  else
    cout << word << " " << "does not exist" << endl;
}

// Updating
void avl::sort(ofstream& out){
  sort(root, out);
}

void avl::sort(node *t, ofstream& out){
  if (t == nullptr)
    return;
  sort(t->left, out);
  out << t->word << endl;
  sort(t->right, out);
}

// Updating
void avl::rangeSearch(string startWord, string endWord, node* t){
  if (t == nullptr)
    return;

  // startWord is in the left subtree of t  
  if (startWord.compare(t->word) < 0)
    rangeSearch(startWord, endWord, t->left);

  // if t is in the range, then print it out  
  if (startWord.compare(t->word) <= 0 && endWord.compare(t->word) >= 0)
    cout << t->word << endl;

  // endWord is in the right subtree of t
  if (endWord.compare(t->word) > 0)
    rangeSearch(startWord, endWord, t->right); 
}

void avl::Print(string strInput1, string strInput2){
  
  if (strInput1.compare(strInput2) > 0){
    rangeSearch(strInput2, strInput1, root);
    
  }else{
    rangeSearch(strInput1, strInput2, root);
  }
}

void avl::inorder(node* t){
  if (t == nullptr)
    return;
  inorder(t->left);
  cout << t->word << ": " << t->count << ", " << endl;
  inorder(t->right);
}

void avl::display(){
  inorder(root);
}


// helper functions
void avl::StringToLower(string& word)
{
  for (unsigned int i = 0; i < word.size(); ++i)
{
    word[i] = tolower(word[i]);
}
}





// int main(){
//   string str1 = "Carlos";
//   string str2 = "Gerardo";
//   string str3 = "Kamilo";
//   string str4 = "Angel";
//   string str5 = "Bosco";
//   string str6 = "prince";
//   string str7 = "Prince";
  

//   avl t = avl();
//   t.insert(str1);
//   t.insert(str2);
//   t.insert(str4);
//   t.insert(str5);
//   t.insert(str6);
//   t.insert(str7);

  
//   t.insert(str3);
  
//   t.display();
//   t.exist(str2);
//   cout << t.size() << endl;
//   t.remove(str1);
//   t.remove(str4);
//   t.remove(str3);
//   t.remove(str2);
//   t.remove(str7);
//   t.display();
  
//   cout << t.size() << endl;
// //   printf("the size is: %d", t.size());
//   return 0;
// }