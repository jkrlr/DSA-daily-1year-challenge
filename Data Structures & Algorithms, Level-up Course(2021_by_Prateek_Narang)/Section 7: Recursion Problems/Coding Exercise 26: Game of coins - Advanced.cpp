/* Coding Exercise 26: Game of coins -
Advanced */

#include <bits/stdc++.h>
using namespace std;

int getSum(vector<int> Sum, int left, int right)
{
    if (left == 0)
        return Sum[right];
    else
        return Sum[right] - Sum[left - 1];
}
int solve(vector<int> v, int left, int right, int k, vector<int> Sum, int turn)
{

    // Base case
    if (right == (left + k))
    {
        if (turn % 2 == 0)
        {
            return getSum(Sum, left, right);
        }
        else
            return 0;
    }

    // Recursive case
    if (turn % 2 == 0)
    {
        int subProblemLeft = getSum(Sum, left, left + k) + solve(v, left + k + 1, right, k, Sum, turn + 1);
        int subProblemRight = getSum(Sum, right - k + 1, right) + solve(v, left, right - k, k, Sum, turn + 1);

        return min(subProblemLeft, subProblemRight);
    }
    else
    {
        int subProblemLeft = 0 + solve(v, left + k + 1, right, k, Sum, turn + 1);
        int subProblemRight = 0 + solve(v, left, right - k, k, Sum, turn + 1);

        return min(subProblemLeft, subProblemRight);
    }
}

int MaxValue(int n, vector<int> v, int k)
{
    int left = 0;
    int right = n - 1;
    int turn = 0;

    vector<int> Sum(n);
    Sum[0] = v[0];
    for (int i = 1; i < n; i++)
    {
        Sum[i] += v[i] + Sum[i - 1];
    }
    return solve(v, left, right, k, Sum, turn);
}