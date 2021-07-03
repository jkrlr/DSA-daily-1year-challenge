// https://leetcode.com/problems/string-compression/

// Time = O(N^2), Space = O(1)

#include <bits/stdc++.h>
using namespace std;

//str is the input the string
string compressString(const string &str)
{
    string res = "";

    int cnt = 0;
    char ch = str[0];
    for (int i = 0; i < str.length(); i++)
    {
        // count the freq of char
        while (ch == str[i] && i < str.length())
        {
            cnt++;
            i++;
        }

        // Append the char+ freqofChar into res
        res += (ch + to_string(cnt)); // O(n)

        // Reset the values
        ch = str[i];
        cnt = 0;
        i--;
    }

    return res.length() < str.length() ? res : str;
}