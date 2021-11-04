// https://leetcode.com/problems/sum-of-left-leaves/

// Easy

// Tags - Binary Tree, DFS, BFS

// What this problem wants to teach me?
/*  How to write Recursive approach by just only thinking possibilities about what to do for current element,
    Then writing the recursive approach for the current element and think the base case for current element,
    Then finally writing the whole recursive solution assuming that it will work for next small subProblems.*/

/*  How to write iterative solution from recursive solution by using the explicit stack and
    all the recursive function parameters that are changing in each recursive call by pushing
    them in single time in explicit stack. */

#include<bits/stdc++.h>
using namespace std;

// DFS - Recursive | Time - O(N), Space - O(H)-depth of recursion
class Solution {  
public:
    int sumOfLeftLeaves(TreeNode* root, bool isLeft = false) {
        // base case
        if(root==NULL){
            return 0;
        }
        if((root->left==NULL && root->right==NULL) && isLeft==true){
            return root->val;
        }
        
        // recursive case
        return sumOfLeftLeaves(root->left,true) + sumOfLeftLeaves(root->right,false);
    } 
};

// Iterative - DFS | Time - O(N), Space - O(H)
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        
        stack<pair<TreeNode*, bool>>s;
        s.push({root,false});
        int leftLeavesSum = 0;
        
        while(!s.empty()){
            auto p = s.top();
            s.pop();
            
            TreeNode* curr = p.first;
            bool isLeft = p.second;
            
            if(curr->left==NULL && curr->right== NULL && isLeft==true){
                leftLeavesSum += curr->val;
            }
            
            if(curr->left){
                s.push({curr->left,true});
            }
            
            if(curr->right){
                s.push({curr->right,false});
            }
        }
        
        return leftLeavesSum;
    } 
};

// BFS | Time - O(N), Space - O(N) - maxm nodes in queue is N+1/2
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        
        queue<pair<TreeNode*, bool>>q;
        q.push({root,false});
        int leftLeavesSum = 0;
        
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            
            TreeNode* curr = p.first;
            bool isLeft = p.second;
            
            if(curr->left==NULL && curr->right== NULL && isLeft==true){
                leftLeavesSum += curr->val;
            }
            
            if(curr->left){
                q.push({curr->left,true});
            }
            
            if(curr->right){
                q.push({curr->right,false});
            }
        }
        
        return leftLeavesSum;
    }
};

// Morris Inorder Traversal Solution | Time - O(N), Space = O(1) 
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        
    }
};

// Why below code give wrong answer

/*     int dfs(TreeNode* root){
        
        // base case
        if(root==NULL){
            return 0;
        }
        if(root->left==NULL && root->right ==NULL){
            return root->val;
        }
            
        // recursive case
        int leftSubTreeLeavesSum = 0, rightSubTreeLeftLeavesSum = 0;
        
        if(root->left){
           leftSubTreeLeavesSum = sumOfLeftLeaves(root->left);
        }
        if(root->right){
            rightSubTreeLeftLeavesSum = sumOfLeftLeaves(root->right->left);
        }
        
        return leftSubTreeLeavesSum + rightSubTreeLeftLeavesSum;        
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        if ((!root) || ((!root->left) && (!root->right)))   //THE PROBLEM IS HERE IN CONDITION CHECKING
            return 0;                                      //WHAT IS THE PROBLEM HERE
        
        return dfs(root);
    } */