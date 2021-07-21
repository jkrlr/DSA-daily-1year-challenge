#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

/* long long int powerModulo(int a, int b)
{

    long long int res = 1;
    while (b > 0)
    {
        if (b % 2 == 0)
        {
            res = ((res % mod) * (a % mod))%mod;
            b /= 2;
        }
        else
        {
            a = ((a % mod) * (a % mod))%mod;
            b--;
        }
    }

    return res;
} */

//Recursive Solution : Time = O(logb) , Space = O(logb)
long long int powerModulo(int a, int b)
{
    // Base Case
    if (b == 0)
        return 1;

    long long halfPower = powerModulo(a, b / 2);
    long long halfPowerSquare = ((halfPower % mod) * (halfPower % mod)) % mod;

    if (b % 2 == 1)
        return ((a % mod) * (halfPowerSquare % mod)) % mod;

    return halfPowerSquare;
}