// Total Hamming Distance
// https://leetcode.com/problems/total-hamming-distance/

class Solution {
public:
    int totalHammingDistance(vector<int>& ar) {
        
        int cnt=0;
        int n = ar.size();
        int ZeroOne[2];
        
        for(int i=0;i<32;i++){
            ZeroOne[0]=0;
            ZeroOne[1]=0;
            
            for(int j=0;j<n;j++){
                ZeroOne[ar[j]%2]++;
                // ZeroOne[(ar[j] & 1)]++;
                ar[j]>>=1;
            }
            cnt+=(ZeroOne[0]*ZeroOne[1]);
        }
        
        return cnt;
    }
};

    
