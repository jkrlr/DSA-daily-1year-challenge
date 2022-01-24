// https://leetcode.com/problems/detect-capital/

// Easy

// Tags - String - ASCII Value Comparision

// What this problem wants to teach me?

#include<bits/stdc++.h>
using namespace std;

// String - ASCII Value Comparision | Time - O(N), Space - O(1) 
class Solution {
public:
    bool detectCapitalUse(string word) {
        int capitalLetterCount  = 0;
        for(char& ch: word){
            if(ch>='A' && ch<='Z')
                capitalLetterCount++;
        }
        
        if(capitalLetterCount == 0 || capitalLetterCount == word.length() || (capitalLetterCount==1 && word[0]>='A' && word[0]<='Z'))
            return true;
        
        return false;
    }
};