// https://leetcode.com/problems/removing-minimum-number-of-magic-beans/

// Medium

// Tags - Sorting, PrefixSum, Greedy

// What this problem wants to teach me?
// Variation of min no. of moves to make array equal

#include<bits/stdc++.h>
using namespace std;

// Sorting + PrefixSum-Variable is used + Greedy | Time - O(NLogN + N), Space - O(1)
class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        long long beansSum = 0;
        beansSum = accumulate(beans.begin(), beans.end(), beansSum);
    
        // Ans will be minimum for one of the case
        // when we make all the array elements to be equal to some array element
        
        // sort the array
        sort(begin(beans), end(beans));
        
        int n = beans.size();
        long long ans = LONG_MAX;
        
        for(int i=0; i<n; i++){
            long long curCost = beansSum - ((long long)(n-i)*(long long)beans[i]);  // pay attention on this line - replacement of prefix sum by a variable
            ans = min(ans,curCost);
        }
        
        return ans;
    }
};

// Sorting + PrefixSum-Array is Used + Greedy | Time - O(NLogN + N), Space - O(N)
class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        // sort the array
        sort(beans.begin(), beans.end());
        
        long long n = beans.size();
        vector<long long> prefixSum(n);
        prefixSum[0] = beans[0];
        for(long long i=1; i<n; i++){
            prefixSum[i] = prefixSum[i-1] + beans[i];
        }
        
        long long sum = 0;
        sum = accumulate(begin(beans), end(beans), sum);
        long long ans = LONG_MAX;
        for(long long i=0; i<n; i++){
            long long leftPartCost = prefixSum[i] - beans[i];   // prefixSum[i-1]
            long long rightPartCost = (prefixSum[n-1] - prefixSum[i]) - (n-i-1)*(long long)beans[i];
            long long curCost =  leftPartCost + rightPartCost;
            ans = min(ans, curCost);
        }
                                                            
        return ans;
    }
};