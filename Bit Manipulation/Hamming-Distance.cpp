// Hamming Distance
// https://leetcode.com/problems/hamming-distance/

// bitset<32>(num).count() => returns the no. of set bits in the a 32 bit number in C++.
// bitset<32>(x^y).count();
// bitset<32>(5).to_string(); => returns the bit representation of a 32 bit number in C++.


class Solution {
public:
    int hammingDistance(int x, int y) {
        // return bitset<32>(x^y).count();
        
        int res = (x^y), cnt=0;

        while(res>0){
            cnt+=(res&1);
            res>>=1;
        }

        return cnt;
    }
};