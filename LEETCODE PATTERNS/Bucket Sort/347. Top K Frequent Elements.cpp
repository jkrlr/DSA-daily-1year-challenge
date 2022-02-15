// https://leetcode.com/problems/top-k-frequent-elements/

// Medium

// Tags - Bucket Sort, Heap, QuickSelect

// What this problem wants to teach me?
/* When the input integer range is of order greater than equal to 10^9 and 
    in the question number to frequency counting is required, Then...
    instead of mapping number to frequency we can map all the nums or any data structure having same freq to that particular frequency
    means freq to nums or any data types or any data structure types 
 This algo is called the bucket counting or bucket sort */

/* If we want to map a particular set of numbers to particular state in case of overlappin subproblems(dp),
    Then, instead of storing like vector<pair<int, vector<int>>>dp we can use bitmasking to create dp like
    vector<pair<int, int>>dp or unordered_map<int, int>> dp */

#include<bits/stdc++.h>
using namespace std;

// Bucket Sort | Time = O(N), Space = O(N)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> freqToNums(n+1);
        
        unordered_map<int, int> numToFreq;
        for(auto& num: nums)
            numToFreq[num]++;
        
        for(auto&[num, freq] : numToFreq){
            freqToNums[freq].push_back(num);
        }
        
        vector<int> result;
        for(int freq=n; freq>=1; freq--){
            for(auto& num : freqToNums[freq]){
                result.push_back(num);
                
                if(result.size()==k)
                    return result;
            }
        }
        
        return result;
    }
};