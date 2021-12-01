// https://leetcode.com/problems/maximum-subarray/

// Easy

// Tags - Array, Dynamic Programming, Kadane's Algorithm, Divide and Conquer(Less Obvious)

// What this problem wants to teach me?
// Kadane's Algorithm can be used to find the contiguous subarray maxSum
// When, A problem is given to me to find the optimal solution, Then intutively first approach comes in
// my mind is Dp/greedy/Heap etc.
// Solve problem by making cases, If the cases will be merged Then it will be merged, while dry running on examples
// For contiguous range maximum/minimum type problems, Think in terms of two inidicies/pointers i and j and 
// If this doesn't solve purpose, Then think starting at i or ending at i

#include<bits/stdc++.h>
using namespace std;

// Brute-Force | Time = O(N^3) or O(N^2), Space = O(1) => By using Three Loops or Two Loops sum for every i...j

// DP-BottomUp | Time - O(n), Space - O(n)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n);
        
        dp[0] = nums[0];
        for(int i=1; i<n; i++){
            dp[i] = max(nums[i], nums[i] + dp[i-1]);
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};

// Kadane's Algorithm | Time- O(n), Space- O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxi = nums[0];
        
        for(int num: nums){
            sum += num;
            if(maxi < sum)  maxi = sum;
            if(sum<0)   sum = 0;
        }
        return maxi;
    }
};

// In Case If we'have to findout the subarray, Then we can use Two Pointer Approach also
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
         int maxElement = *max_element(nums.begin(), nums.end());
        
        if(maxElement <= 0){
            return maxElement;
        }
        
        int left = 0, right = 0; 
        int maxSum = INT_MIN, currSum = 0;
        while(right<nums.size()){
            currSum += nums[right];
            right++;
            
            while(left<right && currSum < 0){
                currSum -= nums[left++];
            }
            
            maxSum = max(maxSum,currSum);
        }
        
        return maxSum;
    }
};

// DP-TopDown | Time - O(n), Space - O(n)
class Solution {
private:
    int solve(vector<int>& nums, int idx, vector<int>& dp){
        if(idx==nums.size()-1){
            return dp[idx] = nums[idx];
        }
        
        if(dp[idx]!=INT_MIN){
            return dp[idx];
        }
        
        return dp[idx] =  max(nums[idx], nums[idx] + solve(nums,idx+1,dp));
    }
public: 
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,INT_MIN);
        solve(nums,0,dp);
        
        return *max_element(dp.begin(),dp.end());
    }
};

// Divide and Conquer (Less Obvious) | Time = O(nLogn), Space = O(Logn)
class Solution {
private:
    int solve(vector<int>& nums, int left, int right){
        if(left>right){
            return INT_MIN;
        }
        
        int mid = left + (right-left)/2;
        int leftSum = 0, rightSum = 0;
        
        int currSum = 0;
        for(int i=mid-1; i>=left; i--){
            currSum += nums[i];
            leftSum = max(leftSum,currSum);
        }
        
        currSum = 0;
        for(int i=mid + 1; i<=right; i++){
            currSum += nums[i];
            rightSum = max(rightSum,currSum);
        }
        
        int leftSubproblem = solve(nums,left,mid-1);
        int rightSubproblem = solve(nums,mid+1,right);
        
        return max({leftSubproblem, rightSubproblem, leftSum+nums[mid]+rightSum});
    }
public:
    int maxSubArray(vector<int>& nums) {
        return solve(nums,0,nums.size()-1);
    }
};

// Divide and Conquer Optimized | Time = O(n), Space = O(n)
class Solution {
private:
    vector<int>prefix, suffix;  // O(n) space
private:
    int solve(vector<int>& nums, int left, int right){
        if(left==right){
            return nums[left];
        }
        
        int mid = left + (right-left)/2;
        
        int leftSubproblem = solve(nums,left,mid);
        int rightSubproblem = solve(nums,mid+1,right);
        
        return max({leftSubproblem, rightSubproblem, prefix[mid]+suffix[mid+1]});
    }
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        prefix = suffix = nums;
        
        for(int i=1 ; i<n; i++){
            prefix[i] = max(prefix[i], prefix[i] + prefix[i-1]);
        }
        
        for(int i=n-2; i>=0; i--){
            suffix[i] = max(suffix[i], suffix[i] + suffix[i+1]);
        }
        
        return solve(nums,0,n-1);
    }
};