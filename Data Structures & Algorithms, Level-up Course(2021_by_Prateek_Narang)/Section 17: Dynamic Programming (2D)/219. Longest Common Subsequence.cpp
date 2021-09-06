// https://leetcode.com/problems/longest-common-subsequence/

/* In next round solve this similar problem
https://leetcode.com/problems/shortest-common-supersequence/
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Recursive - Time = O(2^n), Space = O(n) , Here n = max(s1.length(), s2.length())
int LongestCommonSubsequence(string s1, string s2, int i, int j)
{
    // base case
    if (s1[i] == '\0' || s2[j] == '\0')
    {
        return 0;
    }

    // recursive case
    int lcs;
    if (s1[i] == s2[j])
    {
        lcs = 1 + LongestCommonSubsequence(s1, s2, i + 1, j + 1);
    }
    else
    {
        int exclude_i = LongestCommonSubsequence(s1, s2, i + 1, j);
        int exclude_j = LongestCommonSubsequence(s1, s2, i, j + 1);
        lcs = max(exclude_i, exclude_j);
    }

    return lcs;
}

// Top-Down - Time = O(m*n), Space = O(m*n) , Here m = s1.length(), n = s2.length()
int LongestCommonSubsequenceTD(string s1, string s2, int i, int j, vector<vector<int>> &dp)
{
    // base case
    if (s1[i] == '\0' || s2[j] == '\0')
    {
        return 0;
    }

    // check if an state is precomputed
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int lcs;
    if (s1[i] == s2[j])
    {
        lcs = 1 + LongestCommonSubsequenceTD(s1, s2, i + 1, j + 1, dp);
    }
    else
    {
        int exclude_i = LongestCommonSubsequenceTD(s1, s2, i + 1, j, dp);
        int exclude_j = LongestCommonSubsequenceTD(s1, s2, i, j + 1, dp);
        lcs = max(exclude_i, exclude_j);
    }

    return dp[i][j] = lcs;
}

// Bottom-Up - Time = O(m*n), Space = O(m*n)
int LongestCommonSubsequenceBU(string s1, string s2)
{
    int n1 = s1.length();
    int n2 = s2.length();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            // why s1[i-1] and s2[j-1] because here indexing is 1 based
            // but string indexes starts from 0. So, i-1 and j-1 taken
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                int exclude_i = dp[i - 1][j];
                int exclude_j = dp[i][j - 1];
                dp[i][j] = max(exclude_i, exclude_j);
            }
        }
    }
    // for printing of lcs we'll do some kind of backtracking
    int i = n1, j = n2;
    vector<char> result;
    while (i != 0 && j != 0)
    {
        if (dp[i][j] == dp[i][j - 1])
        {
            j--;
        }
        else if (dp[i][j] == dp[i - 1][j])
        {
            i--;
        }
        else
        {
            result.push_back(s1[i - 1]);
            i--;
            j--;
        }
    }
    reverse(result.begin(), result.end());
    for (char ch : result)
    {
        cout << ch << ", ";
    }
    cout << endl;
    return dp[n1][n2];
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int i = 0, j = 0;
    int len1 = s1.length();
    int len2 = s2.length();
    vector<vector<int>> dp(len1, vector<int>(len2, -1));
    cout << LongestCommonSubsequence(s1, s2, i, j) << endl;
    cout << LongestCommonSubsequenceTD(s1, s2, i, j, dp) << endl;

    // see which states are visited
/*     for (int i = 0; i < len1; i++)
    {
        for (int j = 0; j < len2; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    } */

    cout << LongestCommonSubsequenceBU(s1, s2) << endl;
}
