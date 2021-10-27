// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

// Medium

// What this problem wants to teach me?
// Modified Level Order Traversal + how to store the elements in reverse order in vector
// while adding the elements in the vector first time (not using the reverse fn at all)

// Time = O(N), Space = O(N)- for storing the queue and row vector , maxsize of both of these are N/2 
// Here N is total no. of tree nodes

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root){
        if(root==nullptr){
            return {};
        }
        
        vector<vector<int>> result;
        queue<TreeNode*> q;
        q.push(root);
        
        bool leftToRight = true;
        while(!q.empty()){
            int nodesCount = q.size();
            vector<int> row(nodesCount);
            
            for(int i=0; i<nodesCount; i++){
                TreeNode* node = q.front();
                q.pop();
                
                int index = leftToRight==true ? i : (nodesCount - 1 - i);
                
                row[index] = node->val;
                
                if(node->left){
                    q.push(node->left);
                }
                
                if(node->right){
                    q.push(node->right);
                }
            }
            
            result.push_back(row);
            leftToRight = !leftToRight;
        }
        return result; 
    }
};