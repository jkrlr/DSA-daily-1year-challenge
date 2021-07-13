#include <iostream>
#include <vector>
using namespace std;

int CountSubsets(vector<int> arr, int n, int start, int Sum)
{
    // Base Case
    if (start == n)
    {
        if (Sum == 0)
        {
            return 1;
        }
        return 0;
    }

    // Recursive Case
    int include = CountSubsets(arr, n, start + 1, Sum - arr[start]);
    int exclude = CountSubsets(arr, n, start + 1, Sum);
    return include + exclude;
}

int main()
{
    vector<int> arr{1, 2, 3, 4, 5};
    int X = 6;

    cout << CountSubsets(arr, arr.size(), 0, X) << endl;
}