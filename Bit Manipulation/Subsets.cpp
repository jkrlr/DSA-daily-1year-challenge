// Subsets
// https://leetcode.com/problems/subsets/

// Time Complexity = O(Nx2^N) -> to generate all subsets and then copy them into res array.
// Space Complexity = O(Nx2^N) -> to keep all the subsets of length N, since each of N elements could be present or absent.

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& ar) {
        int n = ar.size();
        vector<vector<int>> res;

        int tot_subset = 1<<n ; // i.e Total no. of subsets = 2^n
        
        for(int mask=0;mask<tot_subset;mask++){
            vector<int> tmp;
       
            for(int i=0;i<n;i++){
                int f = (1<<i);
                
                // Check whether the ith bit set or not
                // If ith bit is set -> then include that
                // element of ar into the subset
                if(mask&f){
                    tmp.push_back(ar[i]);
                }
            }
            res.push_back(tmp);
        }
       return res; 
    }
};