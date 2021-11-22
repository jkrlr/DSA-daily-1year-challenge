// https://leetcode.com/problems/delete-node-in-a-bst/

// Medium

// Tags - BST

// What this problem wants to teach me?
// How to delete a node in BST
// How to use the property of BST i.e. every subtree of BST is also a BST to divide the problem into cases of recursion and in writing the code
// If this is only BT, Then we can also use simailar approach but instead of checking in left or right part
// We have to check in both left and right part for general tree
// How to free the memory of a pointer using delete in C++

#include<bits/stdc++.h>
using namespace std;

// DP-TopDown | Time - O(Height), Space - O(Height)
class Solution {
public:
    //Function to find minimum in a tree. 
    TreeNode* findMin(TreeNode* root){
        while(root->left){
            root = root->left;
        }
        
        return root;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        // base case
        if(root==NULL){
            return root;
        }
        
        else if(key < root->val){
            root->left = deleteNode(root->left,key);
        }
        else if(key > root->val){
            root->right = deleteNode(root->right,key);
        }
        else{
            // Wohoo... I found you, Get ready to be deleted	
            
            // Case 1: No Child
            if(root->left==NULL && root->right==NULL){
                delete root;
                root = NULL;
            }
            // Case 2: One Child
            else if(root->left==NULL){
                TreeNode* temp = root;
                root = root->right;
                delete temp;
            }
            else if(root->right==NULL){
                TreeNode* temp = root;
                root = root->left;
                delete temp;
            }
            // Case 3: Two Child
            else{
                TreeNode* temp = findMin(root->right);
                root->val = temp->val;
                
                root->right = deleteNode(root->right,temp->val);
            }
        }
        
        return root;
    }
};