// https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum/

// Easy

// Tags - Binary Search, Prefix-Sum

// What this problem wants to teach me?
// Whenever we want to improve the efficiency of an existing approach, 
// a good place to start is by considering the inefficiencies of the current approach.

#include<bits/stdc++.h>
using namespace std;

// Binary Search | Solution - Time = O(N*log(10^4)), Space = O(1)
class Solution {
public:
    bool isValid(vector<int>& nums, int stepSum){
        
        for(int num: nums){
            stepSum += num;
            
            if(stepSum<=0){
                return false;
            }
        }
        return true;
    }
    
    int minStartValue(vector<int>& nums) {
        int lo = 1;
        int hi = 10001;
        int ans = -1;
        
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            
            if(isValid(nums,mid)){
                ans = mid;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        
        return ans;
    }
};

// Prefix-Sum | Solution - Time = O(N), Space = O(1)
class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int minConsecuativeSum = INT_MAX;
        int currSum = 0;
        
        for(int num: nums){
            currSum += num;
            
            if(currSum < minConsecuativeSum){
                minConsecuativeSum = currSum;
            }
        }
        
        if(minConsecuativeSum >= 0){
            return 1;
        }
        
        return abs(minConsecuativeSum) + 1;
    }
};