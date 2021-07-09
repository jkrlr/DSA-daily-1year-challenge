// https://leetcode.com/problems/search-in-rotated-sorted-array/

// Time = O(Log2(N)), Space = O(1)

#include <iostream>
#include <vector>
using namespace std;

int RotatedSearch(vector<int> arr, int key)
{
    int start = 0;
    int end = arr.size() - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }

        // 2 Cases

        // left half is sorted
        if (arr[start] <= arr[mid])
        {

            if (key >= arr[start] and key <= arr[mid])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        // right half is sorted
        else
        {

            if (key >= arr[mid] and key <= arr[end])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }

    return -1;
}

int main()
{
    vector<int> arr{4, 5, 6, 7, 0, 1, 2, 3};
    int key;
    cin >> key;

    cout << RotatedSearch(arr, key) << endl;
}