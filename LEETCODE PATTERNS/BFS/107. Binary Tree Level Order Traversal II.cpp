// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

// Medium

// What this problem wants to teach me?
// Level Order Traversal

// How using ithLevelNodes vector as a temporary vector  and then pushing into levelOrder vector 
// can be faster than directly pushing the nodes into levelOrder vector

// How push_back() in levelOrder vector directly without using ithLevelNodes vector 
// can be costly in larger size trees than running BFS or DFS two times compare to push_back() + one time BFS or DFS

// Time = O(N), Space = O(N)- for storing the queue and ithLevelNodes vector , maxsize of both of these are N/2 
// Here N is total no. of tree nodes

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root==nullptr){
            return {};
        }
        
        // 1. normal level order traversal
        vector<vector<int>> levelOrder;
        queue<TreeNode*> todo;
        todo.push(root);
        
        while(!todo.empty()){
            int nodesCount = todo.size();

            vector<int> ithLevelNodes;
            for (int i = 0; i < nodesCount; i++){
                TreeNode *node = todo.front();
                todo.pop();

                ithLevelNodes.push_back(node->val);

                if(node->left){
                    todo.push(node->left);
                }
            
                if(node->right){
                    todo.push(node->right);
                }
            }

            levelOrder.push_back(ithLevelNodes);
        }

        // 2. reverse the levelOrder vector
        reverse(levelOrder.begin(), levelOrder.end());
        
        return levelOrder;
    }
};