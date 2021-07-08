// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

// Time Complexity : O(2N) = O(N) and Space = (1) using 2 pointer techique , greedy
// Time using Sorting = O(NLogN) and Space = O(1)

#include <bits/stdc++.h>
using namespace std;

pair<int, int> subarraySorting(vector<int> a)
{
    //Expected Optimal Complexity O(n) Time, O(1) Space
    //may be start with O(NLogN) and try to improve
    //complete this function

    int n = a.size();

    int lo = 0;
    while (lo < n - 1 and a[lo + 1] >= a[lo])
        lo++;

    // Sorted Array
    if (lo == n - 1)
        return {-1, -1};

    int hi = n - 1;
    while (hi > 0 and a[hi] >= a[hi - 1])
        hi--;

    int unsortedMax = INT_MIN;
    int unsortedMin = INT_MAX;

    for (int i = lo; i <= hi; i++)
    {
        if (a[i] > unsortedMax)
            unsortedMax = a[i];

        if (a[i] < unsortedMin)
            unsortedMin = a[i];
    }

    int start = 0;
    while (start < lo and a[start] <= unsortedMin)
        start++;
    lo = start;

    int end = n - 1;
    while (end > hi and unsortedMax <= a[end])
        end--;
    hi = end;

    return {lo, hi};
}