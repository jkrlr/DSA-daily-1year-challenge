// https://leetcode.com/problems/k-diff-pairs-in-an-array/

// Medium

// Tags - Hash Table, Skip Duplicates - Set, Two Pointer, Binary Search, Sorting, Array

// What this problem wants to teach me?
// We Can avoid the duplicacy with the help of unordered_map also by collecting key and their frequencies
// After storing all the elements into the unordered_map, we have to start traversing element by element from the unordered_map not from the array
// because if we start traversing from the array, then we'll cnt the same answer multiple times in case of duplicates
// Variation of pair sum problem

#include<bits/stdc++.h>
using namespace std;

// Hash Table-Unordered_Map | Time = O(2*N), Space = O(N)
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k<0)
            return 0;
        
        unordered_map<int,int> numToFreq;
        for(auto& num: nums)
            numToFreq[num]++;
        
        int cnt = 0;
        for(auto& [num, freq]: numToFreq){
            if(k==0){
                if(numToFreq[num]>=2)
                    cnt++;
            }
            else{
                if(numToFreq.find(num+k)!=numToFreq.end())
                    cnt++;
            }
        }
        
        return cnt;
    }
};

// Hash Table-Unordered_Set, Skip Duplicates - Set | Time = O(NLogN), Space = O(2*N)
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_set<int> s;
        set<pair<int,int>> pairs;
        for(auto& num: nums){
            int x = num + k;
            int y = num - k;
            
            if(s.count(x)){
                if(pairs.find({num, x})==pairs.end() && pairs.find({x,num})==pairs.end())
                    pairs.insert({num,x});
            }
            
            if(s.count(y)){
                if(pairs.find({num, y})==pairs.end() && pairs.find({y,num})==pairs.end())
                    pairs.insert({num,y});
            }
            
            s.insert(num);
        }
        
        return pairs.size();
    }
};