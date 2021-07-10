// https://leetcode.com/problems/magnetic-force-between-two-balls/
// Time = O(NLog(Xn-Xo))= O(NLog(Largest Diff)), Space = O(1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool CanPlaceBirds(vector<int> nests, int sep, int B)
{
    int birds = 1;
    int location = nests[0];
    for (int i = 1; i < nests.size(); i++)
    {
        int curr_location = nests[i];
        if (curr_location - location >= sep)
        {
            location = curr_location;
            birds++;
        }

        if (birds == B)
            return true;
    }

    return false;
}

int MinDistance(vector<int> nests, int B)
{
    // The nests array may not be given sorted. So, First sort the array
    // sorting
    sort(nests.begin(), nests.end());

    // Binary Search
    int n = nests.size();
    int start = 0;                     // start = min_dist =0
    int end = nests[n - 1] - nests[0]; //  end = max_dist = nests[n-1] - nests[0]
    int ans = -1;

    while (start <= end) // O(LogN)
    {
        int mid = start + (end - start) / 2;

        if (CanPlaceBirds(nests, mid, B)) // O(N) time
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> nests{1, 2, 4, 8, 9};
    int birds = 3;

    cout << MinDistance(nests, birds) << endl;
}