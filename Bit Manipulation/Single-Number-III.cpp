// Single Number III
// https://leetcode.com/problems/single-number-iii/

// The idea in this problem is remember HOW we solved the previous problem! If we xor the array that has one unique elemnt then we get it back.
// What if we had kind of two subarrays at which they have one unqiue element. but how?

// Xoring the bigger array results in the two unique elements being xored (x^y).
// x and y differ at least in one bit(this bit has to be 1).
// Find the right most bit at which x & y differs in.
// Divide the array into two subarrays, one that has this bit is set to 1 and the other is set to 0.
// Xoring the first subarray result in the first number and xoring the second subarray results in the second number

class Solution {
public:
    vector<int> singleNumber(vector<int>& ar) {
        vector<int> res(2,0);
        
        int xors =0;
        
        for(int num:ar)
            xors^=num;
        
        int differentBit=1;
        
        while((xors & differentBit)==0)
            differentBit<<=1;
        
        int firstGroupXor=0, secondGroupXor=0;
        
        for(int num:ar){
            if(num & differentBit)
                firstGroupXor^=num;
            else
                secondGroupXor^=num;
        }
        
        res[0]=firstGroupXor, res[1]=secondGroupXor;
            
        return res;
        
    }
};