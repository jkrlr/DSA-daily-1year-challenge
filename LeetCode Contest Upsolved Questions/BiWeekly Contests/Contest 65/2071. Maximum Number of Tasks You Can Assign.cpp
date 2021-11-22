// https://leetcode.com/problems/maximum-number-of-tasks-you-can-assign/

// Hard

// Tags - Array, Binary Search (Monotonic Seach Space Concept), Greedy, Sorting

// What this problem wants to teach me?
/* How to use multisets => We can also use Multisets in place of Priority Queue
    Multisets are useful when you have duplicates but you want all of them + increasing/decreasing order to be maintained in deletion/insertion */
/* In Monotonic Binary Search isValid() codition check function can be look complicated to implement
    But choosing appropriate Data Structure of STL for your thought process to implement,
    Can simplify the implementaions by following what you actually trying to do, by using example test cases */
/* Greedy sol will work or not If you can't prove it Then you can confirm it by proving  working it to all the edge cases*/

#include<bits/stdc++.h>
using namespace std;

// Binary Search + Greedy | Time = O(Log(min(m,n))*m*Log(m)), Space = O(m) - for multiset of wokers
class Solution {
public:
    bool canBeAssigned(vector<int>& tasks, vector<int>& workers, int pills, int strength, int k) {
            
        // Insert all the workers into multiset, so that order always remains increasing
        multiset<int> s(workers.begin(), workers.end());    // Time = O(m*log(m)), but for sorted array, it will be O(m) also
        
        // Checking if the k(i.e. mid) smallest tasks can be assigned
        for(int i = k-1; i>=0; --i){
            
            // Case 1: Trying to a assign task to a worker without the pill
            auto it = prev(s.end());    // This is same as: auto it = --s.end();
            if(*it >= tasks[i]){
                
                // Case 1 satisfied!
                s.erase(it);
            }
            else{
                
                // Case 2: Trying to assign to a worker with the pill
                it = s.lower_bound(tasks[i]-strength);
                if(it!=s.end()){
                    
                    // Case 2 satisfied
                    s.erase(it);
                    --pills;
                }
                
                // Case 3: Impossible to assign K(mid) tasks
                else{
                    return false;
                }
            }

            // If at any moment, the number of pills require for k(mid) tasks exceeds 
            // the allotted number of pills, we stop the loop
            if(pills < 0){
                return false;
            }
        }
        
        return true;
    }
    
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        
        sort(tasks.begin(),tasks.end());
        sort(workers.begin(), workers.end());
        
        int m = tasks.size();
        int n = workers.size();
        
        int lo = 0;
        int hi = min(m,n);
        int ans = -1;
        
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            
            if(canBeAssigned(tasks,workers,pills,strength,mid)){
                ans = mid;
                lo =  mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        
        return ans;
    }
};