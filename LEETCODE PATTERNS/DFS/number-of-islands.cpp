// https://leetcode.com/problems/number-of-islands/

// Medium

// What this problem wants to teach me?
// How to apply DFS/BFS on 2D-grid by treating it like as a graph

// Time = O(m*n), Space = O(m*n)-depth or recursion in dfs / size of queue in BFS which is at max - O(max(m,n))

#include<bits/stdc++.h>
using namespace std;

int dx[] = {0,0,-1,1};  // left right top bottom
int dy[] = {-1,1,0,0};  // left right top bottom
class Solution {
public:
    bool isValid(vector<vector<char>>& grid, int row, int col, int rows, int columns){
        if(row>=0 && row<rows && col>=0 && col<columns && grid[row][col]=='1'){
            return true;
        }
        return false;
    }
    
    void dfs(vector<vector<char>>& grid, int row, int col, int rows, int columns){
        // visit the current box
        grid[row][col] = '*';
        
       // visit all the neigbhours of current box 
        for(int i=0; i<4; ++i){
                int newRow = row + dx[i];
                int newCol = col + dy[i];
            
                if(isValid(grid,newRow, newCol, rows,columns)){
                    dfs(grid,newRow, newCol, rows, columns);
                }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        
        int islands = 0;
        
        for(int row = 0; row<rows; ++row){
            for(int col = 0; col<columns; ++col){
                if(grid[row][col]=='1'){
                    ++islands;
                    dfs(grid,row,col,rows,columns);
                }
            }
        }
        
        return islands;
    }
};