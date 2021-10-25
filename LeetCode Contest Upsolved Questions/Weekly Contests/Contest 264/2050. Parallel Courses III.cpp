// https://leetcode.com/problems/parallel-courses-iii/

// Hard

// Tags - BFS, Topological Sorting

// What this problem wants to teach me?
/*  How to solve topological sorting problems using queue + indegree concept.

    How to apply topological sorting for graphs having dependency of current node on some previous nodes.
 
    How to build adjList by starting from 0 to n-1 nodes, when nodes are given from 1 to n
    by substracting 1 from each node so that it will be from 0..n-1 and we can use distance array result 
    directly without substracting 1 from each node to access the result and switch to more familiar 0 index based indexing. */

// Time = O(V+E), Space = O(V+E) , where V == N

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        
        for(auto edge: relations){
            int from = edge[0] - 1;
            int to = edge[1] - 1;
            
            adj[from].push_back(to);
            indegree[to]++;
        }
        
        vector<int> distTo(n,0);
        queue<int> q;
        
        for(int node=0; node<n; node++){
            if(indegree[node]==0){
                q.push(node);
                distTo[node] = time[node];
            }
        }
        
        while(!q.empty()){
            int prev = q.front();
            q.pop();
            
            for(int next : adj[prev]){
                distTo[next] = max(distTo[next], distTo[prev] + time[next]);
                indegree[next]--;
                if(indegree[next]==0){
                    q.push(next);
                }
            }
        }
        
        return *max_element(distTo.begin(),distTo.end());
    }
};