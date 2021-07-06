#include <bits/stdc++.h>
using namespace std;

string smallestWindow(string str)
{

    /* First cnt distinct chars in str
       traverse the str L -> R => until all char are present in window
       if present then start contract from left , until all chars are present       
    */

    unordered_set<char> s;
    for (char ch : str)
    {
        s.insert(ch);
    }

    unordered_map<char, int> Freq;
    int start_idx = -1;
    int window_len = 0;
    int min_window_len = INT_MAX;

    int end = 0;
    int start = 0;
    int cnt = 0;

    // Sliding window Algorithm
    while (end < str.length())
    {

        // Process current character => Expand Window
        char ch = str[end];
        Freq[ch]++;
        end++;

        // count no. of req. characters
        if (s.find(ch) != s.end() and Freq[ch] <= 1)
            cnt += 1;

        // Contract window
        if (cnt == s.size())
        {

            while (s.find(str[start]) == s.end() or Freq[str[start]] > 1)
            {
                Freq[str[start]]--;
                start++;
            }

            window_len = end - start;

            if (min_window_len > window_len)
            {
                min_window_len = window_len;
                start_idx = start;
            }
        }
    }

    if (start_idx == -1)
        return "";

    return str.substr(start_idx, min_window_len);
}