// https://leetcode.com/problems/complement-of-base-10-integer/

// Easy

// Tags - 1's Complement, Bit-Manipulation

// What this problem wants to teach me?
// See the problem constraints carefully and test your code into leftmost and rightmost limits of constraints
// How to convert a base-10 number into 1's complement
/* If multiple conditions are present in if,while loops 
    Then, seperate the individual condition by paranthesis, otherwise due to precedence rule of operators coditions will be evaluated
    and the code may give the wrong answer */

#include<bits/stdc++.h>
using namespace std;

// Find 111.....1111 >= N | Time = O(LogN), Space = O(1)
// A binary number plus its complement will equal 111....111 in binary. Also, N = 0 is a corner case.
class Solution {
public:
    int bitwiseComplement(int n) {
        
        int mask = 1;   // mask = pow(2, x) – 1; mask is the smallest number >= N
        while(mask < n){
            mask = (mask<<1) | 1;   //mask = mask*2 + 1;  same as left
        }
        
        return n^mask;  // return mask - N;  also ok  
    }
};

// 1's Complement | Time = O(N), Space = O(1)
class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0)
            return 1;
        
        int complement = 0;
        int mask = 0;
        while(n){
            if((n&1)==0)
                complement += (1<<mask);
            
            mask++;
            n = (n>>1);
        }
        
        return complement;
    }
};