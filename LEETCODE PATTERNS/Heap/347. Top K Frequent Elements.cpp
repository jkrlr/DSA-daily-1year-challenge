// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

// Medium

// Tags - Bucket-Sort, priority_queue(min_heap) , Hasing (unordered_map), counting

// What this problem wants to teach me?
// How to use Bucket-Sort by treating the freq of element as index and map all the values that have the same freq as idx
// If top-k, word is given in problem then to optimize the brute force approach,
// Think in terms of heap

#include<bits/stdc++.h>
using namespace std;

// Bucket-Sort | Time = O(N+N) = O(N), Space = O(N)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>numToFreq;
        for(auto& num: nums)
            numToFreq[num]++;
        
        vector<vector<int>>freqToNums(nums.size() + 1);   // because if all elements are same than a element can occur at most nums.size() times
        for(auto& [num, freq] : numToFreq){
            freqToNums[freq].push_back(num);
        }
        
        vector<int> result;
        for(int i= nums.size(); i>=0; i--){
            for(int& num : freqToNums[i]){
                result.push_back(num);
                
                if(result.size()==k)
                    return result;
            }
        }
        
        return result;
    }
};

// priority_queue(min_heap) + Hasing (unordered_map) | Time = O(N + N*LogK + K*Log*K), Space = O(N + K)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // O(1) time
        if (k == nums.size()) {
            return nums;
        }

        unordered_map<int, int>numToFreq;
        for(auto& num: nums)
            numToFreq[num]++;
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(auto& [num, freq] : numToFreq){
            if(pq.size()<k)
                pq.push({freq, num});
            else if(pq.top().first < freq){
                pq.pop();
                pq.push({freq,num});
            }
        }
        
        vector<int> result;
        while(!pq.empty()){     // O(kLogk)
            int num = pq.top().second;
            result.push_back(num);
            pq.pop();
        }
        
        return result;
    }
};