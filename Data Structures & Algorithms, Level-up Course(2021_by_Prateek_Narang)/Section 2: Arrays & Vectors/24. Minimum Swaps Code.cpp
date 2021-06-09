// https://practice.geeksforgeeks.org/problems/minimum-swaps/1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countMinSwaps(vector<int> ar)
{
    int ans = 0;
    int n = ar.size();

    // Know the actual position of elements(sorting)
    // store the current indices
    pair<int, int> ap[n];

    for (int i = 0; i < n; i++)
    {
        ap[i].first = ar[i];
        ap[i].second = i;
    }

    // Sort by values
    sort(ap, ap + n);

    // build the main logic
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++)
    {
        // If the element is already visited or the element is at its correct position
        int old_pos = ap[i].second;
        if (visited[i] || old_pos == i)
            continue;

        // If the element is not visited
        // then visiting the element(index) first
        int node = i;
        int cycle = 0;
        while (!visited[node])
        {
            visited[node] = true;
            int next_node = ap[node].second;
            node = next_node;
            cycle += 1;
        }
        ans += (cycle - 1);
    }

    return ans;
}

int main()
{

    vector<int> ar{5, 4, 3, 2, 1};
    cout << countMinSwaps(ar) << endl;

    return 0;
}