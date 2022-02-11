// https://leetcode.com/problems/permutation-in-string/

// Medium

// Tags - Hash Table - Array and Freq Cnt, Sliding Window, Sorting, Two Pointer

// What this problem wants to teach me?
// When string contains only lowercase letters, Then atleast you should think for
// storing the frequencies of characters in array of size 26.
// We can replace the comparision of 26 every time to a single variable matches - // pay attention here more optimized approach
// If string contains the special characters as well. 
// Then in that case use unorderee_map or array of size 256


#include<bits/stdc++.h>
using namespace std;

// Sliding Window of Fixed Length + Array and Freq Cnt, Time Optimized | Time = O(N + 26), Space = O(2*26), N == length of bigger string(s2)
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length())
            return false;
        
        vector<int> s1Count(26,0), s2Count(26,0);
        
        for(int i=0; i<s1.length(); i++){
            s1Count[s1[i] - 'a']++;
            s2Count[s2[i] - 'a']++;
        }
        
        int matches = 0;
        for(int i=0; i<26; i++){
            if(s1Count[i]==s2Count[i])
                matches++;
        }
        
        int left = 0;
        for(int right = s1.length(); right<s2.length(); right++){
            if(matches==26)
                return true;
            
            int idxRight = s2[right] - 'a';
            s2Count[idxRight]++;
            if(s2Count[idxRight]==s1Count[idxRight])
                matches++;
            else if(s2Count[idxRight] - 1 == s1Count[idxRight])
                matches--;
            
            int idxLeft = s2[left] - 'a';
            s2Count[idxLeft]--;
            if(s2Count[idxLeft]==s1Count[idxLeft])
                matches++;
            else if(s2Count[idxLeft] + 1 == s1Count[idxLeft])
                matches--;  
            
            left++;
        }
        
        
        return matches==26;
    }
};

// Sliding Window of Fixed Length + Hash Table- Array and Freq Cnt | Time = O(26*N), Space = O(2*26), N == length of bigger string(s2)
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length())
            return false;
        
        vector<int> s1ToFreq(26,0), substrOfS2ToFreq(26,0);
        
        for(auto& ch: s1)
            s1ToFreq[ch-'a']++;
        
        for(int i=0; i<s2.length(); i++){
            if(i<s1.length())
                substrOfS2ToFreq[s2[i] - 'a']++;
            else{
                if(isEqual(s1ToFreq, substrOfS2ToFreq))
                    return true;
                
                substrOfS2ToFreq[s2[i - s1.length()] - 'a']--;
                substrOfS2ToFreq[s2[i] - 'a']++;
            }
        }
        
        return isEqual(s1ToFreq, substrOfS2ToFreq);
    }
private:
    bool isEqual(vector<int>& freq1, vector<int>& freq2){
        for(int i=0; i<26; i++)
            if(freq1[i]!=freq2[i])
                return false;
        
        return true;
    }
};