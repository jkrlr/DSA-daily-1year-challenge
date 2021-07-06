// https://leetcode.com/problems/break-a-palindrome/
// Time = O(N) , Space = O(1)

#include <bits/stdc++.h>

std::string breakPalindrome(std::string palindrome)
{
    int n = palindrome.length();

    // Not possible
    if (n <= 1)
        return "";

    int mid = n / 2;

    // Traverse from L->Mid-1:
    //     if 1st Letter greater than a replace it with a
    for (int i = 0; i < mid; i++)
    {
        if (palindrome[i] > 'a')
        {
            palindrome[i] = 'a';
            return palindrome;
        }
    }

    palindrome[n - 1] = 'b'; //if all 'a'

    // Already Given string is Not Palindrome
    return "The given string is not Palindrome!";
}