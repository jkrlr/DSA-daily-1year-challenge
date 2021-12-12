// https://leetcode.com/problems/partition-equal-subset-sum/

// Medium

// Tags - Array, Dynamic Programming

// What this problem wants to teach me?
// Try to break down the problems in earlier seen problems
// This problem is variation of 0/1 Knapsack Problem + Subset Sum

#include <bits/stdc++.h>
using namespace std;

// Top-Down DP| Time - O(N*Sum), Space = O(N*Sum)
class Solution {
private:
    bool subsetSum(vector<int>& nums, vector<vector<int>>& dp, int sum, int i){
        if(sum==0)      // Sum found
            return true;
        if(i>=nums.size())   // Out of bound
            return false;
        
        if(dp[i][sum]!=-1)
            return dp[i][sum];
        
        bool exclude = false, include = false;
        if(nums[i]<=sum)
            include = subsetSum(nums,dp, sum-nums[i], i+1);
        exclude = subsetSum(nums, dp, sum, i+1);
        
        return dp[i][sum] = include || exclude;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(begin(nums), end(nums),0);
        if(sum&1)           // Odd Sum
            return false;
        
        sum /=2;
        vector<vector<int>> dp(nums.size() + 1, vector<int>(sum+1, -1));
        return subsetSum(nums,dp,sum,0);
    }
};

// BottomUp DP| Time - O(N*Sum), Space = O(N*Sum)
class Solution {
public:
    bool canPartition(vector<int>& ar) {
        int n = ar.size();
        long long int sum = 0;
        
        for(int i=0;i<n;i++)
            sum+=ar[i];
        
        if(sum%2==1)       // i.e. if sum is odd
            return false;
        
        else{  
            sum/=2;
            int t[n+1][sum+1];
            
            for(int i=0;i<=n;i++)
                for(int j=0;j<=sum;j++){
                    if(i==0)
                        t[i][j]=false;
                    if(j==0)
                        t[i][j]=true;
                }
            
            for(int i=1;i<=n;i++)
                for(int j=1;j<=sum;j++){
                    if(ar[i-1]<=j){
                        t[i][j] = (t[i - 1][j - ar[i - 1]] || t[i - 1][j]);
                    }
                    else
                        t[i][j] = t[i - 1][j];
                }

            return t[n][sum];
        }
    }
};