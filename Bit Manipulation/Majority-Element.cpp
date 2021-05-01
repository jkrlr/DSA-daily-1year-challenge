// Majority Element
// https://leetcode.com/problems/majority-element/

class Solution {
public:
    int majorityElement(vector<int>& ar) {
        map<int, int> freq;

        for(int ele:ar){
            if(freq[ele]>=1)
                freq[ele]++;
            else
                freq[ele] = 1;
        }
        int ans = 0, n=ar.size();

        for (auto i : freq)
        {
            if(i.second > floor(n/2)){
                ans = i.first;
                break;     
            }
        }

        return ans;
        
    }
};