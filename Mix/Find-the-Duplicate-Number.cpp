// Find the Duplicate Number
// https://leetcode.com/problems/find-the-duplicate-number/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        map<int,int> freq;
        int ans = 1;
        for(int i: nums){
            if(freq[i]==1){
                ans = i;
                break;
            }
            else{
                freq[i]=1;
            }
        }
        
        return ans;
    }
};