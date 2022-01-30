// https://leetcode.com/problems/rotate-array/

// Medium

// Tags - Two Pointer - Multiple Reverse Array, Math

// What this problem wants to teach me?
// One of the tricky soln to come up

#include<bits/stdc++.h>
using namespace std;

// Two Pointer - Multiple Reverse | Time - O(N), Space = O(1)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int N = nums.size();
        k = k % N;
        
        // 1. InPlace Reverse the whole array
        rangeReverse(nums,0,N-1);
        
        // 2. Reverse the array from 0 to k-1
        rangeReverse(nums,0,k-1);
        
        // 3. Reverse the array from k to N-1
        rangeReverse(nums,k,N-1);
    }
private:
    void rangeReverse(vector<int>& nums, int lo, int hi){
        while(lo<hi){
            swap(nums[lo], nums[hi]);
            lo++;
            hi--;
        }
    }
};