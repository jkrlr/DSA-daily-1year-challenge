// https://leetcode.com/problems/sort-colors/

// Time = O(N), Space = O(1) using DNF Algorithm in single pass
// Using counting sort : Time = O(2N), Space = O(1) in two passes
// using in built library function : Time = O(NLogN), Space = O(1)

#include <bits/stdc++.h>
using namespace std;

vector<int> sortBalls(vector<int> balls)
{
    //sort the balls in place in a single pass (O(N) time, O(1) space)

    int lo = 0;
    int mid = 0;
    int hi = balls.size() - 1;

    while (mid <= hi)
    {
        if (balls[mid] == 0)
        {
            swap(balls[mid], balls[lo]);
            mid++;
            lo++;
        }
        else if (balls[mid] == 1)
        {
            mid++;
        }
        else
        { // balls[mid] == 2
            swap(balls[mid], balls[hi]);
            hi--;
        }
    }

    return balls;
}