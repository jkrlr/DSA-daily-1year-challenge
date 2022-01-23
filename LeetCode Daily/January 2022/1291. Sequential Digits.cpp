// https://leetcode.com/problems/sequential-digits/

// Medium

// Tags - Enumeration

// What this problem wants to teach me?
// If input is small and it is possible to do enumerations by manual calculations , may do it manually also
// Else you can think the choosing the subsequence of particular size in given input by converting the inputs into string
// it can be done by using 2 for loops

#include<bits/stdc++.h>
using namespace std;

// Brute Force - Enumeration | Time = O(1), Space = O(1)
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res = {12, 23, 34, 45, 56, 67, 78, 89,
                          123, 234, 345, 456,567, 678, 789,
                          1234, 2345, 3456, 4567, 5678, 6789,
                          12345, 23456, 34567, 45678, 56789,
                          123456, 234567, 345678, 456789,
                          1234567, 2345678, 3456789,
                          12345678, 23456789,
                          123456789};
        
        vector<int> ans;
        for(int& num: res){
            if(num>=low && num<=high)
                ans.push_back(num);
        }
        
        return ans;
    }
};

// Enumeration-Generating all the substrings in a particular size window | Time = O(1), Space = O(1)
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string digits = "123456789";
        int nl = to_string(low).length();
        int nh = to_string(high).length();
        
        vector<int> result;
        
        for(int i=nl; i<=nh; i++){          // i is the window size
            for(int j = 0; j<10-i; j++){    // j is the begining of substring window
                int num = stoi(digits.substr(j,i));
                
                if(num>=low && num<=high)
                    result.push_back(num);
            }
        }
        return result;
    }
};

// Enumeration - In digits | Time = O(1), Space = O(1)
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;
        
        for(int i=1; i<=9; i++){
            int num = i;
            for(int j = i+1; j<=9; j++){
                num = num*10 + j;
                if(num>=low && num<=high)
                    result.push_back(num);
            }
        }
        
        sort(begin(result), end(result));
        
        return result;
    }
};