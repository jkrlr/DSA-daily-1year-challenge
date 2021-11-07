// https://leetcode.com/problems/maximum-path-quality-of-a-graph/

// hard

// Tags - DFS, Backtracking, Brute-Force, Dijkstra

// What this problem wants to teach me?

/* Analysis
    10 <= time[j], maxTime <= 100 By this constraint, there are at most 10 nodes in a path.
    There are at most four edges connected to each node
    Based on the aforementioned constraints, the brute force approach runs in O(4^10) = O(2^20) which is sufficient to pass the tests.*/

#include<bits/stdc++.h>
using namespace std;

// DFS | Time = O(4^10)= O(2^20) ~= O(10^6)
// Space = O(V+E)-for building graph, O(V)-for visited vector, max-depth of recursion-10  
class Solution {
public:
    int maxQuality = 0;
    void dfs(vector<vector<pair<int,int>>>& adjList, vector<int>& visited, vector<int>& values, int src, int quality, int prevTime, int& maxTime){
        // base case
        if(prevTime > maxTime){
            return;
        }
        
        // recursive case
        if(visited[src]==0){
            quality += values[src];
        }
        
        visited[src] += 1;

        if(src == 0){
            maxQuality = max(quality, maxQuality);
        }
        
        for(auto nbr : adjList[src]){
            int node = nbr.first;
            int time = nbr.second;
            int newTime = prevTime + time;
            // prevTime +=time; wrong why?
            // if(maxTime - time >= 0){
                // maxTime -= time;
                dfs(adjList, visited, values, node, quality, newTime, maxTime);
                // maxTime -= time;    // backtracking
            // }
        }
        
        // backtracking
        visited[src] -= 1;
    }
    
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        // 1. Build the graph
        int n = values.size();
        vector<vector<pair<int,int>>> adjList(n);
        
        for(auto edge: edges){
            int from = edge[0];
            int to = edge[1];
            int time = edge[2];
            
            adjList[from].push_back({to, time});
            adjList[to].push_back({from, time});
        }
        vector<int> visited(n,0);
        maxQuality = values[0];
        
        // 2. Apply Brute-Force(Explore all the valid paths) DFS(means one path at a time not one step in each path a time(BFS)) to find the maxQuality
        dfs(adjList, visited, values, 0, 0, 0, maxTime);
        
        return maxQuality;
    }
};

// Dijkstra solution - Complete it after end sem
// https://leetcode.com/problems/maximum-path-quality-of-a-graph/discuss/1563699/JavaC%2B%2B-dfs-with-optimization
// https://leetcode.com/discuss/general-discussion/655708/Graph-For-Beginners-Problems-or-Pattern-or-Sample-Solutions