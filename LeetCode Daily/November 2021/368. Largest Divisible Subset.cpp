// https://leetcode.com/problems/largest-divisible-subset/

// Medium

// Tags - Dp, Soting, Math

// What this problem wants to teach me?
// If in a problem max/min is asked(i.e. optimal substructure) and 
// you think recursive solution surely give correct ans but the constraints of
// input not allowing the recursive solution (i.e. > 20) but the constraints allow such that dp table can be created
// that means if constraints are 10^6(only 1D dp possible) and if constraints are 10^3(means both 1D and 2D dp possible)
// Then, surely in that question dp will work if constraints will favour + contains (optimal substruture + overlapping subproblems)

// If constraints aren't in favour(10^5 or 10^6) of possible dp(1D or 2D whichever is appropriate according to varaible changes in fun call)
// Then, look is their any overlapping subproblem or not, If not
// Then, think the gready solution possible approaches
// This question now surely solved by greedy

#include<bits/stdc++.h>
using namespace std;

// DP-TopDown | Time = O(NLogN + N^2 + N),  Space = O(N)
class Solution {
public:
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        
        if(n==0){
            return {};
        }
        
        // 1. Sort the array
        sort(nums.begin(), nums.end());        
        
        // 2. Apply Dp to find max size of subset
        vector<int> dp(n,1);
        int max = 1;
        
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i]%nums[j]==0 && dp[i] < 1 + dp[j]){
                    dp[i] =  1 + dp[j];
                    
                    if(max < dp[i]){
                        max = dp[i];
                    }
                }
            }
        }
        
        // 3. find the subset
        vector<int> result;
        int prev = -1;
        
        for(int i = n-1; i>=0; i--){
            
            if(dp[i]==max && (prev==-1 || prev%nums[i]==0)){
                result.push_back(nums[i]);
                max -= 1;
                prev = nums[i];
            }

        }
        return result;
    }
};