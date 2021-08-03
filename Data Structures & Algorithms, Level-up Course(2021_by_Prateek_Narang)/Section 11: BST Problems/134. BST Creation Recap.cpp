#include<bits/stdc++.h>
using namespace std;
 
class Node
{
 public:
  int key;
  Node *left;
  Node *right;
 
  Node(int key){
      this->key = key;
      left = right  = NULL;
  }
};

Node *insert(Node *root, int key){
    // base case
    if(root==NULL){
        return new Node(key);
    }

    //recursive case
    if(key < root->key){
        root->left = insert(root->left, key);
    }
    else{
        root->right = insert(root->right, key);
    }

    return root;
}

void printInorder(Node* root){
    // base case
    if(root==NULL){
        return;
    }

    // recursive case
    printInorder(root->left);
    cout << root->key << ", ";
    printInorder(root->right);
}

int main(){
    Node *root = NULL;
    int arr[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};

    for(int x:arr){
        root = insert(root, x);
    }
}