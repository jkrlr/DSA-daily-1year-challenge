// https://leetcode.com/problems/powx-n/submissions/
// Time = O(LogN), Space =(LogN)

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
/* LeetCode Solution */

// Recursive
class Solution
{
public:
    double myPow(double x, long long int n)
    {
        // check for -ve power
        if (n < 0)
        {
            long long int nn = -1 * n;
            return myPow(1 / x, nn);
        }

        // Base Case
        if (n == 0)
            return 1;

        double halfPower = myPow(x, n / 2);
        double halfPowerSquare = (halfPower * halfPower);

        if (n % 2 == 1)
            return (x * halfPowerSquare);

        return halfPowerSquare;
    }
};

// Iterative
class Solution
{
public:
    double myPow(double x, int n)
    {
        double ans = 1.0;

        // declaring another variable nn because we're modifying the value of n.
        // long long because , range of int is -2,147,483,648 to 2,147,483,647
        // for -2,147,483,648 and making it +ve and storing it into int => overflow
        // So, use long long int
        long long nn = n;
        if (nn < 0)
        {
            nn = -1 * nn;
        }

        while (nn)
        {
            if (nn % 2)
            {
                ans = ans * x;
                nn = nn - 1;
            }
            else
            {
                x = x * x;
                nn = nn / 2;
            }
        }

        if (n < 0)
        {
            ans = (double)(1.0) / (double)(ans);
        }
        return ans;
    }
};
