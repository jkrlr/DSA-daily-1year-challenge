// Multiples of 3 : Solved using Lazy Propagation
// https://www.codechef.com/problems/MULTQ3

// In this Q we're storing the cnt of 3 types of element in segmet tree,
// 0%3 cnt , 1%3 cnt, 2%3 cnt
// In each range update we can circular right shift the cnt for that range
// for getting the answer

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

const int maxN = 100001;
int lazy[4 * maxN];

struct node
{
    int ar[3];
};

node st[4 * maxN];

void build(int si, int ss, int se)
{

    if (ss == se)
    {

        st[si].ar[0] = 1; // Since, Initially all elements of array is given as zero.
        st[si].ar[1] = 0;
        st[si].ar[2] = 0;

        return;
    }

    int mid = ss + (se - ss) / 2;

    build(2 * si, ss, mid);
    build(2 * si + 1, mid + 1, se);

    st[si].ar[0] = st[2 * si].ar[0] + st[2 * si + 1].ar[0];
    st[si].ar[1] = st[2 * si].ar[1] + st[2 * si + 1].ar[1];
    st[si].ar[2] = st[2 * si].ar[2] + st[2 * si + 1].ar[2];
}

void shift(int si)
{
    int a = st[si].ar[2];

    st[si].ar[2] = st[si].ar[1];
    st[si].ar[1] = st[si].ar[0];
    st[si].ar[0] = a;
}

void update(int si, int ss, int se, int qs, int qe)
{

    // lazy[si]== 0 means no pending val update changes
    if (lazy[si] != 0)
    {
        int times_pend_update = lazy[si];
        lazy[si] = 0;

        // Pass the pending updates to the left and right child
        if (ss != se)
        {
            lazy[2 * si] += times_pend_update;
            lazy[2 * si + 1] += times_pend_update;
        }

        times_pend_update %= 3; // Becoz size is '3'. so, after multiple of 3 right shift times, position is same.

        for (int i = 0; i < times_pend_update; i++)
        {
            shift(si);
        }
    }

    if (ss > qe || se < qs)
        return;

    if (ss >= qs && se <= qe)
    {

        shift(si);

        // Pass the pending updates to the left and right child
        if (ss != se)
        {
            lazy[2 * si] += 1;
            lazy[2 * si + 1] += 1;
        }
        return;
    }

    int mid = ss + (se - ss) / 2;

    update(2 * si, ss, mid, qs, qe);
    update(2 * si + 1, mid + 1, se, qs, qe);

    st[si].ar[0] = st[2 * si].ar[0] + st[2 * si + 1].ar[0];
    st[si].ar[1] = st[2 * si].ar[1] + st[2 * si + 1].ar[1];
    st[si].ar[2] = st[2 * si].ar[2] + st[2 * si + 1].ar[2];
}

int query(int si, int ss, int se, int qs, int qe)
{

    // lazy[si]== 0 means no pending val update changes
    if (lazy[si] != 0)
    {
        int times_pend_update = lazy[si];
        lazy[si] = 0;

        // Pass the pending updates to the left and right child
        if (ss != se)
        {
            lazy[2 * si] += times_pend_update;
            lazy[2 * si + 1] += times_pend_update;
        }

        times_pend_update %= 3; // Becoz size is '3'. so, after multiple of 3 right shift times, position is same.

        for (int i = 0; i < times_pend_update; i++)
        {
            shift(si);
        }
    }

    if (ss > qe || se < qs)
        return 0;

    if (ss >= qs && se <= qe)
        return st[si].ar[0];

    int mid = ss + (se - ss) / 2;

    int left = query(2 * si, ss, mid, qs, qe);
    int right = query(2 * si + 1, mid + 1, se, qs, qe);

    return left + right;
}

int main()
{
    FAST_IO;

    int n, q, code, A, B;
    cin >> n >> q;

    build(1, 1, n);

    while (q--)
    {
        cin >> code >> A >> B;

        if (code == 0)
        {
            update(1, 1, n, A + 1, B + 1);
        }
        else
        {
            cout << query(1, 1, n, A + 1, B + 1) << endl;
        }
    }
}