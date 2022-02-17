// https://leetcode.com/problems/partition-equal-subset-sum/

// Medium

// Tags - Dynamic Programming, Array

// What this problem wants to teach me?
// Top Down to Bottom Up conversion
// Variation of subset sum

#include <bits/stdc++.h>
using namespace std;
// Bottom Up Dynamic Programming | Time = O(N*Sum(nums[i])) , Space = O(N*Sum(nums[i]))
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(begin(nums),end(nums),0);
        if(sum&1)
            return false;
        
        int halfSum = sum/2;
        vector<vector<bool>> dp(halfSum+1, vector<bool>(nums.size() + 1, false));
        for(int j=0; j<nums.size(); j++)
            dp[0][j] = true;
        
        for(int currSum=1; currSum<=halfSum; currSum++){
            for(int idx=1; idx<=nums.size(); idx++){
                bool include = false, exclude = false;
                if(nums[idx-1]<=currSum){
                    include = dp[currSum - nums[idx-1]][idx-1];
                }
                exclude = dp[currSum][idx-1];
                
                dp[currSum][idx] = include || exclude;
            }
        }
            
        return dp[halfSum][nums.size()];
    }
};

// Top Down Dynamic Programming | Time = O(N*Sum(nums[i])) , Space = O(N*Sum(nums[i]))
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(begin(nums),end(nums),0);
        if(total&1)
            return false;
        
        int halfSum = total/2;
        vector<vector<int>> dp(halfSum+1, vector<int>(nums.size(), -1));
        for(int j=0; j<nums.size(); j++)
            dp[0][j] = true;
            
        return isPossible(nums,dp, 0,halfSum);
    }
private:
    bool isPossible(vector<int>& nums, vector<vector<int>>&dp, int idx, int target){
        if(target==0)
            return true;
        if(idx>=nums.size())
            return false;
        
        if(dp[target][idx]!=-1)
            return dp[target][idx];
        
        bool include = false, exclude = false;
        if(nums[idx]<=target)
            include = isPossible(nums, dp,idx+1, target-nums[idx]);
        exclude = isPossible(nums,dp, idx+1, target);
        
        return dp[target][idx] = (include || exclude);
    }
};