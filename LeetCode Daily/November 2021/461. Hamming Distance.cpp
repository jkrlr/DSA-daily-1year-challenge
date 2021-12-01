// https://leetcode.com/problems/hamming-distance/

// Easy

// Tags - BitManipulation

// What this problem wants to teach me?
// How to find set bits in a number
// How to use inbuilt bitset<size_t> to calulate the set bits count and other we can perform other operations also
// XOR can be useful when we want to know the different or unique or occuring odd times, item/bit from  
// the collection of bits/items 

#include<bits/stdc++.h>
using namespace std;

// XoR + Count Set Bits | Time - O(32 + 32), Space - O(32)
class Solution {
public:
    int hammingDistance(int x, int y) {
        // 1. Find XoR
        int xorOfXY = x^y;

        // 2. Count set bits in xor
        int setBitsCount = 0;
        
        while(xorOfXY > 0){
            setBitsCount += (xorOfXY & 1);
            xorOfXY = xorOfXY >> 1;
        }
        
        return setBitsCount;
    }
};

// InBuit bitset<size_t> function | Time - O(32 + 32), Space O(32)- by using vector<bool> for storing a bit is set or not
class Solution {
public:
    int hammingDistance(int x, int y) {
        int xorOfXY = x^y;
        bitset<32> bitVector(xorOfXY);          // creates a vector<bool> of size 32 and fill with true/false accoring to bits of xorOfXY
        int setBitsCount = bitVector.count();   // count the set bits
        
        return setBitsCount;
    }
};