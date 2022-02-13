// https://leetcode.com/problems/subsets/

// Medium

// Tags - Subset Generation - (Recursion + Backtracking) or Bitmasking, Array

// What this problem wants to teach me?
// How to generate the all the subsets of an array


#include<bits/stdc++.h>
using namespace std;

// Subset Generation - Bitmasking  | Time - O(2^N * N), Space - O(N)
// Besides, this method has the best time complexity, 
// and as a bonus, it generates lexicographically sorted output for the sorted inputs.
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        int N = 1<<n;           // Total number of subsets
        
        for(int mask=0; mask<N; mask++){
            vector<int> curSubset;
            for(int i=0; i<n; i++){
                if(mask & (1<<i)){   // if ith bit is set in the mask, then include the element at index i
                   curSubset.push_back(nums[i]);
                }
            }
            
            result.push_back(curSubset);
        }
        
        return result;
    }
};

// Subset Generation - Recursion + Backtracking  | Time - O(2^N*N), Space - O(N + N)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curSubset;
        
        generateSubsets(nums,result,curSubset,0);
        
        return result;
    }
private:
    void generateSubsets(vector<int>& nums, vector<vector<int>>& result, vector<int>& curSubset, int idx){
        // base case
        if(idx==nums.size()){
            result.push_back(curSubset);
            return;
        }
        
        // recursive case
        generateSubsets(nums,result,curSubset, idx+1);   // exclude the current element
        
        curSubset.push_back(nums[idx]);                 // include the current element to the current subset
        generateSubsets(nums,result,curSubset,idx+1);   
        curSubset.pop_back();                          // backtrack
    }
};