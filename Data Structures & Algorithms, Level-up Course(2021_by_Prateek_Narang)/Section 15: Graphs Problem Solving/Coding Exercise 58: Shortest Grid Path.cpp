// * Implicit 2D- Graph
// * Dijkshtra Algorithm
// * SSSP in Weighted , Undirected Graph

#include <iostream>
#include <vector>
#include <set>
#include <climits>
using namespace std;

class Node
{
public:
    int x;
    int y;
    int dist;

    Node(int x, int y, int dist)
    {
        this->x = x;
        this->y = y;
        this->dist = dist;
    }
};

class Compare
{
public:
    bool operator()(const Node &a, const Node &b)
    {
        return a.dist < b.dist;
    }
};

int shortest_path(vector<vector<int>> grid)
{
    int m = grid.size();
    int n = grid[0].size();

    set<Node, Compare> s;
    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

    dist[0][0] = grid[0][0];
    s.insert(Node(0, 0, dist[0][0]));

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    while (!s.empty())
    {
        auto it = s.begin();
        int x = it->x;
        int y = it->y;
        int distTillNow = it->dist;
        s.erase(it);

        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n && distTillNow + grid[nx][ny] < dist[nx][ny])
            {
                // if node is already present in set - Remove
                auto found = s.find(Node(nx, ny, dist[nx][ny]));
                if (found != s.end())
                {
                    s.erase(found);
                }

                // update distance
                dist[nx][ny] = distTillNow + grid[nx][ny];
                s.insert(Node(nx, ny, dist[nx][ny]));
            }
        }
    }

    return dist[m - 1][n - 1];
}
