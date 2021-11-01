// https://leetcode.com/problems/surrounded-regions/

// Medium

// What this problem wants to teach me?
// How to apply Boundary DFS / Boundary BFS 
// Instead to thinking when 'O' is flipped, we can think when we can't flip 'O', approach is useful here
// That is this prob. teaches the reverse engineering.

// Let's analyze when an 'O' cannot be flipped,
// if it has atleast one 'O' in it's adjacent, AND ultimately this chain of adjacent 'O's is connected to some 'O' which lies on boundary of board
        
//consider these two cases for clarity :
      /*
        O's won't be flipped          O's will be flipped
        [X O X X X]                   [X X X X X]     
        [X O O O X]                   [X O O O X]
        [X O X X X]                   [X O X X X] 
        [X X X X X]                   [X X X X X]
      
So we can conclude if a chain of adjacent O's is connected some O on boundary then they cannot be flipped*/

// Time = O(m*n), Space = O(m*n) - recursion depth

#include<bits/stdc++.h>
using namespace std;


// DFS Solution

class Solution {
public:
    void dfs(vector<vector<char>>& board, int row, int col, int m, int n){
        if(row<0 || row>=m || col<0 || col>=n || board[row][col]!='O'){
            return;
        }
        
        board[row][col] = '#';
        
        dfs(board, row-1, col, m, n);
        dfs(board, row+1, col, m, n);
        dfs(board, row, col-1, m, n);
        dfs(board, row, col+1, m, n);
    }
    
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if(m==0){
            return;
        }
        int n = board[0].size();
        
        // check for left and right column border
        for(int row = 0; row<m; ++row){
            
                if(board[row][0] == 'O'){
                    dfs(board, row, 0, m, n);
                }
                
                if(board[row][n-1]=='O'){
                    dfs(board, row, n-1, m, n);
                }
        }
        
        // check for top and bottom row border
        for(int col = 0; col<n; ++col){
            
                if(board[0][col] == 'O'){
                    dfs(board, 0, col, m, n);
                }
                
                if(board[m-1][col]=='O'){
                    dfs(board, m-1, col, m, n);
                }
        }
        
        // flipping
        for(int row = 0; row<m; ++row){
            for(int col = 0; col<n; ++col){
                if(board[row][col]=='O'){
                    board[row][col] = 'X';
                }
                
                if(board[row][col]=='#'){
                    board[row][col] = 'O';
                }
            }
        }
    }
};

// BFS Solution
