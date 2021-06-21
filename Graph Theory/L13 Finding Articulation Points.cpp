// Time = O(V+E)
// Space = O(V+E)

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj; // adjacency list of graph
vector<int> low, in;
vector<bool> vis;
int timer;

void dfs(int currNode, int parent = -1)
{
    vis[currNode] = true;
    in[currNode] = low[currNode] = timer++;
    int subTree = 0;

    for (int child : adj[currNode])
    {

        // the edge leads back to parent in DFS tree.
        if (child == parent)
            continue;

        // the edge is back edge to one of the ancestors
        if (vis[child])
        {
            low[currNode] = min(low[currNode], in[child]);
        }

        //the edge is part of DFS tree i.e. forward edge
        else
        {
            dfs(child, currNode);

            low[currNode] = min(low[currNode], low[child]);

            // Check Articulation Point or not
            // If currNode is root then we'll not check Articulation point
            if (low[child] >= in[currNode] && parent != -1)
                Is_CutVertex(currNode); // Is_CutVertex(v) function you will define. Whatever you wanted to be from that cutVertex.
                                        // If You find the cnt of Articulation point then may use counter for that
            subTree++;                  // But the same node can be found Articulation point by many subTree
                                        // So, It is better to use Set for that purpose.
        }
    }

    // If Root has more than one subTree then
    // Root itself an Articulation point
    if (parent == -1 && subTree >= 2)
        Is_CutVertex(currNode);
}

int main()
{
    timer = 1;
    int n, m, a, b;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> a >> b, adj[a].push_back(b), adj[b].push_back(a);

    for (int i = 1; i <= n; i++)
        vis[i] = false;

    // Because Graph may have more than one connected component
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            dfs(i);
    }
}