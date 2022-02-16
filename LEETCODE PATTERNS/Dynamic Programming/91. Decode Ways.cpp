// https://leetcode.com/problems/decode-ways/

// Medium

// Tags - Dynamic Programming, String

// What this problem wants to teach me?
/* How to convert the void return recursive code to int return recursive code 
 by doing small manipulations in code where we're storing the values or from the return statement of void recursion */
/* Sometimes it is easier to write the bottom up approach starting from the last element assuming the rightside to start to end of bounds */
/* How to convert the Top Down code into bottom up code while building the solution of array from right side to left side(means n-1 to 0) */

#include <bits/stdc++.h>
using namespace std;

// Top Down DP | Time = O(N) , Space = O(N+N)
class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.length(),-1);
        return countOfWays(s, dp, 0);
    }
private:
    int countOfWays(string& s, vector<int>&dp, int start){
        // base case
        if(start == s.length()){
            return 1;
        }
        if(s[start] == '0'){
            return dp[start] = 0;
        }
        
        // check if state is already computed or not
        if(dp[start]!=-1)
            return dp[start];
        
        // recursive case
        int ways = countOfWays(s, dp, start+1);
        if(start+1 < s.length() && (s[start]=='1' || (s[start]=='2' && (s[start+1] <='6')))){
            ways += countOfWays(s, dp, start+2);
        }
        
        return dp[start] = ways;
    }
};

// Bottom-Up DP | Time = O(N) , Space = O(N)
class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if(n<1)
            return 0;
        
        vector<int> dp(n+1,0);
        dp[n] = 1;
        
        for(int start=n-1; start>=0; start--){
            if(s[start]=='0')
                dp[start] = 0;
            else{
                dp[start] = dp[start+1];
                
                if(start+1 < n && (s[start]=='1' || (s[start]=='2' && s[start+1] <='6')))
                    dp[start] += dp[start+2];
            }
        }
        
        return dp[0];
    }
};

// Bottom-Up - Space Optimized DP | Time = O(N) , Space = O(1)
class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if(n<1)
            return 0;
        
        int next = 1, nextOfNext = 0;
        int curr = 0;
        
        for(int start=n-1; start>=0; start--){
            if(s[start]=='0')
                curr = 0;
            else{
                curr = next;
                
                if(start+1 < n && (s[start]=='1' || (s[start]=='2' && s[start+1] <='6')))
                    curr += nextOfNext;
            }
            
            nextOfNext = next;
            next = curr;
        }
        
        return next;
    }
};