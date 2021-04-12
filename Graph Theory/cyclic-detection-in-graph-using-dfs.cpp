// In a tree for each pairs of nodes their exists a unique path
// while if the graph is contains cycle, then this is not the case.

bool dfs_cyclic_detection(int node, int parent){
	vis[node] = 1;
	for(int child:ar[node]){
		if(vis[child]==0){
			if(dfs_cyclic_detection(child, node)==true)
				return true;
		}
		else if(child!=parent)
			return true;
	}
	return false;
}