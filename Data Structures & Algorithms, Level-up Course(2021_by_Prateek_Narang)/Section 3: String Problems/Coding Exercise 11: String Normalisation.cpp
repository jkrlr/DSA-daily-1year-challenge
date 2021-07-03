// https://leetcode.com/problems/detect-capital/
// Time = O(N), Space = O(1)

#include <bits/stdc++.h>
using namespace std;

string normalize(const string &sentence)
{
    string copy = sentence;
    //Make the changes in copy, and return it

    int n = copy.length();

    // Empty String
    if (n < 1)
        return copy;

    if (copy[0] >= 'a' && copy[0] <= 'z')
        copy[0] -= 32; // Make uppercase first letter, If it is an alphabet

    for (int i = 1; i < n; i++)
    {
        // Check for space => Begin of new word
        if (copy[i - 1] == ' ')
        {
            if (copy[i] >= 'a' && copy[i] <= 'z')
                copy[i] -= 32; // Capitalize first alphabet letter of Word
        }

        // If letter of word is uppercase alphabet make it lowercase
        else if (copy[i] >= 'A' && copy[i] <= 'Z')
            copy[i] += 32;
    }

    return copy;
}

// Traverse from i = 1->n-1:
//     if str[i]==32: // space
//          if str[i] >='a'
//                 str[i]-=32
//     else
//           if str[i]<'a'
//                  str[i] +=32