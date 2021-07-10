// Time = O(MLogM + NLogM), Space = O(1)

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

void MinPair(vector<int> a1, vector<int> a2)
{
    // Sort a2
    sort(a2.begin(), a2.end());

    pair<int, int> p;
    int diff = INT_MAX;

    // Iterate for each element in a1 and look for closest element in the second array
    for (int num : a1)
    {
        int lb = lower_bound(a2.begin(), a2.end(), num) - a2.begin();

        // left
        if (lb >= 1 and (num - a2[lb - 1]) < diff)
        {
            diff = num - a2[lb - 1];
            p = {a2[lb - 1], num};
        }

        // Right
        if (lb != a2.size() and (a2[lb] - num) < diff)
        {
            diff = a2[lb] - num;
            p = {num, a2[lb]};
        }
    }

    cout << p.first << " , " << p.second << endl;
}

int main()
{
    vector<int> a1{-1, 5, 10, 20, 3};
    vector<int> a2{26, 134, 13515, 17};

    MinPair(a1, a2);
}