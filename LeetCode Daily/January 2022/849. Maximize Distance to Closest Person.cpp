// https://leetcode.com/problems/maximize-distance-to-closest-person/

// Medium

// Tags - Array-Linear Traversal

// What this problem wants to teach me?

#include<bits/stdc++.h>
using namespace std;

// Array-Linear Traversal-GroupByZero - Cleaner Code | Time - O(N), Space - O(1)
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int firstNonEmptyPos = -1, lastNonEmptyPos = -1;
        int consecutiveEmptyCnt = 0;
        int result = 0;
        
        for(int i=0; i<n; i++){
            if(seats[i]==1){
                if(firstNonEmptyPos == -1)
                    firstNonEmptyPos = i;
                
                lastNonEmptyPos = i;
                consecutiveEmptyCnt = 0;
            }
            else{
                consecutiveEmptyCnt++;
                result = max(result, (consecutiveEmptyCnt+1)/2);
            }
        }
        
        result = max({result, firstNonEmptyPos, n-1-lastNonEmptyPos});
        
        return result;
    }
};

// Array-Linear Traversal-GroupByZero | Time - O(N), Space - O(1)
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int maxDist = 0;
        int start = 0;
        if(seats[0]==0){
            while(start < seats.size() && seats[start]==0)
                start++;
            
            maxDist = start;
        }
        
        int end = n-1;
        if(seats[end]==0){
            while(end>=0 && seats[end]==0)
                end--;
            maxDist = max(maxDist, n-1-end);
        }
        
        int lo = start;
        for(int idx = start + 1; idx<=end; idx++){
            if(seats[idx]==1){
                maxDist = max(maxDist, (idx-lo)/2);
                lo = idx;
            }
        }
        
        return maxDist;
    }
};
