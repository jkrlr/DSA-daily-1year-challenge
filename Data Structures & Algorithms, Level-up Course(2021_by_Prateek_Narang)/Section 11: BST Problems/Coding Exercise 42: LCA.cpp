// https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1

#include<bits/stdc++.h>
using namespace std;
 
class node {
public:
	int data;
	node*left;
	node*right;
 
	node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};
 
// Time = O(N), Space = O(Height) - for Binary Tree  not for BST
node* lca(node*root, int a, int b){    
    	// base case
    if(root==NULL){
        return NULL;
    }
    if(root->data==a || root->data==b){
        return root;
    }
    // recursive case
    // 4 cases 
    
    node* Left = lca(root->left, a, b);
    node* Right = lca(root->right, a, b);
    
    if(Left!=NULL && Right!=NULL){
        return root;
    }
    else if(Left==NULL && Right==NULL){
        return NULL;
    }
    return Left!=NULL?Left:Right;
}

// Time = O(Height), Space = O(Height) - for BST
node* lca(node*root, int a, int b){
    // base case
    if(root==NULL){
        return NULL;
    }

    // recursive case
    /* 1. ancestor lies in left subtree */
    if (a < root->data && b < root->data){
        return lca(root->left, a, b);
    }
    /* 2. ancestor lies in right subtree */
    else if (a > root->data && b > root->data){
        return lca(root->right, a, b);
    }
    /* 3. current node is ancestor 
    i.e. if((a < root->data && root->data < b) || root->data==a || root->data==b)*/
    else{
        return root;
    }
}