// https://leetcode.com/problems/combination-sum-ii/

// Medium

// Tags - Recursion + Backtracking, Handling Duplicates, Array

// What this problem wants to teach me?
// How to handle duplicates while generating the subset having sum equal to target sum

#include<bits/stdc++.h>
using namespace std;

// Recursion + Backtracking + Handling Duplicates  | Time - O(2^N + NLogN), Space - O(N+N)
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> combinations;
        vector<int> currcombination;
        
        generateCombinations(candidates, combinations,currcombination, target,0);
        
        return combinations;        
    }
private:
    void generateCombinations(vector<int>& candidates, vector<vector<int>>& combinations, vector<int>& currcombination, int target, int start){
        // base case
        if(target==0){
            combinations.push_back(currcombination);
            return;
        }
        if(start>=candidates.size() || target < 0)
            return;
        
        // recursive case
        int prev = -1;      // initialize prev to some invalid no, that array doesn't contain
        for(int idx=start; idx<candidates.size(); idx++){
            if(candidates[idx]==prev)   // skip the duplicates
                continue;
            
            currcombination.push_back(candidates[idx]);
            generateCombinations(candidates,combinations,currcombination,target-candidates[idx], idx+1);
            currcombination.pop_back();

            prev = candidates[idx];
        }
    }
};