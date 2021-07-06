// Time =O(N) and Space=O(N)

#include <bits/stdc++.h>
using namespace std;

int cntSubarrays(vector<int> arr, int k)
{
    unordered_map<int, int> PrevSum; // unordered_map<sum,cnt_of_subarray_having_sum=sum>
    int CurrSum = 0;
    int cnt = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        CurrSum += arr[i];

        if (CurrSum == k)
            cnt++;

        if (PrevSum.find(CurrSum - k) != PrevSum.end())
            cnt += PrevSum[CurrSum - k];

        PrevSum[CurrSum]++;
    }

    return cnt;
}