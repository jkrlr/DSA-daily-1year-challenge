// https://leetcode.com/problems/is-subsequence/
// Time = O(N+M), Space = O(1)

#include <iostream>
using namespace std;

bool isSubset(string str, string subStr)
{

    int strPtr = str.length() - 1;
    int subStrPtr = subStr.length() - 1;

    while (strPtr >= 0 and subStrPtr >= 0)
    {
        if (subStr[subStrPtr] == str[strPtr])
        {
            strPtr--;
            subStrPtr--;
        }
        else
            strPtr--;
    }

    return subStrPtr == -1;
}

int main()
{
    string str, subStr;
    cin >> str >> subStr;

    cout << isSubset(str, subStr) << endl;
}