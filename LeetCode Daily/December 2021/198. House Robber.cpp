
// Medium

// Tags - Dynamic Programming

// What this problem wants to teach me?
// For TopDown Dp -> The ith index will contain the answer for i to n-1 for array
// For BottomUp Dp -> The ith index will contain the answer for 0 to i for array
// So, convert the TopDown to BottomUp according to the above 2 points keeping in mind
// In Some cases, we can optimize the space of BottomUp Dp from O(n^2) to O(n) or from O(n) to O(1)
// By simply looking the dependency of current row on previous rows(in 2D-Dp)/ dependency of current item on previous items(in 1D-Dp)

#include<bits/stdc++.h>
using namespace std;

// BottomUp Dp | Time = O(n), Space = O(n)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,0);
        dp[1] = nums[0];
        
        for(int i=2; i<=n; i++){
            dp[i] = max(dp[i-1], nums[i-1] + dp[i-2]);
        }
        
        return dp[n];
    }
};

// BottomUp Space-Optimized Dp | Time = O(n), Space = O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        int prevOfPrevAns = 0, prevAns = nums[0]; 
        
        for(int i=1; i<n; i++){
            int currAns = max(prevAns, nums[i] + prevOfPrevAns);
            
            prevOfPrevAns = prevAns;
            prevAns = currAns;
        }
        
        return prevAns;
    }
};