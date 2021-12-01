// https://leetcode.com/problems/search-insert-position/

// Easy

// Tags - Binary Search

// What this problem wants to teach me?
// For very sligh variation of Binary Search problem, Simply dry run the Binary Search on
// All the edge cases examples and then you will understand what to do and what to return in answer

#include<bits/stdc++.h>
using namespace std;

// Binary-Search | Time = O(n), Space = O(1)
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size()-1;
        
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid] < target){
                lo = mid + 1;
            }
            else{
                hi = mid-1;
            }
        }
        
        return lo;
    }
};