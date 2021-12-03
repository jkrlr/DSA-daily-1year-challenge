// https://leetcode.com/problems/maximum-product-subarray/

// Medium

// Tags - Array, Dynamic Programming

// What this problem wants to teach me?
// In Contiguous Sliding Window Subsequence type problems, BottomUp Dp is much easier to think than TopDown Dp
// For contiguous subsequence of array containing both +ve and -ve integers,
// For finding max or min finding problems, you can keep track of both prevMax and prevMin 
// for finding the next starting seq. max or min, starting from current index i or starting from index j(0<=j<i) to i

#include<bits/stdc++.h>
using namespace std;

// Brute-Force | Time = O(n^2), Space = O(1)

// BottomUp Space-Optimized DP | Time = O(n), Space = O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int ans = nums[0]; 
        int mx = ans, mn = ans; // we keep also the minimum-product subarray for the case of multiplying negative with negative
        for(int i=1; i<nums.size(); i++){
            if (nums[i]< 0){    // if we got a negative element, we will swap maximum with minimum
                swap(mx,mn);
            }
            
            mx = max(mx*nums[i], nums[i]);
            mn = min(mn*nums[i], nums[i]);
            
            ans = max(ans,mx);
        }
        
        return ans;
    }
};

// Sol-2, BU DP
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int ans = nums[0];
        int currMaxProd = 1, currMinProd = 1; 
        
        for(int num: nums){
            if (num==0){    // If current element is zero, reset the max and min
                currMaxProd = 1, currMinProd = 1;
                continue;
            }
            
            int tmp = currMaxProd;
            currMaxProd = max({currMaxProd*num, currMinProd*num, num});
            currMinProd = min({tmp*num, currMinProd*num, num});
            
            ans = max({ans,currMaxProd,currMinProd});
        }
        
        return ans;
    }
};