// https://leetcode.com/problems/find-the-town-judge/

// Easy

// Tags - Indegree-Outdegree Concept, Hash Table, Graph, Array

#include<bits/stdc++.h>
using namespace std;

// Indegree-Outdegree Concept | Time = O(T+N), Space = O(2N)
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>outdegree(n+1,0);
        vector<int>indegree(n+1,0);
        
        for(auto& edge: trust){
            int from = edge[0];
            int to = edge[1];
            
            outdegree[from]++;
            indegree[to]++;
        }
        
        for(int i=1; i<=n; i++){
            if(outdegree[i]==0 && indegree[i]==n-1)
                return i;     
        }
        
        return -1;
    }
};

// Indegeree - outdegree = balance Concept | Time = O(T+N), Space = O(N)
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>balance(n+1,0);
        
        for(auto& edge: trust){
            int from = edge[0];
            int to = edge[1];
            
            balance[from]--;
            balance[to]++;
        }
        
        for(int i=1; i<=n; i++){
            if(balance[i]==n-1)
                return i;     
        }
        
        return -1;
    }
};

// Brute-Force Space Optimized| Time = O(T+N), Space = O(N)
