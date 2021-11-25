// https://leetcode.com/problems/largest-component-size-by-common-factor/

// Hard

// Tags - Array, Math, Union-Find

// What this problem wants to teach me?
// How to create DSU and use it in problems asking for maximum size of connected component problems
// The key point to notice is that(ki DSU lagega ki nahi) all the values given to you should be distinct i.e. No duplicates
// Means A input value can't be belong to two different sets, It can only be present in only one set

#include<bits/stdc++.h>
using namespace std;

// Disjoint-Set Union Find | Time - O(N*Sqrt(max(A[i]))), Space - O(10^5 or Max(A[i]))-for DSU
class DisjointSetUnion{
private:
    vector<int>parent;  // used for storing the parent as well as the current size
public:
    DisjointSetUnion(){
        parent.resize(100001,-1);
    }
    
    // Time = O(1)
    void _union(int x , int y){ 
        int root1 = find(x);
        int root2 = find(y);
        
        if(root1==root2){
            return;
        }
        
        else if(parent[root2] < parent[root1]){
            parent[root2] += parent[root1];
            parent[root1] = root2;
        }
        else{
            parent[root1] += parent[root2];
            parent[root2] = root1;            
        }
    }

    // Time = O(α(n))
    int find(int x){
        if(parent[x] < 0){
            return x;
        }
        return parent[x] = find(parent[x]);
    }
};

class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        DisjointSetUnion dsu;
        
        for(int num : nums){
            for(int factor=2; factor*factor<=num; factor++){
                if(num%factor==0){
                    dsu._union(num, factor);
                    dsu._union(num, num/factor);
                }
            }
        }
        
        int ans = 0;
        unordered_map<int,int> mp;
        for(int num : nums){
            int parentNum = dsu.find(num);
            mp[parentNum]++;
            
            ans = max(ans, mp[parentNum]);
        }
        
        return ans;
    }
};

// Brute Force(TLE) => DFS + GCD | Time - O(N^2*LogN), Space - O(N^2)
class Solution {
private:
    vector<vector<int>> adjList;
    vector<int> visited;
private:
    bool gcd(int a, int b){
        if(b==0){
            return a;
        } 
        return gcd(b,a%b);
    }
private:
    int dfs(int src){
        visited[src] = true;
        
        int currSize  = 1;
        for(int nbr : adjList[src]){
            if(visited[nbr]==false){
                currSize += dfs(nbr);
            }
        }
        
        return currSize;
    }
public:
    int largestComponentSize(vector<int>& nums) {
            int n = *max_element(nums.begin(), nums.end());
            
            adjList.clear();
            adjList.resize(n+1);
            
            for(int u : nums){
                for(int v : nums){
                    if(gcd(u,v) > 1){
                        adjList[u].push_back(v);
                        adjList[v].push_back(u);
                    }
                }
            }
            
            visited.clear();
            visited.resize(n+1,false);
            
            int largest = 0;
            for(int vertex : nums){
                if(visited[vertex]==false){
                    largest = max(largest, dfs(vertex));
                }
            }
            
            return largest;
        }
};