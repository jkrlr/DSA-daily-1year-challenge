// https://leetcode.com/problems/minimum-absolute-difference/

// Easy

// Tags - Sorting

// What this problem wants to teach me?
// Revisit the counting sort approach

#include<bits/stdc++.h>
using namespace std;

/* Complexity Analysis

Let n be the length of the array arr.

Time complexity: O(n⋅log(n))

First, we sort arr using comparision sorting, which takes O(n⋅log(n)).
We then traverse the array, which takes O(n) time.
To sum up, the overall time complexity is O(n⋅log(n)).
Space complexity: O(n).

Some extra space is used when we sort arr in place. The space complexity of the sorting algorithm depends on the programming language.
In python, the sort method sorts a list using Timsort algorithm which has O(n) additional space where nn is the number of the elements.
In C++, the sort() function is implemented as a hybrid of Quick Sort, Heap Sort and Insertion Sort, with a worst case space complexity of O(logn).
In Java, Arrays.sort() is implemented using a variant of the Quick Sort algorithm which has a space complexity of O(logn).
In Javascript, the space complexity of sort() is O(logn).
We then traverse the array and update the output array answer as we go. 
While the output itself does not count towards the space complexity, the space used by the answer array that is not part of the output is counted. 
For example, if the array is [1,3,5,7,8], at some point, the answer array will contain n - 2 pairs, each with a difference of 2, but the output will only consist of 1 pair with a difference of 1.
 Thus, the answer array requires O(n) space.
To sum up, the overall space complexity is O(n).*/

// Sorting + Traversal | Time = O(NLogN), Space = O(N)

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        
        sort(arr.begin(), arr.end());
        
        long minDiff = LONG_MAX;
        vector<vector<int>> result;
        for(int i=1; i<arr.size(); i++){
            long currDiff = arr[i] - arr[i-1];
                        
            if(currDiff==minDiff)
                result.push_back({arr[i-1], arr[i]});
            
            else if(currDiff < minDiff){
                result.clear();
                result.push_back({arr[i-1], arr[i]});
                
                minDiff = currDiff;
            }
        }
        
        return result;
    }
};

// Count Sort + Traversal | Time = O(M+N), Space = O(M+N)

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        // Initialize the auxiliary array `line`.
        // Keep a record of the minimum element and the maximum element.
        int minElement = *min_element(arr.begin(), arr.end());
        int maxElement = *max_element(arr.begin(), arr.end());
        int shift = -minElement;
        vector<uint8_t> line(maxElement - minElement + 1);
        vector<vector<int>> answer;
        
        // For each integer `num` in `arr`, we increment line[num + shift] by 1.
        for (const int& num : arr) {
            line[num + shift] = 1;
        }
        
        // Start from the index representing the minimum integer, initialize the 
        // absolute difference `min_pair_diff` as a huge value such as
        // `max_element - min_element` in order not to miss the absolute 
        // difference of the first pair.
        int minPairDiff = maxElement - minElement;
        int prev = 0;
        
        // Iterate over the array `line` and check if line[curr] 
        // holds the occurrence of an input integer.
        for (int curr = 1; curr <= maxElement + shift; ++curr) {
            // If line[curr] == 0, meaning there is no occurrence of the integer (curr - shift) 
            // held by this index, we will move on to the next index.
            if (line[curr] == 0) {
                continue;
            }
            
            // If the difference (curr - prev) equals `minPairDiff`, we add this pair 
            // {prev - shift, curr - shift} to the answer list. Otherwise, if the difference 
            // (curr - prev) is smaller than `minPairDiff`, we empty the answer list and add 
            // the pair {curr - shift, prev - shift} to the answre list and update the `minPairDiff`
            if (curr - prev == minPairDiff) {
                answer.push_back({prev - shift, curr - shift});
            } else if (curr - prev < minPairDiff) {
                minPairDiff = curr - prev;
                answer = {{prev - shift, curr - shift}};
            }        

            // Update prev as curr.
            prev = curr;
        }
        
        return answer;
    }
};