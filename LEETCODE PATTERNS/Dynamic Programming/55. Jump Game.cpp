// https://leetcode.com/problems/jump-game/

// Medium

// Tags - Dynamic Programming, Greedy, Array

// What this problem wants to teach me?
// Tricky Solution 
// Revision


#include <bits/stdc++.h>
using namespace std;

// Greedy | Time - O(N), Space - O(1)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reachable = 0;
        for(int i=0; i<nums.size(); i++){
            if(reachable < i)
                return false;
            
            reachable = max(reachable, i+nums[i]);
        }
        
        return true;
    }
};

// Top Down Dynamic Programming | Time = O(N*Max(nums[i])) , Space = O(N+N)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return isPossible(nums,dp,0);
    }
private:
    bool isPossible(vector<int>& nums, vector<int>& dp, int idx){
        if(idx==nums.size()-1)
            return true;
        
        if(dp[idx]!=-1)
            return dp[idx];
        
        for(int jump=1; jump<=nums[idx]; jump++){
            if(idx+jump < nums.size()){
                bool nextJump = isPossible(nums, dp, idx+jump);
                if(nextJump==true)
                    return dp[idx] = true;
            }
        }
        
        return dp[idx] = false;
    }
};