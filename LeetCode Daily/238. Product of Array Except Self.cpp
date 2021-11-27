// https://leetcode.com/problems/product-of-array-except-self/

// Medium

// Tags - Array, PrefixProduct + SuffixProduct

// What this problem wants to teach me?
// How to replace the PrefixProduct/SuffixProduct or PrefixSum/SuffixSum array by storing the result into a single variable

#include<bits/stdc++.h>
using namespace std;

// PrefixProd + SuffixProd | Time = O(N), Space = O(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n,1);
        
        int prefixProd = 1, suffixProd = 1;
        for(int i=0; i<n; i++){
            result[i] *= prefixProd;
            prefixProd *= nums[i];
            
            result[n-i-1] *=suffixProd;
            suffixProd *= nums[n-i-1];
        }
        
        return result;
    }
};