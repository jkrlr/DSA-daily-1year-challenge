// https://leetcode.com/problems/consecutive-characters/

// Easy

// Tags - String

// What this problem wants to teach me?
// How to find the substring with maximum frequency of same character in one pass

#include<bits/stdc++.h>
using namespace std;

// One Pass | Time = O(n), Space = O(1)
class Solution {
public:
    int maxPower(string s) {
        int count = 0;
        int maxCount = 0;
        int previous = ' ';
        
        for(int i=0; i<s.length(); i++){
            char c = s[i];
            if(c==previous){
                // if same as previous one, increase the count
                count++;
            }
            else{
                // else, reset the count
                count = 1;
                previous = s[i];
            }
            
            maxCount = max(maxCount,count);
        }
        
        return maxCount;
    }
};