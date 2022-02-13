// https://leetcode.com/problems/maximum-and-sum-of-array/

// Hard

// Tags - DP, Bitmasking

// What this problem wants to teach me?
// When question is saying to find the min/max and greedy will not work then try dp
// for mapping a subset of integers from an array -> to do this efficiently use bitmasking
// __builtin_popcount(int n), __builtin_popcountl(long n), __builtin_popcountll(long long n) => return number of set bit in 'n'

// Revision Problem

#include<bits/stdc++.h>
using namespace std;

// DP + Bitmasking | Time - O(2^n * n), Space - O(2^n)
class Solution {
public:
    int maximumANDSum(vector<int> nums, int numSlots) {
        while(nums.size()<2*numSlots){
            nums.push_back(0);
        }
        
        int n = nums.size();
        int N = (1<<n);
        vector<int> dp(N,0);
        
        for(int mask = 1; mask<N; mask++){
            int slots = (__builtin_popcount(mask) + 1)/2; 
            
            for(int i=0; i<n; i++){
                if(mask & (1<<i)){
                    dp[mask] = max(dp[mask], dp[mask ^ (1<<i)] + (slots & nums[i]));
                }
            }
        }
        
        return dp[N-1];
    }
};