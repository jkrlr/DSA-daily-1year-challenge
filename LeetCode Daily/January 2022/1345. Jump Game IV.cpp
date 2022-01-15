// https://leetcode.com/problems/palindrome-partitioning/

// Hard

// Tags - BFS, Hash Map

// What this problem wants to teach me?
/* Explain NO DP -
    One of the conditions for Dynamic programming is that the topological ordering must exists which means that there should not be any cycles. 
    However, in this case, because of the back edges, there is a cycle. 
    Therefore, DP cannot be used. However , DP can be used but it will not be efficient. */
/* Just a simple breadth first search, at any index where can you go.
    (1). All nodes which have same value as the index you are currently on.
    (2). Previous node (index - 1)
    (3). Next node (index + 1)
    Why should it return minimum jumps?
    In traversal, we put a condition that whenever we reach last node, we return our answer, hence its minimum. */

#include<bits/stdc++.h>
using namespace std;

// BFS | Time = O(N), Space = O(N)
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if(n<=1)    
            return 0;
        
        unordered_map<int, vector<int>>indicesOfValue;
        for(int i=0; i<n; i++)
            indicesOfValue[arr[i]].push_back(i);
        
        queue<int> curs;   // store current layer
        vector<bool> visited(n,false);
        curs.push(0);
        visited[0] = true;
        int step = 0;
        
        // when current layer exists
        while(!curs.empty()){
            
            // iterate the layer
            for(int len = curs.size(); len > 0; --len){
                int idx = curs.front();
                curs.pop();
                
                // check if reached end
                if(idx == n-1)
                    return step; 
                
                vector<int>& next = indicesOfValue[arr[idx]];
                // insert neighbors
                next.push_back(idx -1);
                next.push_back(idx + 1);
                
                // check same value and neighbors
                for(int j: next){
                    if(j>=0 && j<n && visited[j]==false){
                        visited[j] = true;
                        curs.push(j);
                    }
                }
                
                // clear the list to prevent redundant search
                next.clear();   // avoid later lookup of indicesOfValue of arr[i]
            }
            
            step++;
        }
        
        return -1;
    }
};