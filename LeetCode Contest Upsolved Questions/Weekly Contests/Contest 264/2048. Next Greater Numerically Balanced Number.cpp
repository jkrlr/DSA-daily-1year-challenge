// https://leetcode.com/problems/next-greater-numerically-balanced-number/

// Medium

// Tags - permutation - string like permutations in intergers, backtracking  

// What this problem wants to teach me?
/* If premutations possibilities are few than you can solve a problem in contest/coding test
    by manually counting all the possiblilities when your soln giving TLE for brute force and 
    you can't able to think other approach in given time slot. 
    
    All the string permutation problems can be made for integer also and hence
    these problem can be solve in similar fashion as you solve string permutation problems.

    Brute force in permutations will give TLE probably, So think some oprimizations i.e. how to prue out possibilities?*/

// Time = O(7^7) , Space = O(1)

// Since n <= 10^6, in the worst case, there are up to 7 digits, each digits must be values from [1..7], 
// so it can run up to 7^7 = 823543.

// recursion depth is 7 only and we aren't creating the any extra memory in recursion and
// output contains few no. of permutations and hasmap store only 7 digits an max freq of digit is 7 only => O(1) Space

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void validPermutations(int currLen, int NumLen, int num, unordered_map<int,int>& digitsCountOf, vector<int>& output){
        // Base Case
        if(currLen == NumLen){
            bool isBalanced = true;
            
            for(auto& it: digitsCountOf){
                int digit = it.first;
                int digitCount = it.second;
                
                if(digitCount > 0 && digitCount!=digit){
                    isBalanced = false;
                }
            }
            
            if(isBalanced){
                output.push_back(num);
            }
        }
        
        // Recursive Case
        for(int digit = 1; digit<=NumLen; ++digit){
            
            // If occurence of current digit in num is greater than equal to digit => prune
            if(digitsCountOf[digit]>=digit){
                continue;
            }
            
            // If current digit count till now + remaining positions left for current digit is less than digit
            // Then, all the occurences of current digit in num is not possible => prune
            else if (digitsCountOf[digit] + NumLen - currLen < digit){
                continue;
            }
            else{
                digitsCountOf[digit] += 1;
                validPermutations(currLen+1, NumLen, num*10+digit, digitsCountOf,output);
                
                // backtracking
                digitsCountOf[digit] -= 1;
            } 
        }
    }
    
    int nextBeautifulNumber(int n) {
        if(n==0){
            return 1;
        }
        
        // 1. Find digit's count of n i.e. length of n
        int digitsCount = log10(n) + 1;
        
        // 2. Generate all the valid permutations of length digitCount and digitCount + 1
        unordered_map<int,int> digitsCountOf;     // for storing the frequency of digit in a permutation
        vector<int> permutations;           // for storing all valid permutations
        
        for(int numLen = digitsCount; numLen<=digitsCount+1; ++numLen){ // This runs two times i.e. for digitsCount, digitsCount + 1
           int currLen = 0;
           int num = 0;
           validPermutations(currLen,numLen,num,digitsCountOf,permutations);
        }
        
        // 3. Return the first number > n in permutations
        // all the permutations are generated in sorted order
        // So, Binary search as well as linear search from begining both work
        
        // return *upper_bound(permutations.begin(), permutations.end(), n);   // Binary search
        
        // Linear Search
       for(int num: permutations){
            if(num > n){
                return num;
            }
        }
        
        return -1;
    }
};

// Another Solution by simply generating all the permutations manually
class Solution {
public:
    int nextBeautifulNumber(int n) {
//        please run this on you local for preparation.
//        vector<int> all;
//        for (int i = 0; i <= 1224444; ++i) {
//            int v = i;
//            unordered_map<int, int> m;
//            while (v > 0) {
//                ++m[v % 10];
//                v /= 10;
//            }
//            for (auto& p : m) {
//                if (p.first != p.second) goto L;
//            }
//            all.push_back(i);
//        L:
//            ;
//        }
        static vector<int> all {
            0, 1, 22, 122, 212, 221, 333, 1333, 3133, 3313, 3331, 4444, 14444, 
            22333, 23233, 23323, 23332, 32233, 32323, 32332, 33223, 33232, 
            33322, 41444, 44144, 44414, 44441, 55555, 122333, 123233, 123323,
            123332, 132233, 132323, 132332, 133223, 133232, 133322, 155555, 
            212333, 213233, 213323, 213332, 221333, 223133, 223313, 223331, 
            224444, 231233, 231323, 231332, 232133, 232313, 232331, 233123, 
            233132, 233213, 233231, 233312, 233321, 242444, 244244, 244424, 
            244442, 312233, 312323, 312332, 313223, 313232, 313322, 321233,
            321323, 321332, 322133, 322313, 322331, 323123, 323132, 323213,
            323231, 323312, 323321, 331223, 331232, 331322, 332123, 332132, 
            332213, 332231, 332312, 332321, 333122, 333212, 333221, 422444, 
            424244, 424424, 424442, 442244, 442424, 442442, 444224, 444242,
            444422, 515555, 551555, 555155, 555515, 555551, 666666, 1224444,
        };
        return *upper_bound(all.begin(), all.end(), n);
    }
};

/* How did you come up with the list: {1, 22, 122, 333, 1333, 4444, 14444, 22333, 55555, 122333, 155555, 224444, 666666};?
    
    The numbers will have x digit x times. That means:
    If length of the number is
    a). 1 => 1 (1)
    b). 2 => 2 (22)
    c). 3 => 1 + 2 (122) OR 3 (333)
    d). 4 => 1 + 3 (1333) OR 4 (4444)
    e). 5 => 1 + 4 (14444) OR 2 + 3 (22333) OR 5 (55555)
    f). 6 => 1 + 2 + 3 (122333 ) OR 1 + 5 (155555) OR 2 + 4 (224444) OR 6 (666666) */