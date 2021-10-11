// https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/

// Medium

// What this problem wants to teach me?

/*  Hint 1- Is it possible to make two integers a and b equal if they have different remainders dividing by x? Ans - No
    
    Hint 2- If it is possible, which number should you select to minimize the number of operations? Ans - Median
    
    Hint 3- What if the elements are sorted? Ans - median is mid element in this case

    How to check if one number can be made equal to another number by adding or substracting some integer x?
    
    Why median gives the minimum moves to make array equal? */

/* Constraints:
    m == grid.length
    n == grid[i].length
    1 <= m, n <= 10^5
    1 <= m * n <= 10^5
    1 <= x, grid[i][j] <= 10^4          */ 

// Solution - Time = O(m*n*log(m*n)) , Space = O(m*n)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
       int  m = grid.size();
       int  n = grid[0].size();
        
        vector<int> ar(m*n);
        int k = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                ar[k++] = grid[i][j];
            }
        }
        
        sort(ar.begin(), ar.end());

        int mid = m*n/2;
        int target =ar[mid]; // target is median here 
        
        int cnt = 0;

        for(auto n: ar){
            int diff = abs(target - n);
            
            if(diff % x != 0){
                return -1;    
            }
            else{
                cnt += diff/x;    
            }
        }
        
        return cnt;
    }
};