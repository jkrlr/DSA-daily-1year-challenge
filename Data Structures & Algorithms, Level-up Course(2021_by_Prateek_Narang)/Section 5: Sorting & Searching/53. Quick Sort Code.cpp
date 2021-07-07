// Time : Avg. Case = O(NLogN) and Worst Case = O(N^2), Space = O(N) in Worst Case and O(LogN) in Avg. Case
// The space complexity is calculated based on the space used in the recursion stack. The worst case space used will be O(n)

#include <iostream>
#include <vector>
using namespace std;

// partition
int Partition(vector<int> &arr, int start, int end)
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

    swap(arr[L + 1], arr[end]); // Palce Pivot element to its correct position

    return (L + 1); // return pivot index
}

// sorting method
void QuickSort(vector<int> &arr, int start, int end)
{
    // Base Case
    if (start >= end)
        return;

    // Recursive Case
    int pivot = Partition(arr, start, end);

    QuickSort(arr, start, pivot - 1);
    QuickSort(arr, pivot + 1, end);
}

int main()
{
    vector<int> arr{10, 5, 2, 0, 7, 6, 4};
    int start = 0;
    int end = arr.size() - 1;

    QuickSort(arr, start, end);

    for (int num : arr)
        cout << num << ", ";
}
//5+15+5+10+10 + 10 + 5 + 10