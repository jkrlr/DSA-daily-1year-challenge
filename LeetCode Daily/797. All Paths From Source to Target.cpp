// https://leetcode.com/problems/all-paths-from-source-to-target/

// Medium

// Tags - DFS, BFS, Backtracking

// What this problem wants to teach me?
// For finding all the possibilities of a question => Recursion + Backtracking is used

#include<bits/stdc++.h>
using namespace std;

// DFS + Backtracking | Time = O(V+E), Space = O(V)-for depth of Recusion, for storing the path vector
class Solution {
private:    
    void dfs(vector<vector<int>>& graph, vector<vector<int>>& paths, vector<int>& path, int src, int dest){
        path.push_back(src);
        
        // base case
        if(src==dest){
            paths.push_back(path);
            path.pop_back();        // Backtracking
            return;
        }
        
        // recursive case
        for(int& nbr : graph[src]){
            dfs(graph,paths,path,nbr,dest);
        }
        
        path.pop_back();    // Backtracking
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int src = 0;
        int dest = graph.size()-1;
        vector<vector<int>> paths;
        vector<int> path;
        
        dfs(graph,paths,path,src,dest);
        
        return paths;
    }
};