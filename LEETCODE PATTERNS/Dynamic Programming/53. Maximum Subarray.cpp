// https://leetcode.com/problems/maximum-subarray/

// Easy

// Tags - Dynamic Programming, Kadane's Algo Variation, Divide Conquer - Less Obvious

// What this problem wants to teach me?
// If the problem is like the problem you've solved already, and while thinking the half-remebring previous approch
// and question answer is not coming then try to think the problem like you haven't seen before approach and you can take
// the help of topic tags or any other hint and then solve with your fundamental approach -> boom! most probably you'll get the solution

#include <bits/stdc++.h>
using namespace std;

// Dynamic Programming, Kadane's Algo Variation | Time = O(N) , Space = O(1)
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int maxEndingHere = nums[0], maxSoFar = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            maxEndingHere = max(nums[i], maxEndingHere + nums[i]);

            maxSoFar = max(maxSoFar, maxEndingHere);
        }

        return maxSoFar;
    }
};

// Follow Up 
// Divide and Conquer Optimize using prfix and suffix array | Time = O(N) , Space = O(N)
class Solution {
private:
    vector<int> prefix, suffix;
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        prefix.resize(n), suffix.resize(n);
        
        prefix[0] = nums[0], suffix[n-1] = nums[n-1];
        for(int i=1; i<n; i++)
            prefix[i] = max(nums[i], nums[i]+prefix[i-1]);
        for(int i=n-2; i>=0; i--)
            suffix[i] = max(nums[i], nums[i] + suffix[i+1]);
        
        return solve(nums, 0, n-1);
    }
private:
    int solve(vector<int>& nums, int start, int end){
        if(start>end)
            return INT_MIN;
        if(start==end)
            return nums[start];
        
        int mid = start + (end-start)/2;
        int leftSubproblem = solve(nums, start, mid-1);
        int rightSubproblem = solve(nums,mid+1, end);
        
        return max({leftSubproblem, rightSubproblem, prefix[mid] + suffix[mid+1], prefix[mid], suffix[mid], nums[mid]});
    }
};