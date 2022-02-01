// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

// Easy

// Tags - Two Pointer, Peak-valley graph, Kadane's Algorithm, Array

// What this problem wants to teach me?
// In problems like differene to be max or find the global/local min/max type problems
// For optimize the approach start draw the solution in terms of peak and valley graph
// and then use two pointer to get the answer

#include<bits/stdc++.h>
using namespace std;

// Two Pointer | Time = O(N), Space = O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0, right = 1;
        int maxProfit = 0;
        
        while(right < prices.size()){
            // If profitable?
            if(prices[left] < prices[right]){
                int profit = prices[right] - prices[left];
                maxProfit = max(profit, maxProfit);
            }
            else
                left = right;
            
            right++;
        }
        
        return maxProfit;
    }
};

// MinPriceSoFar | Time = O(N), Space = O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int minPrice = INT_MAX;
        for(int i=0; i<prices.size(); i++){
            minPrice = min(minPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i]-minPrice);
        }
        
        return maxProfit;
    }
};