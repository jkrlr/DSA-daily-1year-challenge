// https://leetcode.com/problems/maximum-depth-of-binary-tree/

// Easy 

// Tags - DFS, BFS, Binary Tree

// What this problem wants to teach me?
// How to apply bfs and dfs to find the depth of binary tree
// For writing the iterative traversal sol of tree from the recursive traversal sol
// push all the variables that are changing in the recursive function call as an argument single time argument in stack

#include<bits/stdc++.h>
using namespace std;

// DFS-Recursive - 1 |  Time - O(N), Space - O(height)
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==nullptr)
            return 0;
        
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

// DFS-Recursive - 2 |  Time - O(N), Space - O(height)
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int maxDepth = 0;
        dfs(root,0,maxDepth);
        
        return maxDepth;
    }
private:
    void dfs(TreeNode* root, int curDepth, int& maxDepth){
        if(root==nullptr){
            maxDepth = max(maxDepth, curDepth);
            return;
        }
        
        dfs(root->left, curDepth+1, maxDepth);
        dfs(root->right, curDepth+1, maxDepth);
    }
};

// DFS - Iterative | Time = O(N), Space = O(Height)
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==nullptr)
            return 0;

        int maxDepth = 0;
        stack<pair<TreeNode*, int>> s;
        s.push({root,0});
        
        while(!s.empty()){
            auto& p = s.top();
            TreeNode* node = p.first;
            int curDepth = p.second;
            s.pop();
            
            if(node==nullptr){
                maxDepth = max(maxDepth, curDepth);
                continue;
            }
            s.push({node->left, curDepth+1});
            s.push({node->right, curDepth+1});
        }
        
        return maxDepth;
    }
};

// BFS | Time - O(N), Space - O(N/2)
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==nullptr)
            return 0;
        
        int levels = 0;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int levelSize = q.size();
            for(int i=0; i<levelSize; i++){
                TreeNode* cur = q.front();
                q.pop();
                
                if(cur->left)   q.push(cur->left);
                if(cur->right)  q.push(cur->right);
            }
            levels++;
        }
        
        return levels;
    }
};