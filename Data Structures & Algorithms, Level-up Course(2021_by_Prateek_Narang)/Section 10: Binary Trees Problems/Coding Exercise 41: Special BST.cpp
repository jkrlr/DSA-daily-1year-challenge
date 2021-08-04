// Time = O(Height), Space = O(1)
#include<bits/stdc++.h>
using namespace std;
 
class Node
{
  public:
   int key;
   Node *left;
   Node *right;
   Node *parent;
};
 
Node* findInOrderSuccessor( Node *inputNode ){
    // HINT : Since the parent pointer is given, you can traverse upwards in the tree

	// Case-1: check if the right subtree exist or not? if yes -> leftmost child of right subtree is our ans
	Node *successor = NULL;
	Node *temp;
	if(inputNode->right!=NULL){
		temp = inputNode->right;
		while(temp->left!=NULL){
			temp = temp->left;
		}
		successor = temp;
		return successor;
	}
 
	// Case-2: otherwise traverse upward and the first parent which is greater than target is our ans
	temp = inputNode;
	while(temp->parent!=NULL){
		temp = temp->parent;
		if(temp->key > inputNode->key){
			successor = temp;
			break;
		}
	}
	return successor;
}
 
 
