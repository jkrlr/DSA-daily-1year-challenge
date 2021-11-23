// https://leetcode.com/problems/range-frequency-queries/

// Medium

// Tags - Binary Search, HashMap

// What this problem wants to teach me?
// How combination of Binary Search and HashMap can be used in RangeQueries of without point updade
// In this case value range is upto 10^4 (not upto 10^9)
// So, Instead of thinking about segment tree -> We can use HasMap here and store the indicies of value in vector
// Then, Apply Binary Serach that will solve the problem easily 
// When the input range is in the range of 0 to maxSize of Array, Then-> HashMap will not result in TLE at all

#include<bits/stdc++.h>
using namespace std;

// Time : RangeFreqQuery: O(N), where N is the number of elements in arr. 
//        query: O(logN)
// Space: O(N), required for maintaining hashmap


// Binary Seach + Hasmap + Vector of Index
class RangeFreqQuery {
private:
    unordered_map<int,vector<int>> indiciesOf;
public:
    RangeFreqQuery(vector<int>& arr) {
        for(int i=0; i<arr.size(); i++){
            indiciesOf[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        
        // 1. check if the key is present in input or not
        if(indiciesOf.find(value)==indiciesOf.end()){
            return 0;
        }
        
        // 2. count frquency of value with the help idiciesOf[value] vector 
        
        int lb = lower_bound(indiciesOf[value].begin(), indiciesOf[value].end(), left) - indiciesOf[value].begin();
        int ub = upper_bound(indiciesOf[value].begin(), indiciesOf[value].end(), right) - indiciesOf[value].begin();
        
        return (ub - lb);
    }
};