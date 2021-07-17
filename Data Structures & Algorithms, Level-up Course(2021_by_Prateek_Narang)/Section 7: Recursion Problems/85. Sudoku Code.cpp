#include <iostream>
using namespace std;

bool IsSafe(int mat[][9], int row, int col, int n, int num)
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
bool SolveSudoku(int mat[][9], int row, int col, int n)
{

    // Base Case
    if (row == n) // we found out the solution
    {
        // print the solution
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }

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

int main()
{
    int n = 9;
    int mat[9][9] =
        {{5, 3, 0, 0, 7, 0, 0, 0, 0},
         {6, 0, 0, 1, 9, 5, 0, 0, 0},
         {0, 9, 8, 0, 0, 0, 0, 6, 0},
         {8, 0, 0, 0, 6, 0, 0, 0, 3},
         {4, 0, 0, 8, 0, 3, 0, 0, 1},
         {7, 0, 0, 0, 2, 0, 0, 0, 6},
         {0, 6, 0, 0, 0, 0, 2, 8, 0},
         {0, 0, 0, 4, 1, 9, 0, 0, 5},
         {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    if (!SolveSudoku(mat, 0, 0, n))
    {
        cout << "No solution exists";
    }
}

/* You don't need to dive in how this recursion working.
    If you have an idea and you can assume this can work.
    Then it will be easy to you to write code. 
    
   While writing code you don't need to think how this backtracking works
   If you are beginner in solving these type of problems.
   
   Once you know, you have written the code.
   You can easily verify, how this code is working and why this is working.

    For beginners, try to break the problem in simpler cases =>
    Write the code => Then try to think what is you code is doing, why it is working?

*** Do it for one cell and the rest is recursion will do it for you.
    This is the point you keep in mind, How I handle it for one cell?
*/