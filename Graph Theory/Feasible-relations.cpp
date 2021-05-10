// Feasible relations
// https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/feasible-relations/

// Problem Approach :
// If "!=" sign operator elements belongs to two sets, then ans = NO, else ans = YES 
// 5 5                                      1
// 1 = 2                                   / \ 
// 3 = 1                                  2   3
// 4!= 2                      
// 5 = 4                                  4---5
// 3!=5

// Ans = YES






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
int vis[1000001], cc[1000001];
int curr_cc;

void dfs(int node)
{
    vis[node] = 1;
    cc[node] = curr_cc;

    for (int child : adj[node])
    {
        if (vis[child] == 0)
            dfs(child);
    }
}

int main()
{
    FAST_IO;

    int t, n, k, a, b;
    string op;

    cin >> t;

    while (t--)
    {
        cin >> n >> k;

        for (int i = 1; i <= n; i++)
            adj[i].clear(), vis[i] = 0;

        vector<pair<int, int>> EdgeList;

        for (int i = 1; i <= k; i++)
        {
            cin >> a >> op >> b;

            if (op == "=")
                adj[a].push_back(b), adj[b].push_back(a);
            else
                EdgeList.push_back({a, b});
        }

        curr_cc = 0;

        for (int i = 1; i <= n; i++)
        {
            if (vis[i] == 0)
            {
                curr_cc++;
                dfs(i);
            }
        }

        bool flag = true;

        for (int i = 0; i < EdgeList.size(); i++)
        {
            a = EdgeList[i].first;
            b = EdgeList[i].second;

            if (cc[a] == cc[b])
            {
                flag = false;
                break;
            }
        }

        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}