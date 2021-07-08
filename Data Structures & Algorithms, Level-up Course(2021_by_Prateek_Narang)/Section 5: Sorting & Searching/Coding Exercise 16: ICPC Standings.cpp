// Time : Greedy => O(N) and Space = O(N) using Hashmap

// Sorting : Time = O(NLogN)

#include <bits/stdc++.h>
using namespace std;

int badness(vector<pair<string, int>> teams)
{

    unordered_map<int, int> m;

    for (auto p : teams)
    {
        m[p.second]++;
    }

    int BadnessSum = 0;
    int Position = 1;
    for (int rank = 1; rank <= teams.size(); rank++)
    {
        while (m[rank] > 0)
        {
            BadnessSum += abs(Position - rank);
            Position++;
            m[rank] = m[rank] - 1;
        }
    }

    return BadnessSum;
}