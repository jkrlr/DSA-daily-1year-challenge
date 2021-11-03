// https://leetcode.com/problems/sum-root-to-leaf-numbers/

// Medium

// Tags - Binary Tree, DFS, PreOrder Traversal

// What this problem wants to teach me?
// Recursive and Iterative PreOrder Traversal
// Morris PreOrder Traversal
// When we've to go to till the leaf nodes of tree. Then, dfs is a good choice for this work.
// If we pass copy of a value in function, then we don't need to undo the changes while backtracking.
// because we're making changes into the copy not in actual variable

#include<bits/stdc++.h>
using namespace std;

// DFS Recursive Solution - Time = O(N), Space = O(H)

class Solution {
public:
    int _sum = 0;
    
    void dfs(TreeNode* root, int currSum){
        
        currSum = currSum*10 + root->val;
        
        // base case
        if(root->left == NULL && root->right==NULL){
            _sum += currSum;
            return;
        }
        
        // recursive case
        if(root->left){
            dfs(root->left,currSum);
        }
        
        if(root->right){
            dfs(root->right, currSum);
        }
    }
    
    int sumNumbers(TreeNode* root) {
        int currSum = 0;
        dfs(root, currSum);
        
        return _sum;
    }
};

// DFS Iterative Solution - Time = O(N), Space = O(H)

class Solution {
public:
    
    int sumNumbers(TreeNode* root) {
        int totalSum = 0;

        stack<pair<TreeNode*, int>> s;
        s.push({root, 0});

        while(!s.empty()){
            auto temp = s.top();
            s.pop();
            
            TreeNode* node = temp.first;
            int prevSum = temp.second;
            
            int currSum = 10*prevSum + node->val;
            
            if(node->left==NULL && node->right==NULL){
                totalSum +=currSum;
            }
            if(node->left){
                s.push({node->left,currSum});
            }
            
            if(node->right){
                s.push({node->right,currSum});
            }
        }
        
        
        return totalSum;
    }
};

// BFS Solution - Time = O(N), Space = O(N) - At max (N+1/2) stored in queue

class Solution {
public:
    
    int sumNumbers(TreeNode* root) {
        int totalSum = 0;
        
        queue<pair<TreeNode*, int>> q;
        q.push({root,0});
        
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            
            TreeNode* node = temp.first;
            int prevSum = temp.second;
            
            int currSum = 10*prevSum + node->val;
            
            if(node->left==NULL && node->right==NULL){
                totalSum +=currSum;
            }
            if(node->left){
                q.push({node->left,currSum});
            }
            
            if(node->right){
                q.push({node->right,currSum});
            }
        }
        
        
        return totalSum;
    }
};

// Morris PreOrder Traversal - Time = O(N) + O(N) = O(N), Space = O(1)