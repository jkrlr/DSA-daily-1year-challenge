// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

// Medium

// Tags - LevelOrderTraversal, Binary Tree

#include<bits/stdc++.h>
using namespace std;

// Modification of LevelOrderTraversal | Time = O(N), Space = O(1)
class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return root;
        
        Node* temp = root;
        while(temp->left!=NULL){
            
            Node* curr = temp;
            while(true){
                
                curr->left->next = curr->right;
                
                if(curr->next==NULL)
                    break;
                curr->right->next = curr->next->left;
                curr = curr->next;
            }
            
            temp = temp->left;
        }
        
        return root;
    }
};

// LevelOrderTraversal | Time = O(N), Space = O(N)
class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return root;
        
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty()){
            int len = q.size();
            Node* node;
            
            for(int i=0; i<len-1; i++){
                node = q.front();
                q.pop();
                node->next = q.front();
                
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            
            node = q.front();
            q.pop();
            
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        
        return root;
    }
};