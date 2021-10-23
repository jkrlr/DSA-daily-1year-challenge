// https://leetcode.com/problems/minimum-window-substring/

// Time = O(n+m), Space=O(1)

#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

string stringWindow(string str, string pattern)
{
    //Array as a Freq Map or you can use hasmap
    int FP[256] = {0};
    int FS[256] = {0};

    for (int i = 0; i < pattern.length(); i++)
        FP[pattern[i]]++;

    // Sliding Window Algorithm
    int cnt = 0;
    int start = 0;            // left contraction
    int start_idx = -1;       // start_idx for best window
    int min_so_far = INT_MAX; // large number
    int window_size;

    for (int i = 0; i < str.length(); i++)
    {
        //expand the window by including current character
        char ch = str[i];
        FS[ch]++;

        // Count how many characters have been matched till now (str and pattern)
        if (FP[ch] != 0 and FS[ch] <= FP[ch])
            cnt += 1;

        // another thing
        // if all character of the pattern found in the current window then you can start contracting
        if (cnt == pattern.length())
        {

            // start contracting from the left to remove unwanted character
            // Unwanted character => 1. Not present in pattern,  2. Freq is higher than required

            while (FP[str[start]] == 0 or FS[str[start]] > FP[str[start]])
            {
                FS[str[start]]--;
                start++;
            }

            //note. the window size
            window_size = i - start + 1;

            if (window_size < min_so_far)
            {
                min_so_far = window_size;
                start_idx = start;
            }
        }
    }

    if (start_idx == -1)
        return "No window found!";
    return str.substr(start_idx, min_so_far);
}

int main()
{
    string str, pattern;
    cin >> str >> pattern;

    cout << stringWindow(str, pattern) << endl;
}