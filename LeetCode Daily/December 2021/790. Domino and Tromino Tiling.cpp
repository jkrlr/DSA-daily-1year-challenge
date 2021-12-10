// https://leetcode.com/problems/domino-and-tromino-tiling/

// Medium

// Tags - Dynamic Programming, Matrix Exponentiation

// What this problem wants to teach me?
/* DP can be used in exploring the ways or finding the paths problems containing the overlapping subproblems
    even the optimal substructure isn't present => But we can use DP for only overlapping subproblems to optimize the calculations */
/* In Tiling Problems, when you start drawing the structures from the base case
    Then, pattern will be visible by dry running on few examples */
/* Try to think for making the F(N) from the previous states(conditions) that are given in questions*/
/* For drawing or understanding purpose, we can also use shorthand drawing notations for faster calculations
    e.g. we can represent the tile patterns by using the lines insted of using the block */
/* When the forming pattern is dependent upon all the previous till begining for any state i
    Then, Try to make pattern by doing substractions 
    e.g. dp[i] = dp[i-1] + dp[i-2] + 2*dp[i-3] + 2*dp[i-4] + .... + 2*dp[0]
    Then, put i = i-1 or i-2 or i-3 , depending upon the conditions and which will cancel out maximum terms
    Let put i=i-1 for our case
    Now, dp[i-1] =  dp[i-2] + dp[i-3] + 2*dp[i-4] + 2*dp[i-5] + .... + 2*dp[0]
    => dp[i] - dp[i-1] = dp[i-1] + dp[i-3]
    => dp[i] = 2*dp[i-1] + dp[i-3]
    See it , How Time complexity is decreased from O(n^2) to O(n) */

#include <bits/stdc++.h>
using namespace std;

// BottomUp Time Optimized Dp | Time = O(n), Space = O(n)
class Solution {
public:
    int numTilings(int N) {
        if(N<=2)
            return N;
        
        vector<long long>dp(N+1,1);
        dp[2] = 2;
        long long mod = 1000000007;
        
        for(long long n=3; n<=N; n++){
            dp[n] = (2 * dp[n - 1] % mod + dp[n - 3] % mod) % mod;
        }

        return dp[N];
    }
};

// BottomUp Time and Space Optimized Dp | Time = O(n), Space = O(1)
class Solution {
public:
    int numTilings(int N) {
        if(N<=2)
            return N;
        
        long long prev = 2, prevOfPrev = 1, prevOfPrevOfPrev = 1;
        long long mod = 1000000007;
        
        for(long long n=3; n<=N; n++){
            long long current = (2*prev % mod + prevOfPrevOfPrev % mod) % mod;
            
            prevOfPrevOfPrev = prevOfPrev;
            prevOfPrev = prev;
            prev = current;
        }
        
        return prev;
    }
};