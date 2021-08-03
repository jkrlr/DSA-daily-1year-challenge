// https://leetcode.com/problems/validate-binary-search-tree/
// Time = O(N), Space = O(H)
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

// Note we use LONG_MIN and LONG_MAX to handle edge cases like [INT_MAX].

bool isBstUtil(Node *root, long long int minValue, long long int maxValue){
	// base case
    if(root==NULL){
		return true;
	}
 
	// recursive case
	if(root->key > minValue && root->key < maxValue && isBstUtil(root->left,minValue,root->key) && isBstUtil(root->right,root->key,maxValue)){
		return true;
	}
	return false;
}
 
bool isBST(Node * root){
    	return isBstUtil(root,LONG_MIN,LONG_MAX);
}

 
 
