// https://leetcode.com/problems/minimum-cost-to-set-cooking-time/

// Medium

// Tags - Brute-Force, Try Generating all the permutations, Math

// What this problem wants to teach me?
/* When Choices are small under 10 or 20. Then in such cases try to generate all the permutations
    iteratively or recursively whatever will be easy and then check if a permutation is valid or not
    if permutation is valid then calculate the answer for that case and try to find out the answer */
/* If you have lesser choices (like 4 or 5), Then you can store them into vector instead of declaring them 
    individually in form of variables...Sometimes this will shorten the line of code. */

#include<bits/stdc++.h>
using namespace std;

// Brute-Force, Try Generating all the permutations | Time - O(10^4), Space - O(1)
class Solution {
public:
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        // Try generating all the possible permutations
        int minCost = INT_MAX;
        for(int i=0; i<=9; i++){
            for(int j=0; j<=9; j++){
                int minute = 10*i + j; 
                
                for(int k=0; k<=9; k++){
                    for(int l=0; l<=9; l++){
                        int second = 10*k + l;
                        
                        int totalTimeInSeconds = minute*60 + second;
                        if(totalTimeInSeconds == targetSeconds){
                            vector<int> clockDigits;
                            
                            clockDigits.push_back(i);
                            clockDigits.push_back(j);
                            clockDigits.push_back(k);
                            clockDigits.push_back(l);

                            int currCost = findCost(clockDigits, startAt, moveCost, pushCost);
                            minCost = min(minCost, currCost);

                            while(clockDigits.size()> 0 && clockDigits[0]==0){
                                clockDigits.erase(clockDigits.begin());

                                currCost = findCost(clockDigits, startAt, moveCost, pushCost);
                                minCost = min(minCost, currCost);
                            }
                        }
                        
                    }
                }
            }
        }
        
        return minCost;
    }
    
private:
    int findCost(vector<int>& clockDigits, int startAt, int& moveCost, int& pushCost){
        int cost = 0;
        
        for(int i=0; i<clockDigits.size(); i++){
            if(clockDigits[i]!=startAt){
                cost += moveCost;
                startAt = clockDigits[i];
            }
            cost += pushCost;
        }
            
        return cost;
    }
};