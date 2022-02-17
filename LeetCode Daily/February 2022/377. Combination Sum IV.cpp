// https://leetcode.com/problems/combination-sum-iv/

// Medium

// Tags - Dynamic Programming

// What this problem wants to teach me?
// How to apply dp if for considering a particular element of array and 
// then in subsequence recursive calls we can start from the beginning of array
// apparantely to be appeared like going from some idx to the left of it and to the right of it

#include<bits/stdc++.h>
using namespace std;

// Top-Down Dynamic Programming  | Time - O(n*Target), Space - O(N+Target)
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1,-1);
        dp[0] = 1;
         
        countCombinations(nums,dp,target);
        return dp[target];
    }
private:
    int countCombinations(vector<int>& nums, vector<int>& dp, int target){
        // base case
        if(target==0){
            return 1;
        }
        
        if(dp[target]!=-1)
            return dp[target];
        
        // recursive case
        int combinations = 0;
    
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<=target)
                combinations += countCombinations(nums,dp,target-nums[i]);
        }
        
        return dp[target]=combinations;
    }
};

// Bottom-Up Dynamic Programming  | Time - O(n*Target), Space - O(N)
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target+1,0);    // pay attention to unsigned int -. to avoid integer overflow
        dp[0] = 1;
        for(int currTarget=1; currTarget<=target; currTarget++){
            for(int& num: nums){
                if(num<=currTarget){
                    dp[currTarget] += dp[currTarget-num];
                }
            }
        } 
        
        return dp[target];
    }
};

// Bottom-Up Slightly Optimized Dynamic Programming  | Time - O(n*Target), Space - O(N)
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<uint> dp(target+1,0);
        dp[0] = 1;
        for(int currTarget=1; currTarget<=target; currTarget++){
            for(int& num: nums){
                if(num<=currTarget){
                    dp[currTarget] += dp[currTarget-num];
                }
                else
                    break;
            }
        } 
        
        return dp[target];
    }
};