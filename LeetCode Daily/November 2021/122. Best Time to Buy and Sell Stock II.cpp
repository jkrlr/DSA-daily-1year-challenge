// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

// Medium

// Tags - Dynamic Programming, Greedy

// What this problem wants to teach me?
// How to solve problems by drawing the increasing-decreasing graph sequence of given input integers
// using the Peak-Valley approach
// How we can use boolean in dp table by treating false as 0 ans true as 1 

#include<bits/stdc++.h>
using namespace std;

// Recursion | Solution - Time = O(2^N), Space = O(N)- for recursion depth
// Top-Down DP | Solution - Time = O(2*N), Space = O(2*N)-for dp and O(N) for recursion depth
class Solution {
public:
    int solve(vector<int>& prices, int pricesIndex, bool alreadyBuyed, vector<vector<int>>& dp){
        // base case
        if(pricesIndex == prices.size()){
            return 0;
        }
        
        // check if a state is precomputed or not
        if(dp[pricesIndex][alreadyBuyed]!=-1){
            return dp[pricesIndex][alreadyBuyed];
        }
        
        // recursive case
        int buy = 0, sell = 0, doNothing = 0;
        if(alreadyBuyed){
            sell = prices[pricesIndex] + solve(prices,pricesIndex+1, false,dp);
        }
        else{
            buy =  (-1)*prices[pricesIndex] + solve(prices, pricesIndex+1,true,dp) ;
        }
        
        doNothing = solve(prices, pricesIndex + 1, alreadyBuyed,dp);
        
        return dp[pricesIndex][alreadyBuyed] = max(doNothing, max(buy,sell));
    }
    
    int maxProfit(vector<int>& prices) {
        int pricesIndex = 0;
        vector<vector<int>> dp(prices.size(), vector<int>(2,-1));
        return solve(prices,pricesIndex, false,dp);
    }
};

// Greedy-PeakValue Approach | Solution - Time = O(N), Space = O(1)
class Solution {
public:  
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2){
            return 0;
        }
        
        int n = prices.size();
        int index = 0;
        int peak = prices[0];
        int valley = prices[0];
        int maxprofit = 0;
        
        while(index < n-1){
            // find valley
            while(index < n-1 && prices[index] >= prices[index+1]){
                index++;
            }
            valley = prices[index];
            
            // find peak
            while(index < n-1 && prices[index] <= prices[index+1]){
                index++;
            }
            peak = prices[index];
            
            // calculate profit
            maxprofit += peak - valley;
        }   
        
       return maxprofit; 
    }
};

// Greedy-PeakValue Approach | Solution - Time = O(N)-Single Pass, Space = O(1)
class Solution {
public:  
    int maxProfit(vector<int>& prices) {

        int maxprofit = 0;
        
        for(int i = 1; i<prices.size(); i++){
            if(prices[i] > prices[i-1]){
               maxprofit += prices[i] - prices[i-1]; 
            }
        }
        
       return maxprofit; 
    }
};