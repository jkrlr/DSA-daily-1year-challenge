#include <bits/stdc++.h>
using namespace std;

bool isValid(int row, int col, vector<vector<int>> v, vector<vector<bool>> visited, int m, int n)
{

    if (row >= 0 && row < m && col >= 0 && col < n && visited[row][col] == false && v[row][col] == 1)
    {
        return true;
    }

    return false;
}

void longestPossiblePath(int row, int col, vector<vector<int>> v, vector<vector<bool>> visited, int m, int n, int &maxPathLen, int currPathLen)
{
    // base case
    if (row == m - 1 and col == n - 1)
    {
        maxPathLen = max(maxPathLen, currPathLen);
        return;
    }

    // recursive case
    visited[row][col] = true;

    // Down
    if (isValid(row + 1, col, v, visited, m, n))
        longestPossiblePath(row + 1, col, v, visited, m, n, maxPathLen, currPathLen + 1);

    // Left
    if (isValid(row, col - 1, v, visited, m, n))
        longestPossiblePath(row, col - 1, v, visited, m, n, maxPathLen, currPathLen + 1);

    // Right
    if (isValid(row, col + 1, v, visited, m, n))
        longestPossiblePath(row, col + 1, v, visited, m, n, maxPathLen, currPathLen + 1);

    // Up
    if (isValid(row - 1, col, v, visited, m, n))
        longestPossiblePath(row - 1, col, v, visited, m, n, maxPathLen, currPathLen + 1);

    // backtrack
    visited[row][col] = false;
}

int findLongestPath(int m, int n, vector<vector<int>> v)
{
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    int maxPathLen = INT_MIN;
    int currPathLen = 0;
    longestPossiblePath(0, 0, v, visited, m, n, maxPathLen, currPathLen);

    return maxPathLen;
}
