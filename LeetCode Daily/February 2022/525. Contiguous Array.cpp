// https://leetcode.com/problems/4sum-ii/

// Medium

// Tags - Hash Table-LookUp,  Replace 0's with -1, Prefix Sum

// What this problem wants to teach me?
// For array containing ony 0's and 1's sometime it is useful to rplace all zeros with -1.
// So, that whenever equal no. of 0's and 1's are come in particular part the sum in that range nullifies.

#include<bits/stdc++.h>
using namespace std;

// Hash Table-LookUp + Replace 0's with -1's + Prefix Sum | Time = O(N), Space = O(N)
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int longestSubarray = 0;
        
        unordered_map<int, int> numToIdx;
        int sum = 0;
        
        for(int i=0; i<nums.size(); i++){
            sum += (nums[i]==0 ? -1 : 1);
            
            if(sum==0){
                longestSubarray = max(longestSubarray, i+1);
            }
            
            else if(numToIdx.find(sum)!=numToIdx.end()){
                int mpIdx = numToIdx[sum];
                longestSubarray = max(longestSubarray, i - mpIdx);
            }
            else{
                numToIdx[sum] = i;
            }
        }
        
        return longestSubarray; 
    }
};