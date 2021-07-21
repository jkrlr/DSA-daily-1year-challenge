#include <bits/stdc++.h>
using namespace std;

void ratInMaze(int right, int bottom, vector<vector<char>> c, vector<int> &res, int n)
{
    // base case
    if (right == n and bottom == n)
    {
        return;
    }

    // recursive case
    if (right < 0 || right > n || bottom < 0 || bottom > n)
    {
        return;
    }

    if (c[right][bottom] == 'O')
    {
        res.push_back((n * right) + (bottom + 1));

        // right traversal
        if (right + 1 < n && c[right + 1][bottom] == 'O')
        {
            return ratInMaze(right + 1, bottom, c, res, n);
        }

        // bottom traversal
        if (bottom + 1 < n && c[right][bottom + 1] == 'O')
        {
            return ratInMaze(right, bottom + 1, c, res, n);
        }
    }
    return;
}

vector<int> findPath(int n, vector<vector<char>> c)
{
    vector<int> res;

    ratInMaze(0, 0, c, res, n);
    return res;
}