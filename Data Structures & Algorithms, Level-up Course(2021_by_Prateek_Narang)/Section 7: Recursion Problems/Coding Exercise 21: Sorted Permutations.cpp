// https://leetcode.com/problems/permutations/
// Time = O(n^2 * n!) , Space =(n) => depth of recursion

/* Calling SortedPermutationsHelper O(n * n!) times (as an upper bound) and each call takes O(n) time for string concatenation, 
    the total runtime will not exceed O(n^2 * n!). */

#include <bits/stdc++.h>
using namespace std;

set<string> st;

void SortedPermutationsHelper(string s, string output, int start)
{
    // Base Case
    if (start == s.length()) // s[start]=='\0'
    {
        st.insert(output);
        return;
    }

    // Recursive Case
    for (int idx = start; idx < s.size(); idx++)
    {
        swap(s[start], s[idx]);
        SortedPermutationsHelper(s, output + s[start], start + 1);
        swap(s[start], s[idx]);
    }
}

vector<string> findSortedPermutations(string s)
{
    //Your code goes here. Do not change the function or parameters. You can use helper functions if needed.
    st.clear();
    string output;
    SortedPermutationsHelper(s, output, 0);

    vector<string> res;

    for (auto &str : st)
    {
        res.push_back(str);
    }

    return res;
}

int main()
{
    string input;
    cin >> input;

    vector<string> res = findSortedPermutations(input);
    for (auto str : res)
        cout << str << " ";
}