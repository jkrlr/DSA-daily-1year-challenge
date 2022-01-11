// https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/

// Easy

// Tags - DFS(Morris Traversal, Preorder Traversal), Binary Tree, Bit Manipulation

// What this problem wants to teach me?
// Don't forget to check the conditions of base case for updating the answer
// Morris Traversal
// https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/Figures/1022/preorder2.png

#include<bits/stdc++.h>
using namespace std;

// Morris Preorder Traversal | Time = O(N), Space = O(1)
/* The idea of Morris preorder traversal is simple: to use no space but to traverse the tree.

The idea of Morris algorithm is to set the temporary link between the node and its predecessor: predecessor.right = root. 
So one starts from the node, computes its predecessor and verifies if the link is present.

There is no link? Set it and go to the left subtree.
There is a link? Break it and go to the right subtree.

There is one small issue to deal with : what if there is no left child, i.e. there is no left subtree? 
Then go straightforward to the right subtree.*/
class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        int rootToLeaf = 0, currNumber = 0;
        int steps;
        TreeNode* predecessor;
        
        while(root!=NULL){
            // If there is a left child
            // then compute predecessor.
            // If there is no link predecessor->right = root  --> set it.
            // If ther is a link predecessor->right = root  --> break it.
            if(root->left!=NULL){
                // Predecessor node is one step to the left
                // and then to the right till you can.
                predecessor = root->left;
                steps = 1;
                while(predecessor->right!=NULL && predecessor->right!=root){
                    predecessor = predecessor->right;
                    ++steps;
                }
                
                // Set link predecessor->right = root;
                // and go to explore the left subtree
                if(predecessor->right == NULL){
                    currNumber = (currNumber<<1) | root->val;
                    predecessor->right = root;
                    root = root->left;
                }
                // Break the link predecessor->right = root
                // Once the link is broken,
                // it's time to change subtree and go to the right
                else{
                    // If you're on the leaf, update the sum
                    if(predecessor->left == NULL){
                        rootToLeaf += currNumber;
                    }
                    
                    // This part of tree is explored, backtrack
                    for(int i=0; i<steps; i++){
                        currNumber >>= 1;
                    }
                    
                    predecessor->right = NULL;
                    root = root->right;
                }
            }
            // If there is no left child
            // then just go right.
            else{
                currNumber = (currNumber << 1) | root->val;
                // if you're on the leaf, update the sum
                if(root->right == NULL){
                    rootToLeaf += currNumber;
                }
                
                root = root->right;
            }
        }
        
        return rootToLeaf;
    }
};

// DFS-Preorder Traversal | Time = O(N), Space = O(height)
class Solution {
private:
    void dfs(TreeNode* root, int currPathSum, int& result){
        if(root==NULL)
            return;
        
        currPathSum = 2*currPathSum + root->val;
        if(root->left==NULL && root->right==NULL){
            result += currPathSum;
        }
        
        dfs(root->left, currPathSum, result);
        dfs(root->right,currPathSum, result);
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        int result = 0;
        dfs(root, 0, result);
        
        return result;
    }
};