// https://leetcode.com/problems/minimum-operations-to-make-the-array-alternating/

// Medium

// Tags - Unordered_Map - Frequency Count, Majority Element, Edge Case Thinking, Array, Dp

// What this problem wants to teach me?
// Don't be afraid to write the edge cases multiple conditions

#include<bits/stdc++.h>
using namespace std;

// Unordered_Map - Frequency Count + first and second Majority Element | Time - O(4*N), Space - O(2*N)
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int,int> oddIdxNumsToFreq, evenIdxNumsToFreq;
        int n = nums.size();
        
        for(int i=0; i<n; i++){
            if(i&1)
                oddIdxNumsToFreq[nums[i]]++;
            else
                evenIdxNumsToFreq[nums[i]]++;
        }
        
        
        int firstOddMax = 0, firstOddMaxFreq = 0;
        int secondOddMax = 0, secondOddMaxFreq = 0;
        
        for(auto& [num, freq] : oddIdxNumsToFreq){
            if(freq > firstOddMaxFreq){
                secondOddMax = firstOddMax;
                secondOddMaxFreq = firstOddMaxFreq;
                
                firstOddMax = num;
                firstOddMaxFreq = freq;
            }
            
            else if(freq > secondOddMaxFreq){
                secondOddMax = num;
                secondOddMaxFreq = freq;
            }
        }
        
        int firstEvenMax = 0, firstEvenMaxFreq = 0;
        int secondEvenMax = 0, secondEvenMaxFreq = 0;
        for(auto& [num, freq] : evenIdxNumsToFreq){
            if(freq > firstEvenMaxFreq){
                secondEvenMax = firstEvenMax;
                secondEvenMaxFreq = firstEvenMaxFreq;
                
                firstEvenMax = num;
                firstEvenMaxFreq = freq;
            }
            
            else if(freq > secondEvenMaxFreq){
                secondEvenMax = num;
                secondEvenMaxFreq = freq;
            }
        }
        
        int result;
        if(firstOddMax != firstEvenMax){
            result = (n - firstOddMaxFreq - firstEvenMaxFreq);
        }
        else{
            if(oddIdxNumsToFreq.size()==1 && evenIdxNumsToFreq.size()==1)
                result = n - max(firstEvenMaxFreq, firstOddMaxFreq);
            else if(oddIdxNumsToFreq.size()==1)
                result = n - (firstOddMaxFreq + secondEvenMaxFreq);
            else if(evenIdxNumsToFreq.size()==1)
                result = n - (firstEvenMaxFreq + secondOddMaxFreq);
            else
                result = n - max(firstOddMaxFreq + secondEvenMaxFreq, firstEvenMaxFreq + secondOddMaxFreq);
                
        }
        
        return result;
    }
};