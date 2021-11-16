// https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/

// Hard

// Tags - Binary Search

// What this problem wants to teach me?
// When finding kth smallest/largest element solution, Is heap sol will give TLE
// Then, You can think Binary search using monotonic search space
// And try to figure out some observation from question, such that you will know 
// what should we check in isValid() condition in BS to accept/reject a value as answer such that condition will fit in constraints as well.

#include<bits/stdc++.h>
using namespace std;

// Binary Search | Time - O(m*Log(m*n)), Space - O(1)

/* Intuition
    As k and m*n are up to 9 * 10^8, linear solutions will not work. 
    This motivates solutions with logarithmic complexity, such as binary search. */

class Solution {
public:
    /* In each row, the numbers we get, are of the form - [i, 2*i, 3*i,...,k*i,...n*i]. 
    Using this observation, we can iterate over each row and count number of elements-N in that row that are less than or equal to mid.*/
    
	// counts number of integers less than or equal to mid in multiplication table
    bool isKSmallerPossible(int m, int n, int k, int mid){
        int cnt = 0;
        
        for(int i=1; i<=m; i++){
            cnt += min(mid/i, n);
        }
        
        return cnt >= k;
    }

    // Time = O(m*log(m*n)), Space = O(1)
    int findKthNumber(int m, int n, int k) {
        int lo = 1;
        int hi = m*n;
        int ans = -1;
        
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            
            if(isKSmallerPossible(m,n,k,mid)){
                ans = mid;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        
        return ans;
    }
};