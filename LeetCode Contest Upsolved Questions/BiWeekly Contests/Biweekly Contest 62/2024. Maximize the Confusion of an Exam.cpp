// https://leetcode.com/problems/maximize-the-confusion-of-an-exam/

// Sliding Window + two pointer technique + expanding and shrinking the window is used

// Idea :- Problems ask you to find maximum substring of 'T' which contains at most k 'F' or maximum substring of 'F' which contains at most k 'T'.
// I just used two seprate sliding windows for this.

// Time = O(N), Space = O(1)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxConsecutiveChars(string str, int k, char ch){
        int n = str.size();
        int left = 0, right = 0;
        int maxWindowSize = 0;
        int countOfOperation = 0;

        while (right < n){

            // process the current character
            if(str[right]==ch){
                countOfOperation++;
            }

            // Compress window from left
            while(countOfOperation > k){
                if(str[left]==ch){
                    countOfOperation--;
                }
                left++;
            }

            int currentWindowSize = right - left + 1;
            maxWindowSize = max(maxWindowSize, currentWindowSize);

            // Expand window from right
            right++;
        }

        return maxWindowSize;
    }

    int maxConsecutiveAnswers(string answerKey, int k) {
        int maxT = maxConsecutiveChars(answerKey, k, 'F');
        int maxF = maxConsecutiveChars(answerKey, k, 'T');   

        return max(maxT, maxF);
    }
};