// https://leetcode.com/problems/smallest-integer-divisible-by-k/

// Medium

// Tags - Math, unordered_set


#include <bits/stdc++.h>
using namespace std;

/* Complexity Analysis
    Time Complexity : O(K) since we at most run the loop O(K) times.
    Space Complexity : O(1) since we only use three ints: K, remainder, and length_N. */

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int remainder = 0;
        for (int length_N = 1; length_N <= k; length_N++) {
            remainder = (remainder * 10 + 1) % k;
            if (remainder == 0) {
                return length_N;
            }
        }
        return -1;
    }
};