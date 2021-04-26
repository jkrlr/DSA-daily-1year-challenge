// Problem Statement
// Given a tree, construct an array subSize[],
// Where subSize[V] Stores the size of subtree rooted at node V.

subSize[1] = 4                                          1
subSize[2] = 3                                         /
subSize[3] = 1                                        2
subSize[4] = 1                                       / \    
                                                    3   4


vector<int> adj[100001];
int vis[100001], subSize[100001];

int dfs(int node){
    vis[node] = 1;
    int curr_size = 1;

    for(int child:adj[node]){
        if (vis[child]==0)
        {
            curr_size += dfs(child);
        }
    }
    subSize[node] = curr_size;
    return curr_size;
}