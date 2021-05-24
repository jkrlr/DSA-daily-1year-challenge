// E. Bertown roads
// https://codeforces.com/problemset/problem/118/E

// Solved using Concept of Bridges, DFS Tree 

// Problem statement :
// Bertown has n junctions and m bidirectional roads. We know that one can get from any junction to any other one by the existing roads.
// Determine whether there is a way to make the traffic one-directional so that there still is the possibility to get from any junction to any other one. 

// If their exists a bridge a bridge in the graph,
// Then, we can't make this graph to be one-directional, because of bridge we wouldn't able to traverse the graph from both sides of bridge.

// Else, we can print the solution using DFS tree.
// DFS Tree Approach :
// Claim 1 : There is a path from root to every other node
// Claim 2 : There is a path from every node to root.

// Time Complexity = O(n+m)
// Space Complexity = O(n+m)

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

vector<int> adj[200001];
int vis[200001], in[200001], low[200001];
int timer;
bool hasBridge;
vector<pair<int, int>> edgeList;

void dfs(int node, int par)
{
    vis[node] = 1;
    in[node] = low[node] = timer++;

    for (int child : adj[node])
    {
        if (child == par)
            continue;

        else if (vis[child])
        {
            // Back - edge condition

            low[node] = min(low[node], in[child]);

            if (in[node] > in[child])
                edgeList.push_back({node, child});
        }

        else
        {
            // Forward - edge condition

            dfs(child, node);
            // Check condition for bridge
            if (low[child] > in[node])
            {
                hasBridge = true;
                return;
            }

            edgeList.push_back({node, child});
            low[node] = min(low[node], low[child]);
        }
    }
}

int main()
{
    int n, m, a, b;
    cin >> n >> m;

    while (m--)
        cin >> a >> b, adj[a].push_back(b), adj[b].push_back(a);

    dfs(1, -1);

    if (hasBridge)
        cout << 0;
    else
    {
        for (pair<int, int> e : edgeList)
            cout << e.first << " " << e.second << endl;
    }

    return 0;
}