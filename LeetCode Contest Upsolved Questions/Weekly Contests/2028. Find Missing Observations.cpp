// https://leetcode.com/problems/find-missing-observations/

// Time = O(M+N), Space = O(1)
// Tags - Array, Math, Simulation

#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int rollsSum = accumulate(rolls.begin(), rolls.end(), 0); // O(m)
        int missingSum = mean * (m + n) - rollsSum;

        if(missingSum < n || missingSum > 6*n){
            return {};
        }

        int rem = missingSum % n;           // rem(max value is) = n - 1
        vector<int> ans(n, missingSum / n); // O(n)

        for (int i = 0; i < rem; i++){      // O(n-1)
            ans[i] += 1;
        }

        return ans;
    }
};