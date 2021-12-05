// https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/

// Medium

// Tags - LCA, Binary Tree

// What this problem wants to teach me?
// How to find LCA of Binary Tree when all nodes are distinct and both Nodes are present in BT
// How to find the path to a node in Binary Tree

// Try to Avoid typos in code
// In Contest don't be panic carefully debug code, make sure logic and code both should be match
// In Contest in first 1 minute just quickly walk through all the 4 problems and solve them according to ease of question
// Always pass maximum no. of variables by reference to a function as much as you can => It'll save from TLE

#include<bits/stdc++.h>
using namespace std;

// LCA + Path Finding to Node in BT | // Time - O(N + N + N)= O(N), Space = O(Height)-for Recursive Stack
class Solution {
private:
    // Time - O(N), Space - O(Height)
    TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q) {
        if(root==NULL)
            return NULL;
        
        if(root->val==p || root->val==q)
            return root;
        
        
        TreeNode *left = NULL, *right = NULL;
        
        if(root->left)
            left = lowestCommonAncestor(root->left,p,q);
        if(root->right)
            right = lowestCommonAncestor(root->right,p,q);
        
        if(left && right)
            return root;
        
        return left==NULL ? right:left;
    }
    
private:
    // Time - O(N), Space - O(Height)
    bool findPath(TreeNode* root, string& path, int dest){
        if(root==NULL)
            return false;
        if(root->val==dest)
            return true;
        
        path.push_back('L');
        bool hasSeen = findPath(root->left,path,dest);
        if(hasSeen)
            return true;
        path.pop_back();
        
        path.push_back('R');
        hasSeen = findPath(root->right,path,dest);
        if(hasSeen)
            return true;
        path.pop_back();
        
        return false;
    }
public:
    // Time - O(N + N + N)= O(N), Space = O(Height)-for Recursive Stack
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca = lowestCommonAncestor(root,startValue, destValue);
        
        string path;
        
        findPath(lca,path, startValue);
        for(char& c: path)
            c = 'U';
        
        findPath(lca,path, destValue);
        
        return path;
    }
};