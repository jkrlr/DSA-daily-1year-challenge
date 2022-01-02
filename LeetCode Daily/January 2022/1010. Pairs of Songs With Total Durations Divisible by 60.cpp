// https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/

// Medium

// Tags - HashTable, Array, Counting

#include<bits/stdc++.h>
using namespace std;

// Counting + Modulo Arithmetic | Time = O(N + divisor), Space = O(divisor)
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        const int divisor = 60;
        vector<int> rem(divisor,0);
        
        for(auto& t: time){
            rem[t%divisor]++;
        }
        
        int count = 0;
        count += (rem[0]*(rem[0]-1))/2;
        count += (rem[divisor/2]*(rem[divisor/2]-1))/2;
        
        for(int i=1; i<divisor/2; i++){
            count += (rem[i]*rem[divisor - i]);
        }  
        return count;
    }
};

// unordered_map + Modulo Arithmetic | Time = O(N + divisor), Space = O(divisor)
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        const int divisor = 60;
        unordered_map<int,int> mp;
        
        for(auto& t: time){
            mp[t%divisor]++;
        }
        
        int count = 0;
        
        for(auto& it: mp){
            if(it.first==0 || it.first==divisor/2)
                count += (it.second * (it.second-1))/2;
            else if(it.first < divisor/2 && mp.count(divisor - it.first) > 0)
                count += (it.second)*mp[divisor - it.first];
        }
        return count;
    }
};
