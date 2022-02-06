// https://leetcode.com/problems/minimum-time-to-remove-all-cars-containing-illegal-goods/

// Hard

// Tags - prefix-sum, suffix-sum, dynamic programming

// What this problem wants to teach me?
// Something hard to come up with first time
// Revisit again and read the discuss section again and contemplate on the written code below

#include<bits/stdc++.h>
using namespace std;

// Prefix,Suffix Sum + dp - Kadane's Algo Type + Space Optimized | Time - O(N), Space = O(1)
class Solution {
public:
    int minimumTime(string s) {
        int n = s.length();
        int left = 0, result = n;
        
        for(int i=0; i<n; i++){
            left = min(left + (s[i] - '0')*2, i+1);
            result = min(result, left + n-1-i);
        }
        
        return result;
    }
};

// Prefix,Suffix Sum + dp - Kadane's Algo Type | Time - O(3N), Space = O(2N)
class Solution {
public:
    int minimumTime(string s) {
        int n = s.length();
        vector<int> left(n,0), right(n,0);
        
        if(s[0]=='1')
            left[0] = 1;
        
        for(int i=1; i<n; i++){
            if(s[i]=='1')
                left[i] = min(left[i-1] + 2, i+1);
            else
                left[i] = left[i-1];
        }
        
        if(s[n-1]=='1')
            right[n-1] = 1;
        for(int i=n-2; i>=0; i--){
            if(s[i]=='1')
                right[i] = min(right[i+1] + 2, n-i);
            else
                right[i] = right[i+1];
        }
        
        int minTime = min(left[n-1], right[0]);
        for(int i=0; i<n-1; i++){
            minTime = min(minTime, left[i] + right[i+1]);
        }
        
        return minTime;
    }
};

// Prefix,Suffix Sum | Time - O(6N), Space = O(4N)
class Solution {
public:
    int minimumTime(string s) {
        int n = s.length();
        
        if(n==1)
            return s[0]=='1'? 1 : 0;
        
        vector<int> left(n), right(n);
        int curr = 0;
        for(int i=0; i<n; i++){
            if(s[i]=='1')
                curr +=1;
            else
                curr -=1;
            
            left[i]=curr;
        }
        
        curr = 0;
        for(int i=n-1; i>=0; i--){
            if(s[i]=='1')
                curr +=1;
            else
                curr -=1;
            
            right[i]=curr;
        }
        
        int maxPossibleCost = 2*count(begin(s), end(s), '1');
        
        vector<int> leftMax(n);
        curr = INT_MIN;
        
        for(int i=0; i<n; i++){
            curr = max(curr, left[i]);
            leftMax[i] = curr;
        }
        
        
        vector<int> rightMax(n);
        curr = INT_MIN;
        
        for(int i=n-1; i>=0; i--){
            curr = max(curr, right[i]);
            rightMax[i] = curr;
        }
        
        int maxPossibleCostCanBeSaved = 0;
        for(int i=0; i<n-1; i++){
            maxPossibleCostCanBeSaved = max(maxPossibleCostCanBeSaved, max(0,leftMax[i]) + max(0,rightMax[i+1]));
        }
        
        return maxPossibleCost - maxPossibleCostCanBeSaved;
    }
};