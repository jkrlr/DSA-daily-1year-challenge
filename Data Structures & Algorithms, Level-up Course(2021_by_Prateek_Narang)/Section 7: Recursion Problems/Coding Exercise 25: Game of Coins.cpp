#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> v, int left, int right, int turn)
{

    // Base case
    if (left == right)
    {
        if (turn % 2 == 0)
            return v[left];
        else
            return 0;
    }

    // Recursive case
    if (turn % 2 == 0)
    {
        return max(v[left] + solve(v, left + 1, right, turn + 1), v[right] + solve(v, left, right - 1, turn + 1));
    }
    else
    {
        return min(0 + solve(v, left + 1, right, turn + 1), 0 + solve(v, left, right - 1, turn + 1));
    }
}

int MaxValue(int n, vector<int> v)
{
    int left = 0;
    int right = n - 1;
    int turn = 0;

    return solve(v, left, right, turn);
}