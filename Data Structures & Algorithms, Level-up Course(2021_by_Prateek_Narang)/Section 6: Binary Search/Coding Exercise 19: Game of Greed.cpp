// Time = O(NLog(Max_Sum)), Space = O(1)

#include <bits/stdc++.h>
using namespace std;

bool isSumPossible(vector<int> arr, int Sum, int k)
{
    int partitions = 0;
    int curr_partition_sum = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        curr_partition_sum += arr[i];

        if (curr_partition_sum >= Sum)
        {
            partitions++;
            curr_partition_sum = 0;
        }

        if (partitions == k)
        {
            return true;
        }
    }
    return false;
}

int getCoins(vector<int> arr, int k)
{
    //return the max coins that you can win!

    /*  Don't do sorting here because here ordering of arr element matters.
    We're applying Binary search on sum search space
    sort(arr.begin(), arr.end());
 */
    // Binary Search
    int Sum = 0;
    for (int num : arr)
    {
        Sum += num;
    }

    int start = 0; // start = min_sum = 0
    int end = Sum; //  end = max_sum = sum[arr[i] : i=0->n-1]
    int ans = -1;

    while (start <= end) // O(LogN)
    {
        int mid = start + (end - start) / 2; // mid = curr_sum

        if (isSumPossible(arr, mid, k)) // O(N) time
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}