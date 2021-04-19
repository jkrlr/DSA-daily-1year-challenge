// https://www.spoj.com/problems/PT07Z/
// PT07Z - Longest path in a tree

#include <bits/stdc++.h>
#define REP(i, n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define endl '\n'
#define INF 1000000000
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(NULL)

using namespace std;

vi ar[10001];
int vis[10001];
int maxDist, maxNode;

void dfs(int v, int d)
{
    vis[v] = 1;
    if (d > maxDist)
        maxDist = d, maxNode = v;

    for (int child : ar[v])
    {
        if (vis[child] == 0)
        {
            dfs(child, d + 1);
        }
    }
}

int main()
{
    int n, a, b;
    cin >> n;

    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        ar[a].pb(b);
        ar[b].pb(a);
    }

    maxDist = -1;
    dfs(1, 0);

    for (int i = 1; i <= n; i++)
        vis[i] = 0;

    maxDist = -1;
    dfs(maxNode, 0);

    cout << maxDist << endl;
}
