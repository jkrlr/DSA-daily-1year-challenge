// https://leetcode.com/problems/numbers-at-most-n-given-digit-set/

// Hard

// Tags - Maths, Dynamic Programming-Digit Dp

// What this problem wants to teach me?
// How to access char of vector<string> entities
// How to cnt the numbers by making certain digits having digits less than the digits of num
// How to cnt the numbers by making certaing digits having digits equal to the digits of num

#include<bits/stdc++.h>
using namespace std;

// Dynamic Programming + Counting | Time = O(logn) , Space = O(logn) - used in dp and s 
// Assuming digits.size() to be constant
class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        sort(digits.begin(), digits.end());
        string s = to_string(n);
        int k = s.length();
        
        vector<int> dp(k+1,0);
        dp[k] = 1;
        int base = digits.size();
        
        // 1. Cnt nums having digits equal to digits in n
        for(int i=k-1; i>=0; --i){
            // string si = to_string(s[i] -'0');
            char si = s[i];
            
            for(string d : digits){
                if(d[0] < si)
                    dp[i] += pow(base,k-i-1);
                else if(d[0] == si)
                    dp[i] += dp[i+1];
            }
        }
        
        // 2. Cnt nums having digits less than the digits in n
        for(int i=1; i<k; i++)
            dp[0] += pow(base,i);
        
        return dp[0];
    }
};