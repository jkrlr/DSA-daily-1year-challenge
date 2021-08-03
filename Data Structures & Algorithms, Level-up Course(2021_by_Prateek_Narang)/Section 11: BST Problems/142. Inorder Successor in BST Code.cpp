// Time = O(Height), Space = O(Height)
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

// target pointer is given instead of data because data can be same in multiple nodes
// the successor of last node is NULL, So, in main you have to handle it separately(Not print the data directly), if the fn returns NULL

Node *InorderSuccessor(Node *root, Node* target){
    Node *successor = NULL;

    if(target->right!=NULL){
        Node *temp = target->right;
        while (temp->left != NULL){
            temp = temp->left;
        }
        successor = temp;
        return successor;
    }

    Node *temp = root;
    while(temp!=NULL){
        if(temp->key > target->key){
            successor = temp;
            temp = temp->left;
        }
        else if(temp->key < target->key){
            temp = temp->right;
        }
        else{
            break;
        }
    }

    return successor;
}