// https://leetcode.com/problems/daily-temperatures/

// Medium

// Tags - Array, Stack, Monotonic Stack

// What this problem wants to teach me?
// In which type of problems and how we can use monotonic stack for efficient searching
// That means in searching in Brute-Force we will use two loops than the inner loop can also be replaced by Monotonic stack also
// Monotonic stacks are a good option when a problem involves comparing the size of numeric elements, with their order being relevant.
// How to use ans output array iteself to optimize the space complexity by using thinking in reverse traversal of previous approach

#include<bits/stdc++.h>
using namespace std;

// Monotonic Decreasing Stack Solution | Time = O(N), Space = O(N)
// Monotonic decreasing means that the stack will always be sorted in descending order.

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(),0);
        stack<int> prevDays;
        
        for(int currDay = 0; currDay<temperatures.size(); currDay++){
            int currDayTemp = temperatures[currDay];
            
            // Pop until the current day's temperature is not
            // warmer than the temperature at the top of the stack
            
            while(!prevDays.empty() && currDayTemp > temperatures[prevDays.top()]){
                int prevDay = prevDays.top();
                prevDays.pop();
                
                result[prevDay] = currDay - prevDay;
            }
            
            prevDays.push(currDay);
        }
        
        return result;
    }
};

// Array, Optimized Space | Time = O(N), Space = O(1)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(),0);
        int hottest = 0;
        
        for(int currDay = temperatures.size()-1; currDay>=0; --currDay){
            int currDayTemp = temperatures[currDay];
            
            if(currDayTemp >= hottest){
                hottest = currDayTemp;
                continue;
            }
            
            int days = 1;
                
            while(temperatures[currDay + days] <= temperatures[currDay]){
                // Use information from answer to search for the next warmer day
                days += result[currDay + days];
            }
                
            result[currDay] = days;
        }
        
        return result;
    }
};