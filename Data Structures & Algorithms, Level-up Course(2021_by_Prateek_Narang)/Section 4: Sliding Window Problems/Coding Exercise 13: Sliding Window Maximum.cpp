// https://leetcode.com/problems/sliding-window-maximum/
// Time = O(N), Space = O(k)
#include <bits/stdc++.h>
using namespace std;

vector<int> maxInWindow(vector<int> ar, int k)
{
    // Algorithm
    deque<int> Q(k);

    //1. Process only the first k elements
    int i = 0;
    for (; i < k; i++)
    {
        // Logic here …

        while (!Q.empty() && ar[i] >= ar[Q.back()])
        {
            Q.pop_back();
        }
        // process the current element
        Q.push_back(i);
    }
    vector<int> res;
    res.push_back(ar[Q.front()]);

    //2. Process the remaining elements of array
    for (; i < ar.size(); i++)
    {
        // Remove element from Left (contraction when an index lies outside the current window)
        while (!Q.empty() && Q.front() <= i - k)
        {
            Q.pop_front();
        }

        // Start contracting the window from Right
        while (!Q.empty() && ar[i] >= ar[Q.back()])
        {
            Q.pop_back();
        }

        // always
        Q.push_back(i);

        res.push_back(ar[Q.front()]);
    }

    return res;
}