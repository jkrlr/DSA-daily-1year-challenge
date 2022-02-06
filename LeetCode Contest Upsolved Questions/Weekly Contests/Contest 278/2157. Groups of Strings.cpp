// https://leetcode.com/problems/groups-of-strings/

// Hard

// Tags - Union Find, Bit Manipulation, String

// What this problem wants to teach me?
// How and when to apply the Union Find Data Structure
// Wherever in the question you will see the word group blindly follow the Union-Find Method
/* For subset generations optimizations, we can use bit-masking technique
    more precisely saying If the mask of subset is in the range of int and the order of the numbers doesn't matter
    then we should use the bitmasking for the subset generation */
// Union-Find problems can also be with the help of dfs/bfs.

#include <bits/stdc++.h>
using namespace std;

// Union-Find - TLE but More Readible Code | Time - O(), Space = O()
class DSU{
 public:
    vector<int> parent;
    int groupCount, maxSize;
    DSU(int n){
        parent.resize(n,-1);
        groupCount = n;
        maxSize = 1;
    }
    
    void _union(int x, int y){
        int root1 = _find(x);
        int root2 = _find(y);
        
        if(root1==root2)
            return;
        else if(parent[root2] < parent[root1]){
            parent[root2] += parent[root1];
            parent[root1] = root2;
            
            maxSize = max(maxSize, -parent[root2]);
        }
        else{
            parent[root1] += parent[root2];
            parent[root2] = root1;
            
             maxSize = max(maxSize, -parent[root1]);
        }
        
        groupCount--;
    }
    
    int _find(int x){
        if(parent[x] < 0)
            return x;
        return parent[x] = _find(parent[x]);
    }
};

class Solution {
public:
    vector<int> groupStrings(vector<string>& words) {
        int n = words.size();
        unordered_map<int, vector> maskToIndex;
        
        vector<int> masks(n);
        for(int i=0; i<n; i++){
            masks[i] = getMask(words[i]);
            maskToIndex[masks[i]] = i;
        }
        
        DSU dsu(n);
        for(int i=0; i<n; i++){
            // This is necessary to union the duplicate words
            dsu._union(i, maskToIndex[masks[i]]);
            
            for(char& ch: words[i]){
                // Removing ch from the word
                int maskWithoutCh = masks[i] ^ (1<<(ch-'a'));
                if(maskToIndex.count(maskWithoutCh)){
                    dsu._union(i, maskToIndex[maskWithoutCh]);
                }
                
                // Replace ch with any other character
                for(int j=0; j<26; j++){
                    // Skip if the word already contains the char at j
                    if(j == ch-'a')
                        continue;
                    
                    int maskWithReplace = maskWithoutCh | (1<<j);
                    if(maskToIndex.count(maskWithReplace)){
                        dsu._union(i, maskToIndex[maskWithReplace]);
                    }
                }
            }
        }
        
        return {dsu.groupCount, dsu.maxSize};
    }
private:
    int getMask(string& word){
        int mask = 0;
        for(char& ch: word){
            int idx = ch - 'a';
            mask = mask | (1<<idx);
        }
        
        return mask;
    }
};

// Union-Find - Accepted but Less Readible Code | Time - O(), Space = O()
class DSU{
 public:
    vector<int> parent;
    
    DSU(int n){
        parent.resize(n,-1);
    }
    
    void _union(int x, int y){
        int root1 = _find(x);
        int root2 = _find(y);
        
        if(root1==root2)
            return;
        else if(parent[root2] < parent[root1]){
            parent[root2] += parent[root1];
            parent[root1] = root2;
        }
        else{
            parent[root1] += parent[root2];
            parent[root2] = root1;
        }
    }
    
    int _find(int x){
        if(parent[x] < 0)
            return x;
        return parent[x] = _find(parent[x]);
    }
};

class Solution {
public:
    vector<int> groupStrings(vector<string>& words) {
        int n = words.size();
        DSU dsu(n+1);
        
        unordered_map<int, int> mp, delMp;
        
        for(int i=0; i<n; i++){
            int hash = 0;
            
            for(auto& ch: words[i])
                hash = hash | (1<<(ch-'a'));
            
            for(int j=0; j<26; j++){
                if((hash>>j) & 1){
                    
                    int t_hash = hash ^ (1<<j);
                    
                    if(mp.count(t_hash))
                        dsu._union(mp[t_hash], i);
                    
                    if(delMp.count(t_hash))
                        dsu._union(delMp[t_hash], i);
                    else
                        delMp[t_hash] = i;
                }
                else{
                    int t_hash = hash | (1<<j);
                    if(mp.count(t_hash))
                        dsu._union(mp[t_hash], i);
                }
            }
            
            mp[hash] = i;
        }
        
        
        unordered_map<int, int> result;
        for(int i=0; i<n; i++){
            int parent = dsu._find(i);
            result[parent]++;
        }

        int maxSizeOfGrp = 0;
        for(auto& [root, sizeOfGrp] : result)
            maxSizeOfGrp = max(maxSizeOfGrp, sizeOfGrp);
        
        int numberOfGrps = result.size();
        return {numberOfGrps, maxSizeOfGrp};
    }
};
