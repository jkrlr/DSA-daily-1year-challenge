// https://leetcode.com/problems/accounts-merge/

// Medium

// Tags - DSU, BFS 

// What this problem wants to teach me?
// Any problem that involves merging connected components is a natural fit for the Disjoint Set Union (DSU) data structure.

#include<bits/stdc++.h>
using namespace std;

// DSU | Time = O(NK*Log(NK)) , Space = O(NK)
class DSU{
  private:
    vector<int> parent;
  public:
    DSU(int n){
        parent.resize(n,-1);
    }
    
    void _union(int x, int y){
        int root1 = find(x);
        int root2 = find(y);
        
        if(root1==root2){
            return;
        }
        
        if(parent[root2] < parent[root1]){
            parent[root2] += parent[root1];
            parent[root1] = root2;
        }
        else{
            parent[root1] += parent[root2];
            parent[root2] = root1;
        }
    }
    
    int find(int x){
        if(parent[x]<0){
            return x;
        }
        
        return parent[x] = find(parent[x]);
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int accountListSize = accounts.size();
        DSU dsu(accountListSize);
        
        // Maps email to their component index
        unordered_map<string, int> emailGroup;
        
        for(int i=0; i<accountListSize; i++){
            int accountSize = accounts[i].size();
            string accountName = accounts[i][0];
            
            for(int j=1; j<accountSize; j++){
                string email = accounts[i][j];
                
                // If this is the first time seeing this email then
                // assign component group as the account index
                if(emailGroup.find(email)==emailGroup.end()){
                    emailGroup[email] = i;
                }
                else{
                   // If we have seen this email before then union this
                    // group with the previous group of the email
                    dsu._union(i,emailGroup[email]);
                }
            }
        }
        // Store emails corresponding to the component's parent
        unordered_map<int, vector<string>> components;
        for(auto it: emailGroup){
            string email = it.first;
            int group = it.second;
            
            components[dsu.find(group)].push_back(email);
        }
        
        // Sort the components and add the account name
        vector<vector<string>> mergedAccounts;
        
        for(auto it: components){
            int group = it.first;
            vector<string> component = {accounts[group][0]};
            component.insert(component.end(), it.second.begin(), it.second.end());
            sort(component.begin()+1, component.end());
            mergedAccounts.push_back(component);
        }
        
        return mergedAccounts;
    }
};