// https://leetcode.com/problems/car-pooling/

// Medium

// Tags - Cummulative Sum(Prefix Sum), Array

// What this problem wants to teach me?
// Take care of edge cases on leftmost and rightmost limits of input
// If input size/constraints is small, Then you can think of prefix sum/cummulative sum type to find/optimize the solution
// Which DS or which algo should I use for this problem => Always think also in terms of this approach

#include<bits/stdc++.h>
using namespace std;

// Cummulative Sum(Prefix Sum) | Time = O(N), Space = O(N)

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int lastDropLocation = -1;
        for(auto& trip : trips)
            lastDropLocation = max(lastDropLocation, trip[2]);
        
        vector<int>highway(lastDropLocation+1,0);
        for(auto& trip: trips){
            int passangers = trip[0], from = trip[1], to = trip[2];
            highway[from] += passangers;
            highway[to]  -= passangers;
        }
        
        if(highway[0] > capacity)
            return false;
        
        for(int i=1; i<=lastDropLocation; i++){
            highway[i] += highway[i-1];
            
            if(highway[i] > capacity)
                return false;
        }
        
        return true;
    }
};