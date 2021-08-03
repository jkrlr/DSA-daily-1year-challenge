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
 
// Time = O(Height), Space = O(Height) 
bool isPresent(Node * root,int key){
      // base case
	if(root==NULL){
        return false;
    }
    if(root->key==key){
        return true;
    }

    // recursive case
	if(key < root->key){
        return isPresent(root->left, key);
    }
    else{
        return isPresent(root->right, key);
    }
}
 
