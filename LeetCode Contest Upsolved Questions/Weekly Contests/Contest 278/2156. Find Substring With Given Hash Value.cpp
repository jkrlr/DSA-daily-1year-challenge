// https://leetcode.com/problems/maximum-good-people-based-on-statements/

// Medium

// Tags - Sliding Window + Rolling Hash

// What this problem wants to teach me?
// How to apply modulo airthmetic - use it wherever integer overflow happen or value becomes -ve(in this case add modulo value and then take modulo)
// How to use Rolling Hash for the pattern matching problem in strings
// Sometimes, If you studied a algorithm for applying to left to right(for an array).
// In some questions the answer may be come by applying the same algo from right to left by minor tweaking in implementaion in code and algo

#include<bits/stdc++.h>
using namespace std;

// Sliding Window + Rolling Hash | Time - O(N), Space = O(1)
class Solution {
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        long long startIdx = 0, curHashVal = 0, powerK = 1, n = s.length();
        
        for(int i=n-1; i>=0; i--){
            curHashVal = (curHashVal*power + s[i] - 'a' + 1)%modulo;
            if(i+k>=n)
                powerK = (powerK*power)%modulo;
            else{
                curHashVal = (curHashVal - powerK*(s[i+k] - 'a' + 1)%modulo + modulo) % modulo; // Pay attention on this line while taking modulo
            }
            
            if(curHashVal == hashValue)
                startIdx = i;
        }
        
        return s.substr(startIdx,k);
    }
};