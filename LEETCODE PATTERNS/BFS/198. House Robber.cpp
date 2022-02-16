// https://leetcode.com/problems/house-robber/

// Medium

// Tags - Dynamic Programming, Array

// What this problem wants to teach me?
// How to use top down to build the solution from the left side to right side (means 0 to n-1)

#include <bits/stdc++.h>
using namespace std;

// BBottom-Up - Space Optimized DP  | Time = O(N) , Space = O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return nums[0];
        
        vector<int> dp(n,0);
        int prevOfPrev = nums[0];
        int prev = max(nums[0], nums[1]);
        
        for(int i=2; i<n; i++){
            int current = max(prev, prevOfPrev + nums[i]);
            
            prevOfPrev = prev;
            prev = current;
        }
        
        return prev;
    }
};