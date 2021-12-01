// https://leetcode.com/problems/single-element-in-a-sorted-array/

// Medium

// Tags - Array, Binary-Search, EVEN-ODD Index Pair Concept

// What this problem wants to teach me?
// How to decode the hidden information give in question to write the Binary Search if() conditions
// In this case the hidden info is size of array will be odd or we can also interprete the info as
// consecuative two same elements appears at conseuative even and odd indices
// If the current index is even Then XOR of index with 1 (i.e. index^1 ) gives:
//  1. If the index is odd, Then result = index - 1 (which is even index or prev index)
//  1. If the index is even, Then result = index + 1 (which is odd index or next index)

#include<bits/stdc++.h>
using namespace std;

// Binary-Search, Even-Odd index Pair Concept | Time - O(n), Space - O(1)
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;     // Pay Attention-1
        
        while(low < high){ // Pay Attention-2
            int mid = low + (high-low)/2;

			// If we are on left side, move right
			// if we are on right side, move left
            if(nums[mid]==nums[mid^1]){ // Pay Attention-3
                low = mid + 1;
            }
            else{
                high = mid;
            }
        }
        
        return nums[low]; // Pay Attention-4
    }
};

// Binary-Search, Even-Odd index Pair Concept | Time - O(n), Space - O(1)
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-2; // Pay Attention-1
        
        while(low<=high){   // Pay Attention-2
            int mid = low + (high-low)/2;

			// If we are on left side, move right
			// if we are on right side, move left
            if(nums[mid]==nums[mid^1]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        
        return nums[low];   // Pay Attention-3
    }
};

// Binary-Search, Array size is odd Concept | Time - O(n), Space - O(1)
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int lo = 0;
        int hi = n-1;
        
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            
            if((mid-1>=0 && nums[mid]==nums[mid-1] && mid%2==1) || (mid+1<n && nums[mid]==nums[mid+1] && mid%2==0)){
                lo = mid + 1;
            }
            else if((mid-1>=0 && nums[mid]==nums[mid-1] && mid%2==0) || (mid+1<n && nums[mid]==nums[mid+1] && mid%2==1)){
                hi = mid - 1;
            }
            else{
                return nums[mid];
            }
        }
        
        return -1;
    }
};