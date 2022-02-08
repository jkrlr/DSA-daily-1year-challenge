// https://leetcode.com/problems/add-digits/

// Easy

// Tags - Maths  -Digital Root, Recursion, Iterative
// What this problem wants to teach me?
// What is digital sum concept and how to apply it.
/* Formula for the Digital Root

There is a known formula to compute a digital root in a decimal numeral system
    dr10(n)=0,if n==0
    dr10(n)=9,if n=9k
    dr10(n) = n mod 9,if n!=9k */

#include<bits/stdc++.h>
using namespace std;

// Digital Root Concept | Time - O(1), Space - O(1)
class Solution {
public:
    int addDigits(int num) {
        if(num==0)
            return 0;
        if(num%9==0)
            return 9;
        return num%9;
    }
};

// Recursive | Time - O(LogN), Space - O(LogN)
class Solution {
public:
    int addDigits(int num) {
        if(num/10==0)
            return num;
        
        int sum = 0;
        while(num){
            sum += num%10;
            num = num/10;
        }
        return addDigits(sum);
    }
};

// Iterative | Time - O(LogN), Space - O(1)
class Solution {
public:
    int addDigits(int num) {
        
        while(true){
            int sum = 0;
            while(num){
                sum += num%10;
                num = num/10;
            }
            
            if(sum/10==0)
                return sum;
            
            num = sum;
        }
        
        return num;
    }
};