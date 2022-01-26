// https://leetcode.com/problems/count-the-hidden-sequences/

// Medium

// Tags -  Finding(Assume) the start of array(sequence), Array

// What this problem wants to teach me?
// You can start by thinking the finding the start of array(or finding the start according to the given question property)
// difference  of two numbers is independent of choosing the any element as start
// Take care of integer overflow limits 
/* for max/min function of cplus plus the both comparing values should be same type 
    here implicit conversion of int to long long or long long to int doesn't happens */
/* First solve the easier version of given problem and then introduce and think the solution for the barriers given in the question
    Like in this question first remove the low and high barriers for array element and
    now you can take any no. as start and would able to generate the sequence by the given difference array
    now introduce the low and high limits for the array numbers and then solve for it */

#include<bits/stdc++.h>
using namespace std;

// Finding(Assume) the start of array(sequence) | Time - O(N), Space - O(1)
class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long x = 0, maxi = 0, mini = 0;
        for(auto& diff : differences){
            x += (long long)diff;
            
            maxi = max(maxi,x);
            mini = min(mini, x);
        }
        
        return max(0LL, (upper-lower + 1)-(maxi-mini));
    }
};