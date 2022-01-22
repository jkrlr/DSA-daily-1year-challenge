// https://leetcode.com/problems/palindrome-partitioning/

// Medium

// Tags - Dynamic Programming, Math - Square root, Game Theory

// What this problem wants to teach me?
// Do dry run on some test cases and you see overlapping is their
// then use dp
// In possible ways or winning/lossing type advanced questions Recursion will be possibly used
// and for recursion code -> first find the base case and then focus completely on clearly 
// writing the answer for current state by re-reading the question and by seeing the constraints


#include<bits/stdc++.h>
using namespace std;

// Top-Down DP | Time = O(N*sqrt(N)), Space = O(N)
class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int> dp(n+1, -1);
        return solve(dp,n);
    }
private:
    bool solve(vector<int>& dp, int n){
        // base case
        if(n==0){
            return false;
        }
        
        // check if state is already computed or not
        if(dp[n]!=-1)
            return dp[n];
        
        // recursive case
        bool result = false;
        for(int i=1; i*i<=n; i++){
            if(solve(dp,n-(i*i)) == false){
                result = true;
                break;
            }
        }
        
        return dp[n] = result;
    }
};

// Bottom-UP DP | Time = O(N*sqrt(N)), Space = O(N)
class Solution {
public:
    bool winnerSquareGame(int N) {
        vector<bool> dp(N+1, false);
        
        for(int n=1; n<=N; n++){
            for(int i=1; i*i<=n; i++){
                if(dp[n-(i*i)] == false){
                    dp[n] = true;
                    break;
                }
            }
        }
        return dp[N];
    }
};