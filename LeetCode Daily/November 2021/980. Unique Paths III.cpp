// https://leetcode.com/problems/unique-paths-iii/

// Hard

// Tags - Recursion, Backtracking, DFS

// What this problem wants to teach me?
// How to use DFS(Recursion) along with Backtracking in 2D-grid
// How by looking the constraints and by calculating the Order of Time in power of 10 using given constraints,
// we can confirm that Brute-Force will work and not cause stack Overflow for recursion as well as not give TLE

// Time = O(3^(m*n)) - not 4 bcoz we've to find the unique,So we can't go back to that cell from we're coming.
// Space = O(m*n)-depth of recursion

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pathCount = 0;
    int m,n;
    int emptyCellsCount = 1;
    
    void dfs(vector<vector<int>>& grid, int row, int col, int currEmptyCellsCount){
        // base case
        if(row < 0 || row>=m || col<0 || col>=n || grid[row][col]==-1){
            return;
        }
        
        if(grid[row][col]==2){
            if(currEmptyCellsCount == emptyCellsCount){
                ++pathCount;
            }
            return;
        }
        
        
        // recursive case;
        int temp = grid[row][col];
        grid[row][col]= -1;
        
        dfs(grid,row-1,col,currEmptyCellsCount+1);
        dfs(grid,row+1,col,currEmptyCellsCount+1);
        dfs(grid,row,col-1,currEmptyCellsCount+1);
        dfs(grid,row,col+1,currEmptyCellsCount+1);
        
        grid[row][col]= temp;   // backtracking
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        int srcRow = -1, srcCol = -1;
        
        // 1. find the src Cell and count total empty cells
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==0){
                    emptyCellsCount++;
                }
                
                if(grid[i][j]==1){
                    srcRow = i;
                    srcCol = j;
                }
            }
        }
        
        
        if(srcRow==-1 || srcCol==-1){
            return 0;
        }
        
        int currEmptyCount = 0;
        
        // 2. find the valid paths
        dfs(grid,srcRow,srcCol,currEmptyCount);

        return pathCount;
    }
};