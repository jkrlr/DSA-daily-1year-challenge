#include <iostream>
#include <vector>
#include <climits>
using namespace std;

//Recursive Time = O(2^n), Space = O(n)
int getMinCost(vector<int> &stones, int idx)
{
    // base case
    if (idx == stones.size() - 1)
    {
        return 0;
    }

    // recursive case
    int steps = INT_MAX;
    for (int i = idx + 1; i <= idx + 2 && i < stones.size(); i++)
    {
        int subprob = abs(stones[idx] - stones[i]) + getMinCost(stones, i);
        steps = min(steps, subprob);
    }
    return steps;
}

//Top-Down Time = O(n), Space = O(n)
int getMinCostTD(vector<int> &stones, vector<int> &dp, int idx)
{
    // base case
    if (idx == stones.size() - 1)
    {
        return 0;
    }

    if (dp[idx] != 0)
    {
        return dp[idx];
    }

    int steps = INT_MAX;
    for (int i = idx + 1; i <= idx + 2 && i < stones.size(); i++)
    {
        int subprob = abs(stones[idx] - stones[i]) + getMinCost(stones, i);
        steps = min(steps, subprob);
    }
    return dp[idx] = steps;
}

//Bottom-Up Time = O(n), Space = O(n)
int getMinCostBU(vector<int> &stones)
{
    int n = stones.size();
    vector<int> dp(n);
    // base case
    dp[0] = 0;
    dp[1] = abs(stones[0] - stones[1]);

    for (int i = 2; i < n; i++)
    {
        int op1 = abs(stones[i] - stones[i - 1]) + dp[i - 1];
        int op2 = abs(stones[i] - stones[i - 2]) + dp[i - 2];
        dp[i] = min(op1, op2);
    }
    return dp[n - 1];
}

int main()
{
    int n;
    cin >> n;
    vector<int> stones(n);

    for (int i = 0; i < n; i++)
    {
        cin >> stones[i];
    }
    int idx = 0;

    cout << getMinCost(stones, idx) << endl;
    cout << getMinCostBU(stones) << endl;

    vector<int> dp(n, 0);
    cout << getMinCostTD(stones, dp, idx) << endl;
}
