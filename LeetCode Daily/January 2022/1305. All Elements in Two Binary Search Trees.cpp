// https://leetcode.com/problems/all-elements-in-two-binary-search-trees

// Medium

// Tags - Inorder Traversal, BST, DFS

// What this problem wants to teach me?
// Efficient Simultaneous Inorder Traversal of Two BST's
// Iterative Inorder Traversal of a BST

#include<bits/stdc++.h>
using namespace std;

// Inorder Traversal | Time = O(N + M), Space = O(Height1 + Height2)
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> s1, s2;
        vector<int> result;
        
        while(root1 || root2 || !s1.empty() || !s2.empty()){
            while(root1){
                s1.push(root1);
                root1 = root1->left;
            }
            while(root2){
                s2.push(root2);
                root2 = root2->left;
            }
            
            if(s2.empty() || (!s1.empty() && s1.top()->val < s2.top()->val)){
                root1 = s1.top();
                s1.pop();
                result.push_back(root1->val);
                root1 = root1->right;
            }
            else{
                root2 = s2.top();
                s2.pop();
                result.push_back(root2->val);
                root2 = root2->right;
            }
        }
        
        return result;
    }
};

// Inorder Traversal | Time = O(2*(N + M)), Space = O(N + M + Height)
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> inorder1, inorder2;
        
        inorderTraversal(root1, inorder1);
        inorderTraversal(root2, inorder2);
        
        int m = inorder1.size(), n = inorder2.size();
        vector<int> result(m+n);
        int idx1 = 0, idx2 = 0, idx = 0;
        
        while(idx1<m && idx2<n){
            if(inorder1[idx1] < inorder2[idx2])
                result[idx++] = inorder1[idx1++];
            else
                result[idx++] = inorder2[idx2++];
        }
        
        while(idx1 < m)
            result[idx++] = inorder1[idx1++];
        while(idx2 < n)
            result[idx++] = inorder2[idx2++];
        
        return result;
    }
private:
    void inorderTraversal(TreeNode* root, vector<int>& result){
        if(root==NULL)
            return;
        
        inorderTraversal(root->left, result);
        result.push_back(root->val);
        inorderTraversal(root->right, result);
    }
};