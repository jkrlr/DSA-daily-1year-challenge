// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/

// Medium

// Tags - Binary Tree, Recursion-DFS


#include <bits/stdc++.h>
using namespace std;

// Approach #1: Recursion | Top-Down Like
/* Complexity Analysis
    Let N be the number of nodes in the binary tree.
    Time complexity: O(N) since we visit all nodes once.
    Space complexity: O(N) since we need stacks to do recursion, and the maximum depth of the recursion is the height of the tree, which is O(N) in the worst case and O(log(N)) in the best case. */
class Solution {
public:
    // record the required maximum difference
    int result = 0;
    int maxAncestorDiff(TreeNode* root) {
        if(root==NULL)
            return 0;
        
        result = 0;
        helper(root,root->val,root->val);
        return result;
    }
    
    void helper(TreeNode* root, int curMin, int curMax){
        if(root==NULL)
            return;
        
        // update result
        int possibleResult = max(abs(curMax - root->val), abs(curMin - root->val));
        result = max(result, possibleResult);
        
        // update the max and min
        curMax = max(curMax, root->val);
        curMin = min(curMin, root->val);
        
        helper(root->left, curMin, curMax);
        helper(root->right, curMin, curMax);
    }
};

// Approach #2: Maximum Minus Minimum | Top-Down Like
// Time - O(N), Space - O(H)
class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        if(root==NULL)
            return 0;
        
        return helper(root,root->val,root->val);
    }
    
    int helper(TreeNode* root, int curMin, int curMax){
        // if encounter leaves, return the max-min along the path
        if(root==NULL)
            return curMax - curMin;
        
        
        /// else, update max and min
        // and return the max of left and right subtrees
        curMax = max(curMax, root->val);
        curMin = min(curMin, root->val);
        
        int left = helper(root->left, curMin, curMax);
        int right = helper(root->right, curMin, curMax);
        
        return max(left, right);
    }
};
