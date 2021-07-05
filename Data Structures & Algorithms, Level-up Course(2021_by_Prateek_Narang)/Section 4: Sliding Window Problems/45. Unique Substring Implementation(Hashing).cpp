// https://leetcode.com/problems/longest-substring-without-repeating-characters/

// Time = O(n), Space=O(1)

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string unique_substring(string str)
{
    int L = 0, R = 0;
    int window_size = 0, max_window_size = 0, window_start = -1;
    unordered_map<char, int> m;

    while (R < str.length())
    {
        char ch = str[R];

        // If it  is inside hashmap & its idx >= start of this current window
        if (m.count(ch) > 0 and m[ch] >= L)
        {
            L = m[ch] + 1;
            window_size = R - L; // Updating remaining window len using current char // (R-1) - (L-1) = R-L
        }

        // Update the last occurence
        m[ch] = R;
        window_size++;
        R++;

        // update max_window_size at every step
        if (window_size > max_window_size)
        {
            window_start = L;
            max_window_size = window_size;
        }
    }

    return str.substr(window_start, max_window_size);
}

int main()
{

    string str;
    cin >> str;

    cout << unique_substring(str) << endl;
}

/*
    A bit tricky implementation.
    While doing such type of problems => Please Do Dry Run.
    You have to think different possibilities.
    
    Learning => Breaking the problems into two simple cases
             => It will easy the implementaion part
*/