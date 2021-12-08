// https://leetcode.com/problems/binary-tree-tilt/

// Easy

// Tags - PostOrder, Binary Tree

// What this problem wants to teach me?
// When we've to calulate the answer of Tree problems in Bottom Up Manner
// Then, we can use PostOrder kind or recursion in that problem

#include <bits/stdc++.h>
using namespace std;

// Recursive PostOrder | Time = O(n), Space = O(Height)
// Time - O(N), Space = O(Height)
class Solution {
private:
    // Calcultes and returns the sum of subtree and computing the ans from the diff of sum of left and sum of right
    int postOrder(TreeNode* root, int& ans){
        if(root==NULL){
            return 0;
        }
        
        int leftSum = postOrder(root->left,ans);
        int rightSum = postOrder(root->right,ans);
        
        ans += abs(leftSum-rightSum);
        
        return root->val + leftSum + rightSum;
    }
    
public:
    int findTilt(TreeNode* root) {
        int ans = 0;
        postOrder(root,ans);
        
        return ans;
    }
};