// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
// Time = O(NlogN), Space = O(1)

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {        
        // Sort
        sort(points.begin(), points.end());
        
        int start = points[0][0], end = points[0][1];
        int cnt = 1;
        
        for(int i=1;i<points.size();i++){
            int L = points[i][0], R = points[i][1];
            
            if(R<= end){
                end = R;
            }
            else if(L > end){
                cnt++;
                start = L;
                end = R ;
            }
        }
        
        return cnt;
    }
};