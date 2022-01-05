// https://leetcode.com/problems/palindrome-partitioning/

// Medium

// Tags - Recursing, Backtacking, Dynamic Programming

// What this problem wants to teach me?
// For generating all possible combinations use recursion(If constraints allow, else optimize approach)
// DP can be used for a smaller condition checking part also in a problem => overlapping subproblem is important => DP (on that particular part)

#include<bits/stdc++.h>
using namespace std;

// Recursion + Backtracking + Dp(while checking palindrome) | Time = O(2^N), Space = O(N.)
class Solution {
public:
    vector<vector<string>> partition(string s) {
        int len = s.length();
        vector<vector<bool>> dp(len,vector<bool>(len,false));
        vector<vector<string>> result;
        vector<string> currentList;
        dfs(s,0,result,dp,currentList);
        
        return result;
    }
private:
    void dfs(string& s, int start, vector<vector<string>>& result,vector<vector<bool>>& dp, vector<string>& currentList){
        if(start >= s.length()){
            result.push_back(currentList);
        }
        
        for(int end = start; end<s.length(); end++){
            if(s[start]==s[end] && (end-start<=2 || dp[start+1][end-1])){
                dp[start][end] = true;
                
                currentList.push_back(s.substr(start, end-start + 1));
                dfs(s,end+1,result,dp, currentList);
                
                currentList.pop_back();
            }
        }
    }
};

// Recursion + Backtracking + Check Palindrome | Time = O(2^N), Space = O(N.N)
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> currentList;
        dfs(s,0,result,currentList);
        
        return result;
    }
private:
    bool isPalindrome(string& str, int lo, int hi){
        while(lo < hi){
            if(str[lo++]!=str[hi--])
                return false;
        }
        return true;
    }
private:
    void dfs(string& s, int start, vector<vector<string>>& result, vector<string>& currentList){
        if(start >= s.length()){
            result.push_back(currentList);
        }
        
        for(int end = start; end<s.length(); end++){
            if(isPalindrome(s,start,end)){
                // add current substring in the currentList
                currentList.push_back(s.substr(start, end-start + 1));
                dfs(s,end+1,result,currentList);
                
                // backtrack and remove the current substring from currentList
                currentList.pop_back();
            }
        }
    }
};