#include <vector>
#include <iostream>

using namespace std;

class node{
public:
  int key;
  node *left, *right;
};

node* newNode(int key){
  node *temp = new node;
  temp->key = key;
  temp->left = temp->right = nullptr;
  return temp;
}

node * insert(node* node, int key){
  /**
  return the new node when the node does not exist
  **/
  if(node == nullptr) return newNode(key);
  if(key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  /*return the unchanged node pointer*/
  return node;
}

node * minNode(node* Node){
  /*find the min rooted by current node*/
  node* current = new node;
  current = Node;
  while(current->left != nullptr)
    current = current->left;

  return current;
}

node * maxNode(node* Node){
  node* current = new node;
  current = Node;
  while(current->right != nullptr)
    current = current->right;

  return current;
}

int min(node* node){
  return minNode(node)->key;
}

int max(node* node){
  return maxNode(node)->key;
}

void inorder(node* root){
  /**
  O(n)
  T(n) <= (c+d)n + c
  **/
  if(root != nullptr){
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
  }
}

void preorder(node* root){
  if(root != nullptr){
    cout << root->key << " ";
    preorder(root->left);
    preorder(root->right);
  }
}

void postorder(node* root){
  if(root != nullptr){
    postorder(root->left);
    postorder(root->right);
    cout << root->key << " ";
  }
}

node * deleteNode(node* root, int key){
  /**
  delete the node with key and returns the new root
  **/
  if (root == nullptr) return root;
  if(key < root->key){
    root->left = deleteNode(root->left, key);
  } else if (key > root->key)
    root->right = deleteNode(root->right, key);
  // this is node to be deleted
  else {
    if(root->left == nullptr){
      node* temp = root->right;
      delete root;
      return temp;
    } else if (root->right == nullptr){
      node* temp = root->left;
      delete root;
      return temp;
    }

    node* temp = minNode(root->right); //inorder successor
    root->key = temp->key; // cope the successor to this rooted
    root->right = deleteNode(root->right, temp->key); // delete the successor

  }

  return root;
}

void Print(node* root, int m, int n){
  /**
  print all keys in range [m,n], with increasing order
  **/
  if (root == nullptr) return;
  if(root->key > m) Print(root->left, m, n);
  if(root->key >= m && root->key <= n){
    cout << " " << root->key << " ";
  }
  if(root->key < n) Print(root->right, m, n);
}

node* ceil(node* current){
  /**
  return node with the smallest data larger than or equal to the current root
  which is just the inorder sucessor
  **/
  return minNode(current->right);

}

int main()
{
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    struct node *root = nullptr;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder traversal of the given tree \n");
    inorder(root);
    printf("preorder traversal of the given tree \n");
    preorder(root);
    printf("postorder traversal of the given tree \n");
    postorder(root);

    printf("\nPrint the nodes in range [30, 60]\n");
    Print(root, 30, 60);

    printf("\nDelete 20\n");
    root = deleteNode(root, 20);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);

    printf("\nDelete 30\n");
    root = deleteNode(root, 30);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);

    printf("\nDelete 50\n");
    root = deleteNode(root, 50);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);

    return 0;
}
