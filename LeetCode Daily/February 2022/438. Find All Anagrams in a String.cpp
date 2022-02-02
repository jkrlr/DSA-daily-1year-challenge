// https://leetcode.com/problems/find-all-anagrams-in-a-string/

// Medium

// Tags - Hash Table-(for storing the frequency), Sliding window - String comparision by frequency

// What this problem wants to teach me?
// size_t length() const; => string.length() return the size of string in unsigned int
// so if the difference of two unsigned goes to -ve, Then it will automatically converts it into
// the max_value_of_unsigned_int - -ve_value, Which becomes +ve value and your codition of while or if or for loop
// gives the out of bound index for array. So, don't forget to explicit conversion into int for unsigned values

#include<bits/stdc++.h>
using namespace std;

// Array as Hash Table, Sliding Window for string comaprison | Time = O(26*(N-M)), Space = O(2*26)

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        vector<int> lettersFreqOfS(26,0), lettersFreqOfP(26,0);
        
        for(char& ch: p){
            int idx = ch - 'a';
            lettersFreqOfP[idx]++;
        }
        
        for(int i=0; i<min(p.length(), s.length()); i++){
            int idx = s[i] - 'a';
            lettersFreqOfS[idx]++;
        }

        for(int i=0; i<=(int)(s.length() - p.length()); i++){   // Pay attention here for explicit conversion
            if(i>0){
                lettersFreqOfS[s[i-1] - 'a']--;     // compress the window from left
                lettersFreqOfS[s[i + p.length()-1] - 'a']++;    // expand the window toward right
            }
            if(haveSameLetterFreq(lettersFreqOfS, lettersFreqOfP))
                    result.push_back(i);
        }
        
        return result;
    }
private:
    bool haveSameLetterFreq(vector<int>& a, vector<int>& b){
        for(int i=0; i<a.size(); i++)
            if(a[i]!=b[i])
                return false;
        
        return true;
    }
};
