// https://leetcode.com/problems/sqrtx/
// Time = O(Log(N) + 9P), Space = O(1)

#include <iostream>
using namespace std;

float SquareRoot(int N, int P)
{
    int start = 0;
    int end = N;
    float ans;

    // Binary Search(Search space 0...N)
    while (start <= end)
    {
        long long mid = start + (end - start) / 2; // long long => because for mid*mid cause overflow for 32-bit integer

        if (mid * mid <= N)
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    // Linear Search for each place(for floating part)
    float incr = 0.1;
    for (int place = 1; place <= P; place++)
    {

        // do linear search
        while ((ans + incr) * (ans + incr) <= N)
        {
            ans += incr;
        }

        incr /= 10.0;
    }

    return ans;
}

int main()
{
    int N, P;
    cin >> N >> P;

    cout << SquareRoot(N, P) << endl;
}