// https://leetcode.com/problems/merge-intervals/

// Medium

// Tags - Array, Sorting

#include<bits/stdc++.h>
using namespace std;

// Sorting | Time = O(NLogN), Space = O(LogN)-for sorting
bool compare(vector<int>&a, vector<int>&b){
    if(a[0] == b[0])
        return a[1] < b[1];
    
    return a[0] < b[0];
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mergedIntervals;
        
        sort(intervals.begin(), intervals.end(), compare);
        for(int i=0; i<intervals.size(); i++){
            cout<<intervals[i][0] <<" "<<intervals[i][1]<<endl;
        }
        
        int prevStart = intervals[0][0], prevEnd = intervals[0][1];
        for(int i=1; i<intervals.size(); i++){
            int nextStart = intervals[i][0], nextEnd = intervals[i][1];
            
            if(nextStart <= prevEnd){
                prevStart = min(prevStart, nextStart);
                prevEnd = max(prevEnd, nextEnd);
            }
            else{
                mergedIntervals.push_back({prevStart, prevEnd});
                prevStart = nextStart;
                prevEnd = nextEnd;
            }
        }
        
        mergedIntervals.push_back({prevStart, prevEnd});
        
        return mergedIntervals;
    }
};