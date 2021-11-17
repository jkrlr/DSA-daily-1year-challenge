// https://leetcode.com/problems/unique-paths/

// Medium

// Tags - Dp, Recursion(DFS), Math-Permutation and Combination(Combinatorics)

// What this problem wants to teach me?
// How we can think that a question can be solved by DP or not by looking Recurison + constraints + overlapping subproblems
// How we can think the BottomUp using Top-Down
// How we can optimize the BottomUp by simplily looking the depenedency of next iteration on previous iterations
// How a problem can be solved using Combinatorics Math 

#include<bits/stdc++.h>
using namespace std;

// DP-TopDown | Time - O(m*n), Space - O(m*n + (m+n))
class Solution {
public:
    int dfs(int m, int n, int row, int col, vector<vector<int>>&dp){
        // base case
        if(row == m-1 && col == n-1){
            return 1;
        }
        
        if(row<0 || row>=m || col<0 || col>=n){
            return 0;
        }
        
        // check if state is precomputed or not
        if(dp[row][col]!=-1){
            return dp[row][col];
        }
        
        // recursive case
        
        int ways = 0;
        ways += dfs(m,n,row+1,col,dp);
        ways += dfs(m,n,row, col+1,dp);
        
        
        return dp[row][col] = ways;
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n,-1));
        
        return dfs(m,n,0,0,dp);
    }
};

// DP-BottomUP | Time - O(m*n), Space - O(m*n)
// We can observe that the result for current row is only depends upon current row and previous row

class Solution {
public:   
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n,1));
        
        for(int row = 1; row<m; row++){
            for(int col=1; col<n; col++){
                dp[row][col] = dp[row-1][col] + dp[row][col-1];
            }
        }
        
        return dp[m-1][n-1];
    }
};

// DP-BottomUP-Optimized | Time - O(m*n), Space - O(n)
class Solution {
public:   
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(2, vector<int>(n,1));
        
        for(int row = 1; row<m; row++){
            for(int col=1; col<n; col++){
                dp[1][col] = dp[0][col] + dp[1][col-1];
            }
            
            // swap - so that result can be used for next iterations
            for(int col = 1; col<n; col++){
                dp[0][col] = dp[1][col];
            }
        }
        
        return dp[1][n-1];
    }
};

// Maths- combinations(P&C) | Time - O(min(m,n)), Space - O(1)
// This is a combinatorial problem and can be solved without DP. 
// For mxn grid, robot has to move exactly m-1 steps down and n-1 steps right and these can be done in any order.
class Solution {
public:
    long long nCr(int N, int R){
        long long res = 1;
        
        for(int num = R+1, den = 1; num <= N; num++, den++){
            res *= num;
            res /= den;
        }
        
        return res;
    }
    
    int uniquePaths(int m, int n) {
        if(n==1 || m==1){
            return 1;
        }
        m = m-1;
        n = n-1;
        
        int N = m+n, R = max(m,n);
        long long ans = nCr(N, R);
        
        return ans;
    }
};
