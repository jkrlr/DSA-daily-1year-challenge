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

    // Traverse from R->Mid:
    //     if the 1st last no. which is smaller than b replace it with b
    for (int i = n - 1; i >= mid; i--)
    {
        if (palindrome[i] < 'b')
        {
            palindrome[i] = 'b';
            return palindrome;
        }
    }

    // Already Given string is Not Palindrome
    return palindrome;
}