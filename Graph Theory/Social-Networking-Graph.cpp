// Social Networking Graph
// https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/social-networking-graph/

// Solved Using bfs

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

vector<int> adj[1000001];
int vis[1000001], level[1000001], dist[1000001];

void bfs(int src)
{

    queue<int> q;
    q.push(src);

    vis[src] = 1;
    dist[src] = 0;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (int child : adj[curr])
        {
            if (vis[child] == 0)
            {
                dist[child] = dist[curr] + 1;
                q.push(child);
                vis[child] = 1;
                level[dist[child]]++;
            }
        }
    }
}

int main()
{

    int n, m, a, b, src, d, q;

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cin >> q;

    while (q--)
    {
        cin >> src >> d;

        for (int i = 0; i <= n; i++)
            level[i] = 0, vis[i] = 0;

        bfs(src);

        cout << level[d] << endl;
    }

    return 0;
}