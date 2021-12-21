// https://leetcode.com/problems/power-of-two/

// Easy

// Tags - Math, Bit-Manipulation

#include<bits/stdc++.h>
using namespace std;

// Math-Logarithm| Time = O(LogN), Space = O(1)
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)
            return false;
        
        return floor(log2(n)) == ceil(log2(n));
    }
};

// Bit-Manipulation | Time = O(32), Space = O(1)
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)
            return false;
        
        return (n&n-1) == 0;
    }
};

// Recursive | Time - O(LogN), Space - O(LogN)
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==1)
            return true;
        if(n<=0 || n%2!=0)
            return false;
        
        return isPowerOfTwo(n/2);
    }
};

// Iterative | Time - O(LogN), Space - O(1)

bool isPowerOfTwo(int n) {
        if(n<=0)
            return false;
        while(n!=1)
        {
            if(n%2!=0)
                return false;
            n = n/2;
        }
        return true;
    }
