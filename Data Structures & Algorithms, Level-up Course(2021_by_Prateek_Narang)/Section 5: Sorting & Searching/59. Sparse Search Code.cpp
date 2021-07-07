// Time : Avg. Case = O(LogN*W) , Worst Case = O(N) and Space = O(1)

#include <iostream>
#include <cstring>
using namespace std;

int SparseSearch(string arr[], int n, string key)
{
    int start = 0;
    int end = n - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid] == "")
        { // update our mid o point to a nearest non empty string
            int L = mid - 1, R = mid + 1;

            while ((L >= start and arr[L] == "") and (R <= end and arr[R] == ""))
            {
                L--;
                R++;
            }
            if (L >= start and arr[L] != "")
                mid = L;
            else if (R <= end and arr[R] != "")
                mid = R;
            else
                return -1; // Traversed the whole array but couldn't find a non-empty string
        }
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            end = mid - 1;
        else
            start = mid + 1;
    }

    return -1;
}

int main()
{
    string arr[] = {"ai", "", "", "bat", "", "", "car", "cat", "", "", "dog", ""};
    int n = 12;
    string key;
    cin >> key;
    cout << SparseSearch(arr, n, key);
}
