// https://leetcode.com/problems/valid-mountain-array/

// Easy

// Tags - Array - Find Peak and Linear Traversal

// What this problem wants to teach me?


#include<bits/stdc++.h>
using namespace std;

// Find Peak and Linear Traversal | Time = O(N), Space = O(1)
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size()<3)
            return false;
        
        int i = 1;
        // walk up
        while(i<arr.size() && arr[i] > arr[i-1])
            i++;
        
        // peak can't be first or last
        if(i==1 || i==arr.size())
            return false;
        
        // walk down
        while(i<arr.size() && arr[i-1] > arr[i])
            i++;
        
        return i==arr.size();
    }
};