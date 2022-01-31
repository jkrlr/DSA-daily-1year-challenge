// https://leetcode.com/problems/richest-customer-wealth/

// Easy

// Tags - Matrix

// What this problem wants to teach me?
// Brute-Force


#include<bits/stdc++.h>
using namespace std;

// Brute-Force | Time = O(N), Space = O(1)
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int mxWealth = 0;
        for(auto& account : accounts){
            int curCustWealth = 0;
            for(int& money : account){
                curCustWealth += money;
            }
            mxWealth = max(mxWealth, curCustWealth);
        }
        
        return mxWealth;
    }
};