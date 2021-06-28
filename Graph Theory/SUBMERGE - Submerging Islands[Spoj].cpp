// Time = O(V+E)
// Space = O(V+E)

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[10001]; // adjacency list of graph
int low[10001], in[10001];
bool vis[10001];
set<int> cutVertex;
int timer;

void dfs(int currNode, int parent = -1)
{
    vis[currNode] = true;
    in[currNode] = low[currNode] = timer++;
    int subTree = 0;

    for (int child : adj[currNode])
    {

        // parent
        if (child == parent)
            continue;

        // back edge
        if (vis[child])
        {
            low[currNode] = min(low[currNode], in[child]);
        }

        // forward edge
        else
        {
            dfs(child, currNode);

            low[currNode] = min(low[currNode], low[child]);

            // Check Articulation Point or not
            // If currNode is root then we'll not check Articulation point
            if (low[child] >= in[currNode] && parent != -1)
                cutVertex.insert(currNode);

            subTree++;
        }
    }

    // Root - Articulation point
    if (parent == -1 && subTree >= 2)
        cutVertex.insert(currNode);
}

int main()
{
    int n, m, a, b;

    while (1)
    {
        cin >> n >> m;
        if (n == 0 and m == 0)
            break;

        timer = 1;
        cutVertex.clear();

        for (int i = 1; i <= n; i++)
            adj[i].clear(), vis[i] = false;

        for (int i = 0; i < m; i++)
            cin >> a >> b, adj[a].push_back(b), adj[b].push_back(a);

        // Because Graph may have more than one connected component
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
                dfs(i);
        }

        cout << cutVertex.size() << endl;
    }
}