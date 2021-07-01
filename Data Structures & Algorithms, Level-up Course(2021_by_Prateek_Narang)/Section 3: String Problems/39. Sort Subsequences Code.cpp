// https://leetcode.com/problems/subsets/
// Time = O(2^N), Space = O(2^N)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// sorted subsequences
void subsequences(string s, string o, vector<string> &v)
{
    // Base Case
    if (s.length() == 0)
    {
        v.push_back(o);
        return;
    }

    // Recursive Case
    char ch = s[0];
    string reduced_input = s.substr(1);

    // include
    subsequences(reduced_input, o + ch, v);

    //exclude
    subsequences(reduced_input, o, v);
}

bool comp(string s1, string s2)
{
    if (s1.length() == s2.length())
        return s1 < s2;
    else
        return s1.length() < s2.length();
}

int main()
{
    string str;
    cin >> str;
    vector<string> v;
    string output = "";
    subsequences(str, output, v);

    sort(v.begin(), v.end(), comp);

    for (string s : v)
        cout << s << ", ";
}