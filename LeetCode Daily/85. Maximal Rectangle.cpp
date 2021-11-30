// https://leetcode.com/problems/maximal-rectangle/

// Hard

// Tags - Array, Monotonic Stack, Dynamic Programming

// What this problem wants to teach me?
/* For seeing the solution first see tags and then second search sol on YT and 
    if good video(i.e. video of familiar youtuber) doesn't found, Then only read text solns otherwise not => Follow it always*/
/* How to reduce the similar type problem into some earlier done standard problem*/
/* When we've to calculate the leftmost limit(bound) or rightmost limit(bound) or both leftmost and rigthmost limits(bounds) 
    for each index i in an Array. Then, in this case we can use the stack(Monotonic Stack) for decreasing the 
    time complexity from O(n^2) to O(n)(although O(n) space comes here for using stack) */
/* While copy-pasting the similar type code. Then, don't forget to change the variables names corresponding to curr solution.
   Be careful while writing the short variable names for familiar variable names. 
    Probably you will messed up while writing code in b/w full name and short names */
/* Write and understand the code as much fast as you can do(30-35 min Rule) */

#include<bits/stdc++.h>
using namespace std;

// Monotonic Stack | Time = O(m*n), Space = O(n)
class Solution {
private:
    int maxHistogram(vector<int>& heights){
        
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
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m==0) return 0;
        int n = matrix[0].size();
        
        int largestArea  = 0;
        vector<int> prevHist(n,0);
        for(int row=0; row<m; row++){
            
            //1. Calulate the histogram vector for current row
            vector<int> currHist(n);
            for(int col = 0; col<n; col++){
                if(matrix[row][col]=='1')
                    currHist[col] = 1 + prevHist[col];
                else
                    currHist[col] = 0;
            }
            
            // 2. find the max histogram area from current row histogram
            int currArea = maxHistogram(currHist);

            // 3. update largest Area
            largestArea = max(largestArea,currArea);
            
            //4. Update the prevHist vector
            for(int i=0; i<n; i++)
                prevHist[i] = currHist[i];
            
        }
        
        return largestArea;
    }
};

// Dynamic Programming | Time = O(m*n*m), Space = O(m*n)
// Complete it next visit