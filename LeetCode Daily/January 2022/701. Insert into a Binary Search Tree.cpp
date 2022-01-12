// https://leetcode.com/problems/insert-into-a-binary-search-tree/

// Medium

// Tags - BST

// What this problem wants to teach me?
// How to insert a node in BST

#include<bits/stdc++.h>
using namespace std;

// BST-Traversal | Time = O(Height), Space = O(1)
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL)  return new TreeNode(val);
        
        TreeNode* curr = root;
        while(curr!=NULL){
            if(curr->val <= val){
                if(curr->right!=NULL)
                    curr = curr->right;
                else{
                    curr->right = new TreeNode(val);
                    break;
                }
            }
            else{
                if(curr->left!=NULL)
                    curr = curr->left;
                else{
                    curr->left = new TreeNode(val);
                    break;
                }                
            }
        }
        
        return root;
    }
};