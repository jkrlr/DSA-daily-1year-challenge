// SSSP in an Unweighted graph using BFS

vector<int> adj[100001];
int vis[100001], dis[100001];

int dfs(int node){
    vis[node] = 1;
    int dis[node] = 0;

    queue<int> q;

    q.push(node);

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for(int child : adj[curr]){
            if(vis[child]==0){
                vis[child] = 1;
                dis[child] = dis[curr] + 1;
                q.push(child);
            }
        }
    }
}