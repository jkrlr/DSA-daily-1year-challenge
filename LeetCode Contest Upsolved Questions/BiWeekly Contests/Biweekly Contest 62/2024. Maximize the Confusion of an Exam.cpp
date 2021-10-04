// https://leetcode.com/problems/maximize-the-confusion-of-an-exam/

// Sliding Window + two pointer technique + expanding and shrinking the window is used

// Idea :- Problems ask you to find maximum substring of 'T' which contains at most k 'F' or maximum substring of 'F' which contains at most k 'T'.
// I just used two seprate sliding windows for this.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxConsecutiveChars(string str, int k, char ch){
        int n = str.size();
        int left = 0, right = 0;
        int currentWindowSize = 0;
        int maxWindowSize = 0;
        int countOfOperation = 0;

        while (right < n){
            // Expand window from right 
            if(str[right] == ch){
                right++;
                currentWindowSize++;
            }
            else if(countOfOperation <= k){
                countOfOperation++;
                right++;
                currentWindowSize++;
            }

            // Compress window from left
            else {
                if(str[left] != ch){
                    countOfOperation--;
                }

                left++;
                currentWindowSize--;
            }

            if(countOfOperation<=k)
                maxWindowSize = max(maxWindowSize, currentWindowSize);
        }
        return maxWindowSize;
    }

    int maxConsecutiveAnswers(string answerKey, int k) {
        int maxT = maxConsecutiveChars(answerKey, k, 'T');
        int maxF = maxConsecutiveChars(answerKey, k, 'F');

        return max(maxT, maxF);
    }
};