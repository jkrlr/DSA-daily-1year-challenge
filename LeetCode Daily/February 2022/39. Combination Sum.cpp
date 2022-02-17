// https://leetcode.com/problems/combination-sum/

// Medium

// Tags - Recursion + Backtracking, Array

// What this problem wants to teach me?
// Unbounded KnapSack Problem 
// Pay attention here, array contains distinct numbers only - so, all generated ways are unique
// If the array contains duplicates, then first remove duplicates and then apply the below approach
// or sort the array and skip the duplicates ar[i-1]==ar[i]=>skip duplicates in recurison 


#include<bits/stdc++.h>
using namespace std;

// Recursion + Backtracking + Unbounded KnapSack Problem  | Time - O(2^N), Space - O(N+N)
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> combinations;
        vector<int> currcombination;
        
        generateCombinations(candidates, combinations,currcombination, target,0);
        
        return combinations;
    }
private:
    void generateCombinations(vector<int>& candidates, vector<vector<int>>& combinations, vector<int>& currcombination, int target, int idx){
        // base case
        if(target==0){
            combinations.push_back(currcombination);
            return;
        }
        if(idx>=candidates.size())
            return;
        
        // recursive case
        if(candidates[idx]<=target){
            currcombination.push_back(candidates[idx]);
            generateCombinations(candidates,combinations,currcombination,target-candidates[idx], idx);
            currcombination.pop_back();
        }
        
        generateCombinations(candidates,combinations,currcombination,target, idx+1);
    }
};