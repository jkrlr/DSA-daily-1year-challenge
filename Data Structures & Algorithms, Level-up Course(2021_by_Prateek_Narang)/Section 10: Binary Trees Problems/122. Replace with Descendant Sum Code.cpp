// PostOrderTraversal Example - Left-Right-Root
// Time = O(N), Space = O(LogN)

#include<iostream>
using namespace std;

class node{

public:
    int data;
    node *left;
    node *right;
    
    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

// Replace with Descendent Sum
int replaceWithSum(node *root){
    // base case

    /* 1. NULL node */
    if(root==NULL){
        return 0;
    }

    /* 2. Leaf node */
    if(root->left==NULL && root->right==NULL){
        return root->data;
    }

    // recursive case
    int tmp = root->data;   // save the curr data before overwriting it
    int leftSum = replaceWithSum(root->left);
    int rightSum = replaceWithSum(root->right);

    root->data = leftSum + rightSum;
    
    return tmp + root->data;
}