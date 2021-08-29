// https://www.hackerrank.com/challenges/journey-to-the-moon/problem

// Time = O(N^2), Space = O(N)

// Graph Problem - same type of pair<int,int> property given 
// can be treated as graph edges to solve problem

#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    int V;
    list<int> *adjList;

    Graph(int v)
    {
        V = v;
        adjList = new list<int>[V];
    }

    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int dfs(int node, vector<bool> &visited)
    {
        visited[node] = true;
        int cc_size = 1;

        for (int nbr : adjList[node])
        {
            if (visited[nbr] == false)
            {
                cc_size += dfs(nbr, visited);
            }
        }
        return cc_size;
    }
};

int count_pairs(int N, vector<pair<int, int>> astronauts)
{
    Graph g(N);

    for (auto astronaut : astronauts)
    {
        g.addEdge(astronaut.first, astronaut.second);
    }

    // store size of different components in vector
    vector<int> connectedComp;
    vector<bool> visited(N, false);
    for (int v = 0; v < N; v++)
    {
        if (visited[v] == false)
        {
            int cc_size = g.dfs(v, visited);
            connectedComp.push_back(cc_size);
        }
    }
    // Take product of each pair of connectedComp elements
    long long diffCountryPairs = 0;
    for (int i = 0; i < connectedComp.size() - 1; i++)
    {
        for (int j = i + 1; j < connectedComp.size(); j++)
        {
            diffCountryPairs += connectedComp[i] * connectedComp[j];
        }
    }
    return diffCountryPairs;
}
