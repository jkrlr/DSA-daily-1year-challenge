// Time = O(3^N) , Space = O(LogN)

#include <iostream>
using namespace std;

int CountWays(int N)
{
    // Base Case
    if (N < 0)
    {
        return 0;
    }
    if (N == 0)
    {
        return 1;
    }

    // Recursive Case
    return CountWays(N - 1) + CountWays(N - 2) + CountWays(N - 3);
}

int main()
{
    int N;
    cin >> N;

    cout << CountWays(N) << endl;
}