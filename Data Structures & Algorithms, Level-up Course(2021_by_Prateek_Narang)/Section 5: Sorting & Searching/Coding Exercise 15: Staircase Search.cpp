// Time = O(N) and Space = O(1) : gfg ques

#include <bits/stdc++.h>
using namespace std;

pair<int, int> search(int m, int n, vector<vector<int>> v, int k)
{
    int row = 0, col = n - 1; // Put ptr to last element of first row

    // Traverse the array until we found the element or
    // The pointer index goes out of bound
    while (row < m and col >= 0)
    {
        if (v[row][col] == k)
            return {row, col};
        else if (v[row][col] > k)
            col--;
        else
            row++;
    }

    return {-1, -1};
}

/* https://leetcode.com/problems/search-a-2d-matrix/    LeetCode Complexity = O(log(m*n))
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Time = O(log(mxn))
        int row = matrix.size();
        int col = matrix[0].size();
        
        int start = 0, end = (row*col)-1;
        
        while(start<=end){
            int  mid = start + (end-start)/2;
            
            // Get the index of mid corresponds to 2D-matrix
            int row_idx = mid/col;
            int col_idx = mid%col;
            
            if(matrix[row_idx][col_idx]==target)    // arr[mid] == key
                return true;
            else if(matrix[row_idx][col_idx]>target)
                    end = mid -1;
            else
                    start = mid + 1;
        }
        
        return false;
    }
};
*/