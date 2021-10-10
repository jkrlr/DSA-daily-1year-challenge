// https://leetcode.com/problems/two-out-of-three/

// Easy

// What this problem wants to teach me?
/* How to handle duplicates - edge case
   How to arrays can be used to look up a value in multiple inputs agrs simultaneously in O(1) (in small constraints)
   Focus on constraints - they are too small
   unordered_set can be used here*/

/* Constraints:
    1 <= nums1.length, nums2.length, nums3.length <= 100
    1 <= nums1[i], nums2[j], nums3[k] <= 100            */ 

// Solution - Time = O(n1 + n2 + n3) , Space = O(303)
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        int cnt[3][101] = {};
        
        for(auto& n: nums1){
                cnt[0][n] = 1;
        }
        
        for(auto& n: nums2){
                cnt[1][n] = 1;
        }        
        
        for(auto& n: nums3){
                cnt[2][n] = 1;
        }
        
        vector<int> ans;
        
        for(int n=1; n<=100; n++){

            // check if value is present in atleast two vectors 
            if(cnt[0][n] + cnt[1][n] + cnt[2][n] >=2){
                ans.push_back(n);
            }
        }
        return ans;
    }
};