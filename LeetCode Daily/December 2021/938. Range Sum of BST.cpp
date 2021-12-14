// https://leetcode.com/problems/range-sum-of-bst/

// Easy

// Tags - Branch Pruning using BST property, DFS

// What this problem wants to teach me?
// First Try to solve the problems using without any special property of question (in this case any Tree Traversal or DFS can be used) and
// Then, optimize the problems using special property given in question (in this case Prune Branchs using BST property)
// In case of recursion, while making multiple calls make sure that name of funtion should be same in all the function calls and
// All the functions calls should receive the same number of function parameters

#include <bits/stdc++.h>
using namespace std;

// LevelOrder + Branch Pruning using BST property | Time - O(high-low+1), Space = O(high-low+1)-depth or recursion
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        // base case
        if(root==NULL)
            return 0;
        
        // recursive case
        if(root->val < low)
            return rangeSumBST(root->right,low,high);
        else if(root->val > high)
            return rangeSumBST(root->left,low,high);
        else
            return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right,low,high);
    }
};