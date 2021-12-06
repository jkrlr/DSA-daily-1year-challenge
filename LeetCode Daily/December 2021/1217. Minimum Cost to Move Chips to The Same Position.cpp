// https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position/

// Easy

// Tags - Maths-Even/Odd Concept, Array, Greedy

// What this problem wants to teach me?
// Don't just try to solve the problem into head, 
// take pen and paper and dry run on test cases and read the problem statement and constraints again,
// Then extract the information that problem want to calculate and try to put it in different words,
// It'll leads to Brute-Force and then again look the problem statement and test cases => leads to optimization

#include<bits/stdc++.h>
using namespace std;

// Brute Force | Time - O(N^2)-using 2 for loops, Space - O(1)

// Even-Odd Concept + Greedy | Time - O(3N), Space - O(1)
// Approach using find the index which has min cost of moving all the piles into that position
// The pos can be even or odd => we've two choices for pos
class Solution {
private:    
    int moveCost(vector<int>& position, int targetPos){
        int cost = 0;
        for(int pos: position){
            if(abs(targetPos-pos)%2==1)
                cost++;
        }
        
        return cost;
    }
public:
    int minCostToMoveChips(vector<int>& position) {
        int odd = -1, even = -1;
        
        for(int pos : position){
            if(pos%2)
                odd = pos;
            else
                even = pos;
        }
        
        int oddPosCost = INT_MAX;
        if(odd!=-1){
            oddPosCost = moveCost(position,odd);
        }
        
        int evenPosCost = INT_MAX;
        if(even!=-1){
            evenPosCost = moveCost(position,even);
        }
        
        return min(oddPosCost, evenPosCost);
    }
};

// Even-Odd Concept + Greedy | Time - O(N)-single pass, Space - O(1)

/* Since move to position[i] + 2 or position[i] - 2 is free, 
    it is natural to think that firstly moving chips as close as possible, with 0 cost.
In fact, we can move all chips at even positions to position 0, and move all chips at the odd positions to position 1.
Then, we only have many chips at position 0 and other chips at position 1. Next, we only need to move those two piles together. */

class Solution { 
public:
    int minCostToMoveChips(vector<int>& position) {
        int odd_cnt = 0, even_cnt = 0;
        
        for(int pos : position){
            if(pos%2)
                odd_cnt++;
            else
                even_cnt++;
        }
        
        return min(odd_cnt,even_cnt);
    }
};