// https://leetcode.com/problems/find-the-difference/

// Easy

// Tags - Array as Hash Table, Bit Manipulation-XOR, Sorting, String

// What this problem wants to teach me?
// Simple use of array to store the frequency of letters in case of string containing the lowercase letters only
/* The trick is to think about this as analogous to the problem about finding the only non-duplicated number into a vector; 
    it it is just that this time you need to parse through 2 strings at once, but the core bitwise property still old true:
    a ^ b == 0; // IFF a == b
  So, progressively XORing all the characters, all that is left is the sole unique one and we can return it :) */

#include<bits/stdc++.h>
using namespace std;

// Bit Manipulation-XOR | Time - O(N+M), Space - O(1)
class Solution {
public:
    char findTheDifference(string s, string t) {
        char res = 0;
        for(auto& ch: s)
            res = res^ch;
        for(auto& ch: t)
            res = res^ch;
        
        return res;
    }
};

// Array as Hash Table | Time - O(N+M), Space - O(2*26)
class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> freqS(26,0), freqT(26,0);
        
        for(auto& ch: s){
            freqS[ch-'a']++;
        }
        
        for(auto& ch: t){
            freqT[ch-'a']++;
        }
        
        for(int i=0; i<26; i++){
            if(freqS[i]!=freqT[i])
                return (char)(i+'a');
        }
        
        return {};
    }
};