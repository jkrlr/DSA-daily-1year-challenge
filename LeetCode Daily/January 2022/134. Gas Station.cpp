// https://leetcode.com/problems/gas-station/

// Medium

// Tags - Greedy, Array

// What this problem wants to teach me?
// If you're able to identify that a problem is solved by greedy technique.'
// then it's implementation will be tricky in most of the cases

#include<bits/stdc++.h>
using namespace std;

// Greedy - Very Tricky Sol | Time - O(N), Space = O(1)
// Don't need to check from the last index to begin and then start part
// becoz sol is unique

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        if(accumulate(begin(gas), end(gas), 0) < accumulate(begin(cost), end(cost),0))
            return -1;
        
        int startIndex = 0;
        int total = 0;
        for(int i=0;i<gas.size(); i++){
            total += gas[i] - cost[i];
            if(total < 0){
                startIndex = i+1;
                total = 0;
            }
        }
        
        return startIndex;
    }
};

// Optimized-Brute Force(Greedy) | Time = O(2*N), Space = O(1)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost){
        int N = gas.size();
        int startIndex = 0;
        while(startIndex < N){
            if(gas[startIndex] - cost[startIndex] < 0){
                startIndex++;
                continue;
            }

            int gasLeft = gas[startIndex] - cost[startIndex];
            int nextIndex = (startIndex + 1 + N) % N;
            while(gasLeft + gas[nextIndex] - cost[nextIndex] >=0){
                if(nextIndex == startIndex)
                    return startIndex;

                gasLeft = gasLeft + gas[nextIndex] - cost[nextIndex];
                nextIndex = (nextIndex + 1 + N) % N;
            }
            if(nextIndex < startIndex)
                return -1;
            startIndex = nextIndex;
        }
        return -1;
    }
};