// Time : Avg. Case = O(N) to O(NLogN) and Worst Case = O(N^2), Space = O(N) in Worst Case and O(LogN) in Avg. Case

#include <iostream>
#include <vector>
using namespace std;

// partition
int Partition(vector<int> &arr, int start, int end, int k)
{
    int L = start - 1;
    int PivotVal = arr[end];

    for (int R = start; R < end; R++)
    {
        if (arr[R] < PivotVal)
        {
            L++;
            swap(arr[R], arr[L]);
        }
    }

    swap(arr[L + 1], arr[end]); // Place Pivot element to its correct position

    return (L + 1); // return pivot index
}

// sorting method
int QuickSelect(vector<int> &arr, int start, int end, int k)
{
    // Assuming k will be inside the array

    // Partition
    int pivot = Partition(arr, start, end, k);

    if (pivot == k)
        return arr[pivot];
    else if (pivot > k)
        return QuickSelect(arr, start, pivot - 1, k);
    else
        return QuickSelect(arr, pivot + 1, end, k);
}

int main()
{
    vector<int> arr{10, 5, 2, 0, 7, 6, 4};
    int start = 0;
    int end = arr.size() - 1;
    int k;
    cin >> k;

    cout << QuickSelect(arr, start, end, k) << endl;
}
//5+5+15+10+5+5+15 + 5 + 5 + 5 + 10 + 5