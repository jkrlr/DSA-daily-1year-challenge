// 416. Partition Equal Subset Sum
// https://leetcode.com/problems/partition-equal-subset-sum/

// Flow
// 1. Problem Statement
// 2. Subset Sum Function & How Similar
// 3. Odd/Even Signification
// 4. Code Variation (from Subset Sum Prob.)

class Solution
{
public:
    bool canPartition(vector<int> &ar)
    {
        int n = ar.size();
        long long int sum = 0;

        for (int i = 0; i < n; i++)
            sum += ar[i];

        if (sum % 2 == 1) // i.e. if sum is odd
            return false;

        else             // Now, from here problem is reduced to find Subset Sum
        {
            sum /= 2;
            int t[n + 1][sum + 1];

            for (int i = 0; i <= n; i++)
                for (int j = 0; j <= sum; j++)
                {
                    if (i == 0)
                        t[i][j] = false;
                    if (j == 0)
                        t[i][j] = true;
                }

            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= sum; j++)
                {
                    if (ar[i - 1] <= j)
                    {
                        t[i][j] = (t[i - 1][j - ar[i - 1]] || t[i - 1][j]);
                    }
                    else
                        t[i][j] = t[i - 1][j];
                }

            return t[n][sum];
        }
    }
};
