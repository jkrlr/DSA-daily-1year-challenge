// https://leetcode.com/problems/count-nodes-with-the-highest-score/

// Medium

// Tags - DFS, DP on Tree

// What this problem wants to teach me?
/* How to find the size of each subtree of tree in O(V+E) by storing the previous results

How to break down problem into multiple small subproblems and seperately sovle each subproblem 
    using the results of previous subproblems or by independently solving each subproblem that will leads to 
    solving the original big problem 
    
How to apply DFS traversal for tree treating it like as a graph*/

// This approach also works for n-ary tree
// Time = O(V+E), Space = O(V+E)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(int src, vector<vector<int>>& adj, vector<int>& subtreeSizeOf){
        int childNodesCount = 0;
        for(int child : adj[src]){
            childNodesCount +=dfs(child,adj,subtreeSizeOf);
        }
        
        subtreeSizeOf[src] = childNodesCount + 1;
        return subtreeSizeOf[src];
    }
    
    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size();
        
        //1. Build the adjList of graph
        vector<vector<int>> adj(n);
        
        for(int node=1; node<n; node++){
            int par = parents[node];
            adj[par].push_back(node);
        }
                
        // 2. calculate size of each node's subtree
        vector<int> subtreeSizeOf(n);
        int root = 0;                   // root is src in case of Binary Tree
        dfs(root,adj,subtreeSizeOf);  
        
        // 3. calculate score of each node
        vector<long long int> score(n);
        long long int maxScore = LLONG_MIN;
        
        for(int node = 0; node<n; node++){
            
            // a. calculate count of nodes that aren't in the current node subtree
            if(node==0){
                score[node] = 1;
            }
            else{
                score[node] = subtreeSizeOf[0] - subtreeSizeOf[node];
            }
            
            // b. multiply the previous result with the subtreeSizeOf of child nodes of current node
            for(int child : adj[node]){
                long long int childNodeCount = subtreeSizeOf[child];
                score[node] *= childNodeCount;
            }
            
            maxScore = max(maxScore, score[node]);
        }
        
        // 4. count the nodes having score is maxScore
        int countOfMaxScore = 0;
        for(int node = 0; node<n; node++){
            if(score[node]==maxScore){
                countOfMaxScore++;
            }
        }
        
        return countOfMaxScore;
    }
};