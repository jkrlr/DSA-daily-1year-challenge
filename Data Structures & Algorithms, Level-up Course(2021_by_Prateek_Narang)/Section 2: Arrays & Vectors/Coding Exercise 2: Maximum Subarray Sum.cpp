// https://leetcode.com/problems/maximum-subarray/

// Solved using Kaden's Algorithm
// Time=O(n), Space=O(1)

int maxSubarraySum(vector<int> ar)
{
    int ans = 0, curr_max = 0;

    for (int i = 0; i < ar.size(); i++)
    {
        curr_max += ar[i];

        if (curr_max > ans)
            ans = curr_max;
        if (curr_max < 0)
            curr_max = 0;
    }
    return ans;
}