// https://leetcode.com/problems/jump-game-iii/

// Medium

// Tags - Recursion + BackTracking, DFS, BFS

// What this problem wants to teach me?
/* Why not Dp is used here although overlapping subproblem are happening in this problems?
    The first reason is that The problem isn't asking about optimal substructure (i.e. not asking to find max/min property)
    And for finding, whether a way is present or not we've not required to the answer from the previous state
    But only we've required not to visit again-and-again to avoid the stack overflow
    This can be done using simply the visited array or inplace changes in input array 
    Hence, this is no use of dp => dp isn't used */
/* When we've to explore the nodes in graph(finding a target node)  or 
  explore the 2d-matrix or 1d-matrix to find the path or find the target node
  Then, in such cases we can use DFS and BFS to solve the problem
  DFS is more efficient is here*/

#include <bits/stdc++.h>
using namespace std;

// Recursion + BackTracking | Time = O(n), Space = O(n)-depth of recursion
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if(start < 0 || start >= arr.size() || arr[start]==INT_MIN)
            return false;
        
        if(arr[start] == 0)
            return true;
        
        int fwdIdx =  start + arr[start];
        int bwdIdx =  start - arr[start];
        
        int tmp = arr[start];
        arr[start]=INT_MIN;     // mark current Idx as visited
        
        bool backward = canReach(arr, bwdIdx);
        if(backward)
            return true;
        
        bool forward = canReach(arr,fwdIdx);
        if(forward)
            return true;
        
        arr[start] = tmp;   // Backtracking
        
        return false;
    }
};

// DFS | Time = O(n), Space = O(n)
class Solution {
private:
    bool dfs(vector<int>& arr,vector<int>& visited, int start){
        if(start < 0 || start >= arr.size() || visited[start] == true)
            return false;
        
        if(arr[start] == 0)
            return true;
        
        visited[start] = true;
        
        return dfs(arr, visited, start - arr[start]) || dfs(arr, visited, start + arr[start]);
        
    }
public:
    bool canReach(vector<int>& arr, int start) {
        vector<int>visited(arr.size(),false);
        
        return dfs(arr,visited,start);
    }
};

// BFS | Time = O(n), Space = O(n)

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        
        vector<bool> visited(n,false);
        queue<int> q;
        
        q.push(start);
        visited[start] = false;
        
        while(!q.empty()){
            int idx = q.front();
            q.pop();
            
            if(arr[idx] == 0)
                return true;
            
            if(visited[idx]==false){
                visited[idx] = true;
                
                if(idx-arr[idx]>=0) 
                    q.push(idx-arr[idx]);
                
                if(idx+arr[idx]<n)
                    q.push(idx+arr[idx]);
            }
        }
        
        return false;
    }
};