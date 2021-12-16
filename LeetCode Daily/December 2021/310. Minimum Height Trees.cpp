// https://leetcode.com/problems/minimum-height-trees/

// Medium

// Tags - Topological Sorting, BFS, DFS, Graph

// What this problem wants to teach me?
// When you have to choose which selection will give max/min ans from multiple choices
// Then, the median(most symmetrical part) will give the most optimal answer
// For the tree-alike graph, the number of centroids is no more than 2.
// The distance between two nodes is the number of edges that connect the two nodes.
// The height of a tree can be defined as the maximum distance between the root and all its leaf nodes.

/* Some statement for tree in graph theory:
(1) A tree is an undirecten, the problem is now reduced down to looking for all the centroid nodes in a tree-alike graph, which in addition are no more than two.d graph in which any two vertices are connected by exactly one path.
(2) Any connected graph who has n nodes with n-1 edges is a tree.
(3) The degree of a vertex of a graph is the number of edges incident to the vertex.
(4) A leaf is a vertex of degree 1. An internal vertex is a vertex of degree at least 2.
(5) A path graph is a tree with two or more vertices that is not branched at all.
(6) A tree is called a rooted tree if one vertex has been designated the root.
(7) The height of a rooted tree is the number of edges on the longest downward path between root and a leaf. */

#include<bits/stdc++.h>
using namespace std;

// Topological-Sorting | Time = O(V + E) = O(n), Space = O(V + E) = O(n)
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)
            return {0};
        
        // 1. Build the graph
        vector<unordered_set<int>> adjList(n);
        for(auto& edge : edges){
            adjList[edge[0]].insert(edge[1]);
            adjList[edge[1]].insert(edge[0]);
        }
        
        // 2. Push all the leaf into queue i.e Initialize the first layer of leaves
        queue<int> leaves;
        for(int i=0; i<n; i++){
            if(adjList[i].size()==1)
                leaves.push(i);
        }
        
        // 3. Apply Topological Sorting i.e Trim the leaves until reaching the centroids
        int remainingNodes = n;
        while(remainingNodes > 2){
            int len = leaves.size();
            remainingNodes -= len;
            
            // remove the current leaves along with the edges
            for(int i=0; i<len; i++){
                int leaf = leaves.front();
                leaves.pop();
                
                // remove the edge along with the leaf node
                for(auto& neighbor: adjList[leaf]){
                    adjList[neighbor].erase(leaf);
                    
                    if(adjList[neighbor].size()==1)
                        leaves.push(neighbor);
                }
            }
        }
        
        // 4. Return the result;
        vector<int> result;
        while(!leaves.empty()){
            result.push_back(leaves.front());
            leaves.pop();
        }
        
        return result;
    }
};

// Brute-Force | Time = O(V*(V+E)) = O(n^2), Space = O(V+E) = O(n)
class Solution {
public:
    int dfs(vector<vector<int>>& edgeList, vector<bool>& visited, int src){
        visited[src] = true;
        
        int depth = 0;
        for(int& nbr : edgeList[src]){
            if(visited[nbr]==false){
                int nbrDepth = 1 + dfs(edgeList, visited, nbr);
                depth = max(depth, nbrDepth);
            }
        }
        
        visited[src] = false;
        return depth;
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // 1. Build the graph
        vector<vector<int>> edgeList(n); vector<bool> visited(n,false);
        for(auto& edge : edges){
            edgeList[edge[0]].push_back(edge[1]);
            edgeList[edge[1]].push_back(edge[0]);
        }
        
        //2. Find all heights, considering all the nodes as root
        unordered_map<int,vector<int>> mapHeightToNodes;
        for(int src = 0; src<n; src++){
            int height = dfs(edgeList,visited,src);
            mapHeightToNodes[height].push_back(src);
        }
        
        // 3. Find the minHeight and reuturn all the nodes having height is minHeight
        int minHeight = INT_MAX;
        for(auto& [currHeight, nodes] : mapHeightToNodes){
            minHeight = min(minHeight, currHeight);
        }
        
        return mapHeightToNodes[minHeight];
    }
};

