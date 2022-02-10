// https://leetcode.com/problems/subarray-sum-equals-k/

// Medium

// Tags - Unordered_Map, prefix sum

// What this problem wants to teach me?
// Tricky Problem

#include<bits/stdc++.h>
using namespace std;

// Unordered_Map + prefix sum | Time - O(N), Space - O(N)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int result = 0, currSum = 0;
        unordered_map<int, int> prefixSums;
        prefixSums[0] = 1;
        
        for(auto& num: nums){
            currSum += num;
            int diff = currSum - k;
            
            result += prefixSums[diff];
            prefixSums[currSum]++;
        }
        
        return result;
    }
};