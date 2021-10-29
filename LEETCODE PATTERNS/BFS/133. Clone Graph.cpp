// https://leetcode.com/problems/clone-graph/

// Medium

// What this problem wants to teach me?
// How to create deep copy of a graph.
// How to use unordere_map for avoiding to create the multiple copies of a node
// How to use BFS and DFS in graph traversal problems

// Time = O(M+N), Space = O(N)- for storing the queue and unordere_map
#include<bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==nullptr){
            return nullptr;
        }
        
        // bfs
        queue<Node*> todo;
        unordered_map<Node*, Node*> cloneOf;
        
        Node *clone = new Node(node->val);
        cloneOf[node] = clone;
        todo.push(node);
        
        while(!todo.empty()){
            Node* curr = todo.front();
            todo.pop();
            
            for(auto nbr : curr->neighbors){
                if(cloneOf.find(nbr) == cloneOf.end()){
                    Node* next = new Node(nbr->val);
                    cloneOf[nbr] = next;
                    
                    todo.push(nbr);
                }
                cloneOf[curr]->neighbors.push_back(cloneOf[nbr]);
            }
        }
        return clone;  
    }
};

// Solution Using DFS
// Time - O(M+N), Space - O(N)-for recursive stack and unordered_map
class Solution {
public:
    unordered_map<Node*, Node*> cloneOf;
    Node* dfs(Node* node){
        // base case
        if(cloneOf.find(node)!=cloneOf.end()){
            return cloneOf[node];
        }
        
        
        // recursive case
        Node* clone = new Node(node->val);
        cloneOf[node] = clone;
        for(auto nbr: node->neighbors){
            Node* next = dfs(nbr);
            clone->neighbors.push_back(next);
        }
        
        return clone;
    }
    
    Node* cloneGraph(Node* node) {
        if(node==nullptr){
            return nullptr;
        }
        
        // dfs
        return dfs(node);
    }
};