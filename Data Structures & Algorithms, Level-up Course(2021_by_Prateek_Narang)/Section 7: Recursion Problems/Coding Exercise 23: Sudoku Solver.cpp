// https://leetcode.com/problems/sudoku-solver/submissions/
// Time = O(n^(n*n)) = O(9^81), Space = O(n*n) = O(81)
#include <bits/stdc++.h>
using namespace std;

bool IsSafe(vector<vector<int>> &mat, int row, int col, int n, int num)
{
    // check for row and column
    for (int k = 0; k < n; k++)
    {
        if (mat[k][col] == num || mat[row][k] == num)
        {
            return false;
        }
    }

    // check for subgrid
    int sx = (row / 3) * 3;
    int sy = (col / 3) * 3;
    for (int x = sx; x < sx + 3; x++)
    {
        for (int y = sy; y < sy + 3; y++)
        {
            if (mat[x][y] == num)
            {
                return false;
            }
        }
    }

    return true;
}

// If you count the no. of ways, Then return type is int instead of bool
bool SolveSudoku(vector<vector<int>> &mat, int row, int col, int n)
{

    // Base Case
    if (row == n) // we found out the solution
    {
        // print the solution
        /*         for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        } */

        return true;
    }

    // Recursive Case
    if (col == n)
    {
        return SolveSudoku(mat, row + 1, 0, n);
    }

    // skip the prefilled cell
    if (mat[row][col] != 0)
    {
        return SolveSudoku(mat, row, col + 1, n);
    }

    // cell to be filled
    // try out all possiblities
    for (int num = 1; num <= n; num++)
    {
        // check whether it is safe to place the number of not.
        if (IsSafe(mat, row, col, n, num))
        {
            mat[row][col] = num;
            bool solveSubproblem = SolveSudoku(mat, row, col + 1, n); // Assume that this can give the solution
            if (solveSubproblem == true)
            {
                return true;
            }
        }
    }

    // If no option works => backtracking
    mat[row][col] = 0;
    return false;
}

vector<vector<int>> solveSudoku(vector<vector<int>> input)
{
    int n = input.size();
    SolveSudoku(input, 0, 0, n);

    return input;
}

/* Time Complexity: 
            O(n ^ m) where n is the number of possibilities for each square 
            (i.e., 9 in classic Sudoku) and m is the number of spaces that are blank.

            The problem can be designed for a grid size of N*N where N is a perfect square. 
            For such an N, let M = N*N, the recurrence equation can be written as:

                T(M) = 9*T(M-1) + O(1)

                where T(N) is the running time of the solution for a problem size of N. 
                Solving this recurrence will yield, O(9^M). */

/* Space complexity: 
            it’s the recursion stack that is used as an auxiliary space which is N*N step deep. 
            Remember we need to fill in 81 cells in a 9*9 sudoku and at each level, only one cell is filled. 
            So, space complexity would be O(M). */