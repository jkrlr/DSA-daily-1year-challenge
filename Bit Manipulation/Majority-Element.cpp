// Majority Element
// https://leetcode.com/problems/majority-element/

// Time Complexity = O(n) and Space Complexity = O(n) (for storing hash maps)
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

// Time Complexity = O(n) and Space Complexity = O(1)
class Solution {
public:
    int majorityElement(vector<int>& ar) {

        int cnt=0;
        int ele;
        for(int num:ar){
            if(cnt==0){
                ele=num;
                cnt++;
            }
            else if(num==ele)
                cnt++;
            else{
                cnt--;
            }
        }
        

        return ele;
        
    }
};