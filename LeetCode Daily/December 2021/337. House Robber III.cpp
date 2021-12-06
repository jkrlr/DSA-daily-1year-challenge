// https://leetcode.com/problems/house-robber-iii/

// Medium

// Tags - Dynamic Programming, DFS, Tree

// What this problem wants to teach me?
// Don't write the messy code, for increasing the readibility of code because somtimes it can be look more code and will be difficult to read
// Don't directly memoize the code, if you aren't confident => First write recursive solution then only memoize the code
// When we've choices to select an item or not select item and based upon choice the constraints are given.
// Then,Instead of returning a single value, sometimes it is better to return the both include and exclude values to compute the answer

#include <bits/stdc++.h>
using namespace std;

// DFS - modified, Space-Optimization Of DP | Time = O(n), Space = O(h)
// return pair instead of returning a single value
class Solution {
private:
    // returns pair<withRoot, withoutRoot>
    pair<int,int> dfs(TreeNode* root){
        if(root==NULL)
            return {0,0};
        
        auto leftPair = dfs(root->left);
        auto rightPair = dfs(root->right);
        
        int withRoot = root->val + leftPair.second + rightPair.second;
        int withoutRoot = max(leftPair.first, leftPair.second) + max(rightPair.first, rightPair.second);
        
        return {withRoot,withoutRoot};
    }
public:
    int rob(TreeNode* root) {
        auto p = dfs(root);
        int withRoot = p.first, withoutRoot = p.second;
        
        return max(withRoot, withoutRoot);
    }
};

// Brute-Force + DFS - Sol-1 | Time - O(2^N), Space - O(Height)
class Solution {
public:
    int rob(TreeNode* root, bool canRob=true) {
        if(root==NULL)
            return 0;
        
        int dontRob = rob(root->left) + rob(root->right);
        int robRoot = canRob? root->val + rob(root->left, false) + rob(root->right, false) : -1;
        
        return max(dontRob, robRoot);
    }
};

// Brute-Force + DFS - Sol-2 | Time - O(2^N), Space - O(Height)
class Solution {
public:
    int rob(TreeNode* root) {
        if(root==NULL)
            return 0;
        
        int dontRob = rob(root->left) + rob(root->right);
        int robRoot = root->val;
        
        if(root->left)
            robRoot += rob(root->left->left) + rob(root->left->right);
            
        if(root->right)
            robRoot += rob(root->right->left) + rob(root->right->right);
        
        return max(dontRob, robRoot);
    }
};

// TopDown DP + DFS - Sol-1 | Time - O(N), Space - O(N)
class Solution {
public:
    unordered_map<TreeNode*, vector<int>> dp;
    int rob(TreeNode* root, bool canRob=true) {
        if(root==NULL)
            return 0;
        
        if(dp.count(root)&& dp[root][canRob]!=-1)
            return dp[root][canRob];
        
        dp[root] = {-1,-1};
        
        int dontRob = rob(root->left) + rob(root->right);
        int robRoot = canRob? root->val + rob(root->left, false) + rob(root->right, false) : -1;
        
        return dp[root][canRob] = max(dontRob, robRoot);
    }
};

// TopDown DP + DFS - Sol-2 | Time - O(N), Space - O(N)
class Solution {
public:
    unordered_map<TreeNode*, int> dp;
    int rob(TreeNode* root) {
        if(root==NULL)
            return 0;
        
        if(dp.count(root))
            return dp[root];
        
        int dontRob = rob(root->left) + rob(root->right);
        int robRoot = root->val;
        
        if(root->left)
            robRoot += rob(root->left->left) + rob(root->left->right);
            
        if(root->right)
            robRoot += rob(root->right->left) + rob(root->right->right);
        
        return dp[root] = max(dontRob, robRoot);
    }
};