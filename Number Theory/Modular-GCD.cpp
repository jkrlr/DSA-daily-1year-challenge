// Modular GCD
// https://www.codechef.com/problems/GCDMOD

// Approach
// If you need to calculate GCD(X,Y),
// where X is very huge number but Y is smaller. Then,
// We would find potential GCD candidate and
// apply modulo arithmetic to find GCD.

// GCD(453274590445273854945,90)=?

// Potential candidate would be divisor of 90.
// That is 1,2,3,5,6,9,10,15,18,30,45,90 .

// We can calculate A^n % d
// (A^n + B^n) % d =0
// (A^n + B^n) % d = (A^n % d + B^n % d) % d 


#include <bits/stdc++.h>
#define REP(i, n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000
#define endl '\n'
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(NULL)

using namespace std;

lli power(lli a, lli n, lli d)
{
    lli res = 1;

    while (n)
    {
        if (n % 2)
        {
            res = ((res % d) * (a % d)) % d;
            n--;
        }
        else
        {
            a = ((a % d) * (a % d)) % d;
            n /= 2;
        }
    }

    return res;
}

lli GCD(lli A, lli B, lli n)
{
    if (A == B)
    {
        return (power(A, n, mod) + power(B, n, mod)) % mod;
    }

    lli pot_candidate = 1;

    lli num = A - B;

    for (lli i = 1; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            lli tmp = (power(A, n, i) + power(B, n, i)) % i;

            if (tmp == 0)
                pot_candidate = max(pot_candidate, i);

            tmp = (power(A, n, num / i) + power(B, n, num / i)) % (num / i);

            if (tmp == 0)
                pot_candidate = max(pot_candidate, (num / i));
        }
    }
    return (pot_candidate % mod);
}

int main()
{

    int t;
    lli A, B, n;

    cin >> t;

    while (t--)
    {
        cin >> A >> B >> n;
        cout << GCD(A, B, n) << endl;
    }

    return 0;
}