// Q - Given 2 nodes, find whether one node lies in the subtree of other node.
// If one node lies into the subtree of another node
// Then In time of node(children) is greater than its root node(or parent node) and
// Out time of node(children) is smaller than its root node(parent node)

int timer =1;
void dfs_In_Out_time(int v){
	vis[v]=1;
	In[v]=timer++;

	for(int child:ar[v]){
		if(vis[child]==0)
			dfs_In_Out_time(child);
	}
	Out[v]=timer++;
}