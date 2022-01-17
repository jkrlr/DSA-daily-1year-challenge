// https://leetcode.com/problems/word-pattern/

// Easy

// Tags - Hashing, stringstream

// What this problem wants to teach me?
// How to use stringstream object for extracting the tokens in string object that are seperated by a delimeter
// First write the less efficient and less readable code then optimize and make more modular code
// after you write the complete code or make changes along the way if it is easy to write the earlier ones

#include<bits/stdc++.h>
using namespace std;


// Hashing + stringstream | Time = O(N*W), Space = O(N*W + N*W + N*W) = (3NW) - N=> word.size(), W=> word[i].length()
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        string word;
        int n = pattern.size(), i=0;
        unordered_map<char, string> charToStr;
        unordered_map<string, char> strToChar;
        while(ss>>word){        // same as while(getline(ss, word, ' ')){
            if(i==n)    return false;   // if pattern length is less
            
            char ch = pattern[i];
            if(charToStr.count(ch)!=strToChar.count(word))  // if one is present but other is not
                return false;
            
            if(charToStr.count(ch)){
                if(charToStr[ch]!=word || strToChar[word]!=ch)  // If at char and word, their is different mapping
                    return false;
            }
            else{
                charToStr[ch] = word;
                strToChar[word] = ch;
            }
            
            i++;
        }
        
        return i==n;   // true, If both patterns and s have the same length 
    }
};

// Hashing + stringstream - less efficient solution | Time = O(4*NW), Space = O(4*NW)
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        // extract all space seperated words from s
        stringstream ss(s);
        vector<string> tokens;
        string token;
        while(getline(ss,token,' ')){
            tokens.push_back(token);
        }
        
        if(tokens.size()!=pattern.length())
            return false;
        
        unordered_map<char, unordered_set<string>> mp1;
        unordered_map<string, unordered_set<char>> mp2;
        for(int i=0; i<pattern.size(); i++){
            mp1[pattern[i]].insert(tokens[i]);
            mp2[tokens[i]].insert(pattern[i]);
        }
        
        for(auto& it: mp1){
            if(it.second.size()!=1)
                return false;
        }
        for(auto& it: mp2){
            if(it.second.size()!=1)
                return false;
        }
        return true;
    }
};