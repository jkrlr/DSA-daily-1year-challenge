// https://www.spoj.com/problems/PRIME1/
// Time = O(MaxN*loglog(MaxN)) , Space = O(maxN) , maxN = R-L+1

#include <bits/stdc++.h>

using namespace std;

vector<int> primes;

void sieve(int maxN)
{
    vector<int> prime(maxN + 1, 1);
    prime[0] = prime[1] = 0;

    for (int i = 2; i <= maxN; i++)
    {
        if (prime[i])
        {
            for (int j = 2 * i; j <= maxN; j += i)
                prime[j] = 0;
        }
    }

    for (int i = 1; i <= maxN; i++)
    {
        if (prime[i])
            primes.push_back(i);
    }
}

void segmentedSieve(int L, int R)
{
    if (L == 1)
        L++;

    int maxN = R - L + 1;
    vector<int> prime(maxN, 1);

    for (int p : primes)
    {
        if (p * p <= R)
        {
            int i = (L / p) * p;
            if (i < L)
                i += p;
            for (; i <= R; i += p)
            {
                if (i != p)
                    prime[i - L] = 0;
            }
        }
    }

    for (int i = 0; i < maxN; i++)
    {
        if (prime[i])
            cout << (i + L) << endl;
    }
}

int main()
{
    sieve(100000);

    int t, L, R;
    cin >> t;
    while (t--)
    {
        cin >> L >> R;
        segmentedSieve(L, R);
        cout << endl;
    }

    return 0;
}
