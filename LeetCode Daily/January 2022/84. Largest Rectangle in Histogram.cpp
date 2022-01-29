// https://leetcode.com/problems/largest-rectangle-in-histogram/

// Hard

// Tags - Monotonic Stack

#include<bits/stdc++.h>
using namespace std;

// Monotonic Stack | Time - O(3N), Space - O(3N)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // For finding the maximum histogram area
        // The key observation is atleast one bar is fully included in area
        int n = heights.size();
               
        //1. Calculate Left and Right limits for each Bar i
        vector<int>left(n), right(n);
        stack<int>s;
        
        // Left limits
        for(int i=0; i<n; i++){
            while(!s.empty() && heights[i] <= heights[s.top()])
                s.pop();
            
            if(s.empty())   
                left[i] = 0;
            else
                left[i] = s.top() + 1;
            
            s.push(i);
        }
        
        // Clear the stack 
        while(!s.empty())
            s.pop();
        
        // Right limits
        for(int i=n-1; i>=0; i--){
            while(!s.empty() && heights[i] <= heights[s.top()])
                s.pop();
            
            if(s.empty())   
                right[i] = n-1;
            else
                right[i] = s.top() - 1;
            
            s.push(i);
        }
        
        // 2. Calculate the Area of Histogram including the ith bar as full bar and find max
        int largest = 0; 
        for(int i=0; i<n;  i++){
            
            int width = right[i]-left[i] + 1;
            int height = heights[i];
            int currArea = width*height;

            largest = max(largest,currArea);
        }
        
        return largest;        
    }
};