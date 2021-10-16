// https://leetcode.com/problems/minimum-size-subarray-sum/

// Time = O(N), Space = O(1)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
		int right = 0;

		int minLen = INT_MAX;
		int currentSum = 0;

		while(right < nums.size()){
			currentSum += nums[right];
			
			while(left <= right && currentSum >= target){   // Compress the window
				int  currentLen = right - left + 1;
				minLen = min(minLen, currentLen);
				currentSum -= nums[left];
				left++;
			}
			
			right++;    // Exapand the window
		}
 
		return minLen==INT_MAX? 0 : minLen;
    }
};
