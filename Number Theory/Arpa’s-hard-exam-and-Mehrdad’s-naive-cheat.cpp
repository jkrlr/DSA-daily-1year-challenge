// A. Arpa’s hard exam and Mehrdad’s naive cheat
// https://codeforces.com/problemset/problem/742/A

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

lli power(lli a, lli n, lli m)
{
    lli res = 1;

    while (n)
    {
        if (n % 2)
        {
            res = (res * a) % m; // overflow not happen bcoz m is 10. So, a and res value remains always less than 10.
            n--;
        }
        else
        {
            a = (a * a) % m;
            n /= 2;
        }
    }

    return res;
}

int main()
{

    int n;

    cin >> n;

    cout << power(8, n, 10);
}