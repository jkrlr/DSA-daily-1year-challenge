// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

// Medium

// Tags - Two Pointer

// What this problem wants to teach me?
// How to use two pointer algorithm to solve the problem O(N) and by doing the inplace changes(i.e. in O(1) Space Complexity)

#include<bits/stdc++.h>
using namespace std;

// Two Pointer | Time = O(N), Space = O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int lo = 0, hi = 1;
        int cnt = 1;
        int result = nums.size();
        
        while(hi<nums.size()){
            if(cnt>=2 && nums[lo]==nums[hi]){
                    result--;
            }
            else{
                if(nums[lo]==nums[hi])
                    cnt++;
                else
                    cnt = 1;
                
                nums[++lo] = nums[hi];
            }   
            hi++;
        }
        
        return result;
    }
};

// Two Pointer - Short Solution | Time = O(N), Space = O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=2)
                return nums.size();
        
        int index = 2;
        for(int i=2; i<nums.size(); i++){
            if(nums[index-2] != nums[i])
                nums[index++] = nums[i];
        }
        
        return index;
    }
};