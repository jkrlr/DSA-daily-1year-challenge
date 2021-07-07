// Time = O(NLogN) and Space = O(N)

#include <iostream>
#include <vector>
using namespace std;

// helper method
int MergeCount(vector<int> &arr, int start, int end)
{
    int L = start;
    int mid = start + (end - start) / 2;
    int R = mid + 1;
    int cnt = 0;

    vector<int> temp;
    while (L <= mid and R <= end)
    {
        if (arr[L] < arr[R])
        {
            temp.push_back(arr[L]);
            L++;
        }
        else // If right part element is smaller than left part element
        {    // Then increment the cnt
            cnt += mid - L + 1;

            temp.push_back(arr[R]);
            R++;
        }
    }

    // Copy the elements from first subarray
    while (L <= mid)
        temp.push_back(arr[L++]);

    // Copy the elements from second subarray
    while (R <= end)
        temp.push_back(arr[R++]);

    //copy elements from temp to original array
    int k = 0;
    for (int idx = start; idx <= end; idx++)
        arr[idx] = temp[k++];

    return cnt;
}

// sorting method
int InversionCount(vector<int> &arr, int start, int end)
{
    // Base Case => what is the smallest possible array which will not require sorting
    if (start >= end) // Either array has one element or the array is empty
        return;

    // Recursive Case
    int mid = start + (end - start) / 2;

    int C1 = InversionCount(arr, start, mid);
    int C2 = InversionCount(arr, mid + 1, end);

    int CI = MergeCount(arr, start, end); // After sorting, Combine them into single arr

    return C1 + C2 + CI;
}

int main()
{
    vector<int> arr{10, 5, 2, 0, 7, 6, 4};
    int start = 0;
    int end = arr.size() - 1;

    cout << InversionCount(arr, start, end) << endl;
}

//5 + 20 + 20 + 10 + 10 + 2