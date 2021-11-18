// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

// Easy

// Tags - Array, Sorting, Hash Table, In-Place Modification-Algo

// What this problem wants to teach me?
/* If we want to improve the Time Complexity of Brute-Force Solution
    Then we have to think which Data Stractur we can use in 80% of the cases and 
    which Algoritm we can use in 20% of the cases  */
/*  But if we want to improve the Space Complexity of our Optimized Solution
    Then we have to think which Algorithm we can use in 80% of the case and 
    which Data structure(Majorily in this cases the input range is bound) we can use in 20% of the cases */
/*  If our Time Complexity is O(N) and Space is also O(N) and we can't use binay-search and
    we want to improve our Space Complexity, Then we can use the below Algos:
        1. Multiple Passes + some O(1) spaced Variables/ use returning output for intermediate space
        2. Multiple Passes + In-Place Modification of given Input
        3. Any Combinations of both 1&2 
        4. Sliding Window using 2-pointers
        5. Greedy Algo  + Some O(1) spaced Variables */
/*  If all the array input interges are +ve or -ve (not simultaneously both) + they are bound by some range
    Then we can use sign(In-Place Modificatio of Input) to store the information whether a number is appears or not in our input 
    The index value that doen't undergo sign-change is missing or present (depends on implementation) in input 
    As we did in our 2nd solution for this questions */

#include<bits/stdc++.h>
using namespace std;

// Counter(unordered_set) | Solution - Time = O(N), Space = O(N)
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int> s;
        for(int num: nums){
            s.insert(num);
        }
        
        vector<int> missingValues;
        for(int no=1; no<=nums.size(); no++){
            if(s.find(no)==s.end()){
                missingValues.push_back(no);
            }
        }
        
        return missingValues;
    }
};

// In-Place Modification + Multiple pass | Solution - Time = O(N), Space = O(1)
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        //1. for each value x, negate the element at xth position
        for(int i = 0; i<nums.size(); i++){
            int idx = abs(nums[i]) - 1;     // index starts from zero
            
            if(nums[idx] > 0){
                nums[idx] = -nums[idx];
            }
        }
        
        // 2. get all the positions that has a positive element. 
        //  These are the missing values to return.
        
        vector<int> missingValues;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] > 0){
                missingValues.push_back(i+1);
            }
        }

        return missingValues;
    }
};