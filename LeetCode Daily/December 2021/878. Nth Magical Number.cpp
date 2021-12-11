// https://leetcode.com/problems/nth-magical-number/

// Hard

// Tags - Binary Search, Maths-LCM,HCF Concept

// What this problem wants to teach me?
// Don't hesitate in declaring a variable by long intstead of int and 
// make explicit conversions of int to long in multiplications/additions
// If search space is monotonic, Then we can use binary search => If hi is large
// Then, Try to optimize is the isValid(mid) condition to O(1) or O(LogN) in case of Maths
// By using some mathematical known formula concepts
// Try to break the problem into case and then try to find out the solutions for each case(steps)

#include <bits/stdc++.h>
using namespace std;

// Binary Search | Time - O(Log(n*min(a,b))), Space - O(1)

class Solution {
private:
    int gcd(int a, int b){
        if(b==0)
            return a;
        
        return gcd(b,a%b);
    }
public:
    int nthMagicalNumber(int n, int a, int b) {
        int MOD = 1e9 + 7;
        int LCM = (a/gcd(a,b))*b;   // LCM * HCF = A * B;
        
        long lo = 0;
        long hi = (long)n * min(a,b);   // Pay attention here in explicit conversion into long from int in case of multiiplications/additions
        
        while(lo<=hi){
            long mi = lo + (hi-lo)/2;
            
            // If there are not enough magic numbers below mi...
            if((mi/a) + (mi/b) - (mi/LCM) < n)
                lo = mi + 1;
            else
                hi = mi-1;
        }
        
        return (int)(lo % MOD);
    }
};

// Maths-LCM,HCF Concept | Time - O(a+b), Space - O(1)

class Solution {
private:
    int gcd(int a, int b){
        if(b==0)
            return a;
        
        return gcd(b,a%b);
    }
public:
    int nthMagicalNumber(int n, int a, int b) {
        int MOD = 1e9 + 7;
        int LCM = (a/gcd(a,b))*b;   // LCM * HCF = a * b;
        
        int m = (LCM/a) + (LCM/b) - 1;
        int q = n/m, r = n % m;
        
        long long ans = (long)q * LCM % MOD;
        if(r==0)
            return (int) ans;
        
        int heads[2] = {a,b};
        
        for(int i=0; i<r-1; i++){
            if(heads[0]<=heads[1])
                heads[0] += a;
            else
                heads[1] +=b;
        }
        
        ans += min(heads[0], heads[1]);
        
        return (int)(ans % MOD);
    }
};