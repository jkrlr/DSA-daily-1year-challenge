// https://leetcode.com/problems/vowels-of-all-substrings/

// Medium

// Tags - dp, prefixSum, math

// What this problem wants to teach me?

/* Explanation
        For each vowels s[i],
        it could be in the substring starting at s[x] and ending at s[y],
        where 0 <= x <= i and i <= y < n,
        that is (i + 1) choices for x and (n - i) choices for y.

        So there are (i + 1) * (n - i) substrings containing s[i] */

#include<bits/stdc++.h>
using namespace std;

// Math | Time = O(N), Space = O(1)
class Solution {
public:
    long long countVowels(string word) {
        long long ans = 0;
        int n = word.length(); 
        const string vowels = "aeiou";
        
        for(int i=0; i<n; ++i){
            if(vowels.find(word[i])!=-1){
                ans += (long long)(i+1) * (long long)(n-i);
            }
        }
        return ans;
    }
};

// dp Solution - Complete it after end sem
// https://leetcode.com/problems/vowels-of-all-substrings/discuss/1563751/C%2B%2B-or-O(n)-or-Brute-to-Optimal-or-Best-Explanation
// https://leetcode.com/discuss/general-discussion/458695/dynamic-programming-patterns 