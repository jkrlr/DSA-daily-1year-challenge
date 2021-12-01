// https://leetcode.com/problems/interval-list-intersections/

// Medium

// Tags - Array, Two-Pointer, Merge-Interval

// What this problem wants to teach me?
// In Merge InterVal Problems, If the Intervals are not given sorted
// Then, In First Step Sort the interval array
// Then, In Second Step make cases by drawing interval lines on pen and paper (very Imp. step)
// Then, In Third Step code the apporach by using Two-Pointer approach + according to given constraints + what is asked

#include<bits/stdc++.h>
using namespace std;

// Two-Pointer | Time - O(M+N), Space - O(1)
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> result;
        
        int firstIdx = 0, secondIdx = 0;
        
        while(firstIdx<firstList.size() && secondIdx<secondList.size()){
            int start1 = firstList[firstIdx][0], end1 = firstList[firstIdx][1];
            int start2 = secondList[secondIdx][0], end2 = secondList[secondIdx][1];
            
            if(start1<=end2 && start2<=end1){
                int mergeStart = max(start1,start2);
                int mergeEnd = min(end1,end2);
                
                result.push_back(vector<int>{mergeStart,mergeEnd});
            }
            
            if(end1 < end2){
                firstIdx++;
            }
            else{
                secondIdx++;
            }
        }
        
        return result;
    }
};