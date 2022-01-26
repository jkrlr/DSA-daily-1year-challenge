// https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/

// Easy

// Tags - Array, Sorting, Greedy

// What this problem wants to teach me?
// For easy questions don't think the graph/dp approach, think the basic approach
// If approach is not coming into mind then you can try one approach that
// try to solve the problem for very samll and simpler case and then try to generalize the process

#include<bits/stdc++.h>
using namespace std;

// Sorting + Greedy | Time - O(NLogN + N), Space - O(LogN) - for sorting
class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int result = 0, n = cost.size();
        sort(cost.begin(), cost.end());
        
        for(int i=0; i<n; i++){
            if(i%3!=n%3)         // i%3 == n%3 for every third element from right
                result += cost[i];
        }
        
        return result;
    }
};