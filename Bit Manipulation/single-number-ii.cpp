// https://leetcode.com/problems/single-number-ii/
class Solution {
public:
    int singleNumber(vector<int>& ar) {
        int res=0;
        for(int i=0;i<32;i++){
            int cnt=0;
            for(int j=0;j<ar.size();j++){
                if(ar[j] & (1<<i))
                    cnt++;
            }
            if(cnt%3)
                res+=(1<<i);
        }  
      return res;  
    }
};