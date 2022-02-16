// https://leetcode.com/problems/word-break/

// Medium

// Tags - Dynamic Programming, Hash Table - Unordered_Set(LookUp)

// What this problem wants to teach me?
// Overlapping Subproblems feeling => dynamic programming

#include <bits/stdc++.h>
using namespace std;

// Dynamic Programming -Top Down + Hash Map - Unordered_Set | Time = O(N^2.N) = O(N^3) , Space = O(N + N + M)
class Solution {
private:
    unordered_set<string> st;
    vector<int> dp;
public:
    bool wordBreak(string s, vector<string>& wordDict, int start = 0) {
        for(auto& word : wordDict){
            st.insert(word);
        }
        dp = vector<int>(s.length()+1,-1);
        return solve(s,0);
    }
private:
    bool solve(string s, int start) {
        // base case
        if(start==s.length())
            return true;
        
        // check if answer is already computed or not
        if(dp[start]!=-1)
            return dp[start];
        
        // recursive case
        string curSubStr = "";
        for(int end=start; end<s.length(); end++){
            curSubStr.push_back(s[end]);
            
            if(st.count(curSubStr) > 0){
                bool nextSubproblem = solve(s, end+1);
                if(nextSubproblem==true)
                    return dp[end] = true;
            }
        }
        
        return dp[start] = false;
    }
};

// Dynamic Programming - Bottom Up + Hash Map - Unordered_Set | Time = O(N^2.N) = O(N^3) , Space = O(N + M)
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool> dp(n+1, false);
        dp[n] = true;               // base case
        unordered_set<string> st;
        for(auto& word: wordDict)
            st.insert(word);
        
        for(int i=n-1; i>=0; i--){
            string curSubStr = "";
            
            for(int j=i; j<n; j++){
                curSubStr.push_back(s[j]);
                
                if(st.count(curSubStr)>0)
                    dp[i] = dp[j+1];
            }
        }
        
        return dp[0];
    }
};