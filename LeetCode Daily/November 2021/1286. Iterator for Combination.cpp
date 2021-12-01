// https://leetcode.com/problems/iterator-for-combination/

// Medium

// Tags - String, Bit-Manipulation, Recursion, BaclTracking, Design

// What this problem wants to teach me?

#include<bits/stdc++.h>
using namespace std;

// Recursion + BackTracling | Time - O(2^N), Space - O(N)
void permutations(string str, int k, int idx, set<string>& result, string output){
    // base case
    if(output.length()==k){
        result.insert(output);
        return;
    }
    
    if(idx==str.length()){
        return;
    }
    
    // recursive case
    char ch = str[idx];
    
    //include
    permutations(str, k, idx+1, result, output+ch);
    
    // exclude
    permutations(str, k, idx+1, result, output);
}

class CombinationIterator {
public:
    vector<string> combinations;
    int idx = 0;
    
    // O(2^N) Time
    CombinationIterator(string characters, int combinationLength) {
        string output;
        set<string> result;
        permutations(characters, combinationLength, 0, result, output);
        
        for(auto& s: result){
            combinations.push_back(s);
        }
    }
    
    // O(1) Time
    string next() {
        return combinations[idx++];
    }
    
    // O(1) Time
    bool hasNext() {    
        if(idx >= combinations.size()){
            return false;
        }
        
        return true;
    }
};


// BitManipulation | Time - O(2^N), Space - O(N)
void permutations(string str, int k, vector<string>& result){
    int n = (1<<str.length());
    
    set<string> temp;
    
    for(int mask = 0; mask<n; ++mask){
        string output;
        
        for(int i=0; i<str.length(); ++i){
            int flag = 1<<i;
            
            if(mask&flag){
                output += str[i];
            }
            
            if(output.length()==k){
                temp.insert(output);
                break;
            }
        }
    }
    
    for(auto& s: temp){
        result.push_back(s);
    }
}

class CombinationIterator {
public:
    vector<string> combinations;
    int idx = 0;
    
    CombinationIterator(string characters, int combinationLength) {
        permutations(characters, combinationLength, combinations);
    }
    
    string next() {
        return combinations[idx++];
    }
    
    bool hasNext() {
        if(idx >= combinations.size()){
            return false;
        }
        
        return true;
    }
};