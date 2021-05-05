// KQUERY - K-query
// https://www.spoj.com/problems/KQUERY/

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
#define maxN 30001  // using maxN in declaring st[4*maxN] and ar[maxN] gives TLE

vi st[4 * 30001];
int ar[30001];

void merge(vi &a, vi &b, vi &c)
{
    int i = 0, j = 0;

    while (i < a.size() && j < b.size())
    {
        if (a[i] <= b[j])
            c.pb(a[i]), i++;
        else
            c.pb(b[j]), j++;
    }

    while (i < a.size())
        c.pb(a[i]), i++;

    while (j < b.size())
        c.pb(b[j]), j++;
}

void build(int si, int ss, int se)
{
    if (ss == se)
    {
        st[si].pb(ar[ss]);
        return;
    }

    int mid = (se - ss) / 2 + ss;

    build(2 * si, ss, mid);
    build(2 * si + 1, mid + 1, se);

    merge(st[2 * si], st[2 * si + 1], st[si]);
}

int query(int si, int ss, int se, int qs, int qe, int k)
{
    if (ss > qe || se < qs)
        return 0;

    if (ss >= qs && se <= qe)
    {
        // uper_bound is iterator, which is binary search
        // In our case it returns the elements which is strictly greater than k
        int res = st[si].end() - upper_bound(st[si].begin(), st[si].end(), k);
        return res;
    }

    int mid = (ss + se) / 2;
    int l = query(2 * si, ss, mid, qs, qe, k);
    int r = query(2 * si + 1, mid + 1, se, qs, qe, k);

    return l + r;
}

int main()
{

    int n, q, l, r, k;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> ar[i];

    build(1, 1, n);

    cin >> q;

    while (q--)
    {
        cin >> l >> r >> k;
        cout << query(1, 1, n, l, r, k) << endl;
    }

    return 0;
}