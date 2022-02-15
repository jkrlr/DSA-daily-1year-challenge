// https://leetcode.com/problems/single-number/

// Easy

// Tags - Bit Manipulation - Xor, Array

// What this problem wants to teach me?
// Xor


#include<bits/stdc++.h>
using namespace std;

// Bit Manipulation - Xor  | Time - O(N), Space - O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(auto& num: nums)
                result = result ^ num;
        
        return result;
    }
};