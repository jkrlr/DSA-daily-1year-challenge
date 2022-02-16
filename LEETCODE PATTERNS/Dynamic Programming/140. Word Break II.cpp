// https://leetcode.com/problems/word-break-ii/

// Hard

// Tags - Recursion, Backtracking, Hash Table - Unordered_Set(LookUp)

// What this problem wants to teach me?
// Recursion and Backtracking usage

#include <bits/stdc++.h>
using namespace std;

// Recursion + Backtracking + Hash Map - Unordered_Set | Time = O(N*W + 2^N * N) , Space = O(N + N + N*W)
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> result;
        unordered_set<string> st;
        for(auto& word: wordDict){
            st.insert(word);
        }
        string curr="";
        solve(s,st,result,curr,0);
        
        return result;
    }
private:
    void solve(string s, unordered_set<string>& st, vector<string>& result, string& currStr, int start){
        // base case
        if(start==s.length()){
            currStr.pop_back(); // remove the last space additional space
            result.push_back(currStr);
            return;
        }
        
        
        // recursive case
        string currsubstr = "";
        for(int end=start; end<s.length(); end++){
            currsubstr.push_back(s[end]);
            
            if(st.count(currsubstr)>0){
                string tmp = currStr;
                currStr = currStr + currsubstr + ' ';
                
                solve(s,st,result, currStr, end+1);
                
                currStr = tmp;  // backtracking
            }
        }
    }
};