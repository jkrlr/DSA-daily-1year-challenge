// GSS3 - Can you answer these queries III
// https://www.spoj.com/problems/GSS3/

/* Problem Statement :
You are given a sequence A of N (N <= 50000) integers between -10000 and 10000.On this sequence you have to apply M (M <= 50000) operations:
modify the i-th element in the sequence or for given x y print max{Ai + Ai+1 + .. + Aj | x<=i<=j<=y }. */

// Concept Used -> Segement Tree - Point Update

// Time Complexity = O(M*logN)
// Space Complexity = O(N)

#include <bits/stdc++.h>
#define REP(i, n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define endl '\n'
#define INF 1000000000
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(NULL)

using namespace std;

struct node
{
    int sum;
    int maxlsum;
    int maxrsum;
    int maxisum;
};

int ar[50001];
node st[4 * 50001];

void build(int si, int ss, int se)
{
    if (ss == se)
    {
        st[si].sum = st[si].maxlsum = st[si].maxrsum = st[si].maxisum = ar[ss];
        return;
    }

    int mid = ss + (se - ss) / 2;

    build(2 * si, ss, mid);
    build(2 * si + 1, mid + 1, se);

    st[si].sum = st[2 * si].sum + st[2 * si + 1].sum;
    st[si].maxlsum = max(st[2 * si].maxlsum, st[2 * si].sum + st[2 * si + 1].maxlsum);
    st[si].maxrsum = max(st[2 * si].maxrsum + st[2 * si + 1].sum, st[2 * si + 1].maxrsum);
    st[si].maxisum = max(max(st[2 * si].maxisum, st[2 * si + 1].maxisum), st[2 * si].maxrsum + st[2 * si + 1].maxlsum);
}

void update(int si, int ss, int se, int qi, int val)
{
    if (ss == se)
    {
        st[si].sum = st[si].maxlsum = st[si].maxrsum = st[si].maxisum = val;
        return;
    }

    int mid = ss + (se - ss) / 2;

    if (qi <= mid)
        update(2 * si, ss, mid, qi, val);
    else
        update(2 * si + 1, mid + 1, se, qi, val);

    st[si].sum = st[2 * si].sum + st[2 * si + 1].sum;
    st[si].maxlsum = max(st[2 * si].maxlsum, st[2 * si].sum + st[2 * si + 1].maxlsum);
    st[si].maxrsum = max(st[2 * si].maxrsum + st[2 * si + 1].sum, st[2 * si + 1].maxrsum);
    st[si].maxisum = max(max(st[2 * si].maxisum, st[2 * si + 1].maxisum), st[2 * si].maxrsum + st[2 * si + 1].maxlsum);
}

int query(int si, int ss, int se, int qs, int qe)
{
    if (ss > qe || qs > se)
        return 0;
    if (ss >= qs && se <= qe)
        return st[si].maxisum;

    int mid = ss + (se - ss) / 2;

    int left = query(2 * si, ss, mid, qs, qe);
    int right = query(2 * si + 1, mid + 1, se, qs, qe);

    return left + right;
}

int main()
{
    int n, m, l, r, code;

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> ar[i];

    build(1, 1, n);

    cin >> m;
    while (m--)
    {
        cin >> code >> l >> r;

        if (code == 0)
        {
            update(1, 1, n, l, r);
        }
        else if (code == 1)
        {
            cout << query(1, 1, n, l, r) << endl;
        }
    }
}
