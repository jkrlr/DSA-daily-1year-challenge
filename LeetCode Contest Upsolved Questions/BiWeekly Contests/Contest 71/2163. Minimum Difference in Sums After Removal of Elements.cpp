// https://leetcode.com/problems/minimum-difference-in-sums-after-removal-of-elements/

// Hard

// Tags - Prefix Sum, Suffix Sum, Priority Queue, Greedy-Combinations, Array

// What this problem wants to teach me?
// what is subsequence
// How to simultaneously use min_heap, max_heap and prefix sum 
// Variation of Kth largest element in array + Combinations
// Reverse engineering approach

#include<bits/stdc++.h>
using namespace std;

// Prefix Sum, Suffix Sum + Priority Queue - min_heap, max_heap + Greedy-Combinations| Time - O(2*(2*n*Logn) + 2*n), Space - O(3*n + 3*n + n + n)
class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        // sumFirst - sumSecond -> to be minimized
        // sumFirst => should be minimum
        // sumSecond => should be maximum
        
        int N = nums.size();
        int n = N/3;
        
        vector<long long> prefix(N,0);  // stores the sum of n minimum elements from left
        priority_queue<long long, vector<long long>> max_heap;
        long long left = 0;
        
        for(int i=0; i<2*n; i++){
            left += (long long)nums[i];
            max_heap.push(nums[i]);
            
            if(max_heap.size()>n){
                left -= max_heap.top();
                max_heap.pop();
            }
            
            if(max_heap.size() == n)
                prefix[i] = left;
        }
        
        vector<long long> suffix(N,0); // stores the sum of n maximum elements from right
        priority_queue<long long, vector<long long>, greater<long long>> min_heap;
        long long right = 0;
        for(int i=N-1; i>=n; i--){
            right += (long long)nums[i];
            min_heap.push(nums[i]);
            
            if(min_heap.size() > n){
                right -= min_heap.top();
                min_heap.pop();
            }
            
            if(min_heap.size()==n){
                suffix[i] = right;
            }
        }
        
        long long result = LLONG_MAX;
        for(int i=n-1; i<N-n; i++){
            result = min(result, prefix[i] - suffix[i+1]);
        }
        
        return result;
    }
};