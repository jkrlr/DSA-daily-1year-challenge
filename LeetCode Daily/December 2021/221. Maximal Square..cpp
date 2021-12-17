// https://leetcode.com/problems/minimum-height-trees/

// Medium

// Tags - Matrix, Dynamic Programming

// What this problem wants to teach me?

#include<bits/stdc++.h>
using namespace std;

// BottomUp DP | Time = O(m*n) , Space = O(m*n) 
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        if(rows==0) return 0;
        int cols = matrix[0].size();
        
        vector<vector<int>> dp(rows+1, vector<int>(cols+1,0));
        int largest = 0;
        
        for(int row = 1; row<=rows; row++){
            for(int col = 1; col<=cols; col++){
                if(matrix[row-1][col-1]=='1'){
                    dp[row][col] = 1 + min({dp[row-1][col], dp[row][col-1], dp[row-1][col-1]});
                    largest = max(largest, dp[row][col]);
                }
            }
        }
        
        return largest*largest;
    }
};

// Space Optimized BottomUp DP | Time = O(m*n) , Space = O(2n) 
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        if(rows==0) return 0;
        int cols = matrix[0].size();
        
        vector<vector<int>> dp(2, vector<int>(cols+1,0));
        int largest = 0;
        
        for(int row = 1; row<=rows; row++){
            for(int col = 1; col<=cols; col++){
                if(matrix[row-1][col-1]=='1'){
                    dp[1][col] = 1 + min({dp[0][col], dp[1][col-1], dp[0][col-1]});
                    largest = max(largest, dp[1][col]);
                }
                else
                    dp[1][col] = 0;         // Pay Attention here, don't forget to put '0' for matrix block containing '0'
            }
            
            // prepare dp for next round
            for(int col = 1; col<=cols; col++)
                dp[0][col] = dp[1][col];
        }
        
        return largest*largest;
    }
};

// Brute-Force | Time = O(m*n*m*n) , Space = O(1) 
class Solution {
private:
    bool allOnes(vector<vector<char>>& matrix, int x, int y, int finalX, int finalY){
        for(int row = x; row<=finalX; row++){
            for(int col = y; col<=finalY; col++){
                if(matrix[row][col]=='0')
                    return false;
            }
        }
        
        return true;
    }
private:
    int findSquareArea(vector<vector<char>>& matrix, int x, int y){
        int ans = 1;
        int dx = 1, dy = 1;
        while(x+dx < matrix.size() && y+dy < matrix[0].size()){
            if(allOnes(matrix,x,y,x+dx, y+dy)){
                ans = (dx+1)*(dy+1);
                dx++, dy++;
            }
            else
                break;
        }
        
        return ans;
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        int maxArea = 0;
        for(int r = 0; r<row; r++){
            for(int c=0; c<col; c++){
                if(matrix[r][c]=='1'){
                    int area = findSquareArea(matrix,r,c);
                    maxArea = max(maxArea, area);
                }
            }
        }
        
        return maxArea;
    }
};