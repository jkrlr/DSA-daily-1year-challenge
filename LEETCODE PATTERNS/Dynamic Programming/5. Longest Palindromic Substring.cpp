// https://leetcode.com/problems/longest-palindromic-substring/

// Medium

// Tags - Dynamic Programming, String

// What this problem wants to teach me?

#include <bits/stdc++.h>
using namespace std;

// Dynamic Programming - OverLapping Subporblem(Expan Around Center) | Time = O(N^2) , Space = O(1)
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()<1)
            return "";
        
        int start = 0, end = 0;
        for(int mid = 0; mid<s.length(); mid++){
            int oddLen = expandAroundCenter(s,mid,mid);
            if(oddLen > end - start){
                start = mid - oddLen/2;
                end   =  mid + oddLen/2;
            }

            int evenLen = expandAroundCenter(s,mid, mid+1);
            if(evenLen > end - start){
                start = mid + 1 - evenLen/2;
                end = mid + evenLen/2;
            }
        }
        
        return s.substr(start, end-start+1);
    }
private:
    int expandAroundCenter(string &s, int left, int right){
        int L = left, R = right;
        while(L>=0 && R<s.length() && s[L]==s[R]){
            L--;
            R++;
        }
        
        return R-L-1;
    }
};