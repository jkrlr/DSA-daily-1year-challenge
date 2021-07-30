// https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1#
// Time = O(26*n), Space = O(26)

#include <bits/stdc++.h>
using namespace std;

vector<char> FindFirstNonRepeatingCharacter(string S)
{
    unordered_map<char, int> freq;
    queue<char> q;
    vector<char> res;

    for (char ch : S)
    {
        freq[ch]++;

        if (freq[ch] == 1)
            q.push(ch);

        // remove all the chars from front of queue till you get char with freq 1
        while (!q.empty() && freq[q.front()] >= 2)
            q.pop();

        if (!q.empty())
            res.push_back(q.front());
        else
            res.push_back('0');
    }

    return res;
}