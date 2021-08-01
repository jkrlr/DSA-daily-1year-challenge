// Time = O(N^2) and Space = O(LogN)

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

// Helper function : Height of Tree
int height(node *root){
    //base case
    if(root==NULL){
        return 0;
    }

    //recursive case
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return max(leftHeight, rightHeight) + 1;
}

int diameter(node *root){
    //base case
    if(root==NULL){
        return 0;
    }

    //recursive case
    int d1 = height(root->left) + height(root->right);  // diameter passes through root - O(N) time
    int d2 = diameter(root->left);  // diameter lies in the left subtree
    int d3 = diameter(root->right); // diameter lies in the right subtree
    int d = max(d1, max(d2, d3));

    return d;
}