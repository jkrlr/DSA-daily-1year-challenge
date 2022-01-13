// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

// Medium

// Tags - Array, Sorting, Greedy-Merge Intervals

#include<bits/stdc++.h>
using namespace std;

// More Concise Soln (Sorting + Greedy-Merge Intervals) | Time = O(NLogN), Space = O(LogN)-for sorting
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        sort(points.begin(), points.end());
        int arrowCnt = 1;
        int arrowPos = points[0][1];
        for(int i=1; i<points.size(); i++){
            if(points[i][0]<= arrowPos){
                arrowPos = min(arrowPos, points[i][1]);
            }
            else{
                arrowCnt +=1;
                arrowPos = points[i][1];
            }
        }
        
        return arrowCnt;
    }
};

// Sorting + Greedy-Merge Intervals | Time = O(NLogN), Space = O(LogN)-for sorting
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        sort(points.begin(), points.end());
        int result = 1;
        int prevStart = points[0][0], prevEnd = points[0][1];
        for(int i=1; i<points.size(); i++){
            if(points[i][0]<= prevEnd){
                prevStart = max(prevStart, points[i][0]);
                prevEnd = min(prevEnd, points[i][1]);
            }
            else{
                result +=1;
                prevStart = points[i][0];
                prevEnd = points[i][1];
            }
        }
        
        return result;
    }
};