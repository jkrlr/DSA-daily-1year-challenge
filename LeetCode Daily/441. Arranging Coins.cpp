// https://leetcode.com/problems/arranging-coins/

// Eay

// Tags - Binary Tree, Triangular series, Math, Brute-Force

// What this problem wants to teach me?

#include<bits/stdc++.h>
using namespace std;

//Triangular Series + Math Solution - Time = O(sqrt(N)), Space = O(1)

class Solution {
public:
    int arrangeCoins(int n) {
        int ans = (-1 + sqrt(1+8*(long)n))/2;
        return ans;
    }
};