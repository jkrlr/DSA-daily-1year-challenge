// https://leetcode.com/problems/single-number-iii/

// Medium

// Tags - Bit Manipulation

// What this problem wants to teach me?

#include<bits/stdc++.h>
using namespace std;

//Time - O(N), Space - O(1)

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long int aXorb = 0;
        
        //Calculate xor of every number so that aXorb will have (a^b)
        for(int num: nums){
            aXorb ^= num;
        }

        // Compute rightmost set bit of aXorb, gives us the ith bit we need as a rightMostSetBit
        int rightMostSetBit = aXorb & (-aXorb);

        int intA = 0, intB = 0;
        for(int num: nums){
            // based on the rightMost bit, group the items into groupA(include a) and groupB
            if(num & rightMostSetBit){
                intA^=num;
            }
            else{
                intB^=num;
            }
        }
        
        return vector<int>{intA,intB};
    }
};