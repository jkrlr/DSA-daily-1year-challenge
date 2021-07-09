#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int LeftMostOccurence(vector<int> arr, int key)
{
    int ans = -1;

    int lo = 0;
    int hi = arr.size() - 1;

    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;

        if (arr[mid] == key)
        {
            ans = mid;
            hi = mid - 1;
        }
        else if (arr[mid] > key)
        {
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }

    return ans;
}

int RightMostOccurence(vector<int> arr, int key)
{
    int ans = -1;

    int lo = 0;
    int hi = arr.size() - 1;

    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;

        if (arr[mid] == key)
        {
            ans = mid;
            lo = mid + 1;
        }
        else if (arr[mid] > key)
        {
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }

    return ans;
}

int FrequencyCount(vector<int> arr, int key)
{
    int Lo = LeftMostOccurence(arr, key);

    if (Lo == -1) // key not found
        return -1;

    int Ro = RightMostOccurence(arr, key);

    return Ro - Lo + 1;
}

int main()
{
    vector<int> arr{0, 1, 1, 1, 1, 2, 2, 2, 3, 4, 4, 5, 10};
    int key;
    cin >> key;

    cout << FrequencyCount(arr, key) << endl;

    // STL  - In Online Round because you haven't time then use STL
    cout << upper_bound(arr.begin(), arr.end(), key) - lower_bound(arr.begin(), arr.end(), key) << endl;

    /*cout<<(upper_bound(arr.begin(), arr.end(), key) - arr.begin())<<endl;
    cout<<lower_bound(arr.begin(), arr.end(), key) - arr.begin()<<endl;    */
}
