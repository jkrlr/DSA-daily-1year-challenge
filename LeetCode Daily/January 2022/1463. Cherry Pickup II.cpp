// https://leetcode.com/problems/cherry-pickup-ii/

// Hard

// Tags - Dynamic Programming, Array, Matrix

// What this problems wants to teach me?
// How to apply 3D-dp to solve a problem
// Max/Min - one thought should be dp
// Overlapping Subproblems => dp

#include<bits/stdc++.h>
using namespace std;

// Top-Down Dp | Time = O(M*N*N), Space = O(M*N*N)
class Solution {
private:
    int dfs(vector<vector<int>>& grid, vector<vector<vector<int>>>& dp, int row, int col1, int col2){
        if (col1 < 0 || col1 >= grid[0].size() || col2 < 0 || col2 >= grid[0].size()) {
            return 0;
        }
        
        // check cache
        if (dp[row][col1][col2] != -1) {
            return dp[row][col1][col2];
        }
        
         // current cell
        int result = 0;
        result += grid[row][col1];
        if (col1 != col2) {
            result += grid[row][col2];
        }
        
        // transition
        if (row != grid.size() - 1) {
            int mx = 0;
            for (int newCol1 = col1 - 1; newCol1 <= col1 + 1; newCol1++) {
                for (int newCol2 = col2 - 1; newCol2 <= col2 + 1; newCol2++) {
                    mx = max(mx, dfs(grid, dp, row + 1, newCol1, newCol2));
                }
            }
            result += mx;
        }
        
        dp[row][col1][col2] = result;
        return result;    
    }
public:
    int cherryPickup(vector<vector<int>> grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // initial all elements to -1 to mark unseen
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n,-1)));
        
        return dfs(grid, dp, 0, 0, n - 1);
    }
};

// Bottom-Up Dp | Time = O(M*N*N), Space = O(M*N*N)
// If we use state compression, Then Space = O(N*N)
class Solution {
public:
    int cherryPickup(vector<vector<int>> grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // initial all elements to -1 to mark unseen
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n,-1)));

        for (int row = m - 1; row >= 0; row--) {
            for (int col1 = 0; col1 < n; col1++) {
                for (int col2 = 0; col2 < n; col2++) {
                    int result = 0;
                    
                    // current cell
                    result += grid[row][col1];
                    if (col1 != col2) {
                        result += grid[row][col2];
                    }
                    
                    // transition
                    if (row != m - 1) {
                        int mx = 0;
                        for (int newCol1 = col1 - 1; newCol1 <= col1 + 1; newCol1++) {
                            for (int newCol2 = col2 - 1; newCol2 <= col2 + 1; newCol2++) {
                                if (newCol1 >= 0 && newCol1 < n && newCol2 >= 0 && newCol2 < n) {
                                    mx = max(mx, dp[row + 1][newCol1][newCol2]);
                                }
                            }
                        }
                        result += mx;
                    }
                    dp[row][col1][col2] = result;
                }
            }
        }
        return dp[0][0][n - 1];
    }
};