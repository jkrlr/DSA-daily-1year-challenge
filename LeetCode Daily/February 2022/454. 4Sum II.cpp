// https://leetcode.com/problems/4sum-ii/

// Medium

// Tags - Hash Table-LookUp and Freq Cnt, Array

// What this problem wants to teach me?
// Think edge case and then proceed carefully and follow the fundamentals

#include<bits/stdc++.h>
using namespace std;

// Hash Table-LookUp and Freq Cnt | Time = O(N^2 + N^2), Space = O(2*N)
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> nums3And4ToFreq;
        for(int& num3 : nums3){
            for(int& num4 : nums4){
                int sm = num3 + num4;
                nums3And4ToFreq[sm]++;
            }
        }
        
        int cnt = 0;
        for(int& num1 : nums1){
            for(int& num2 : nums2){
                int reqSum = 0 - (num1 + num2);
                
                // if(nums3And4ToFreq.count(reqSum)>0)  // In this case it have to rehash. So, time taken will be more
                cnt += nums3And4ToFreq[reqSum];         // After commenting the if -> it runs faster
            }
        }
        
        return cnt;
    }
};