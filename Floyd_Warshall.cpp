NOTE: Distances don't get modified for kth adjacent vertices.
  
NOTE: Distance of vertex-vertex(dist[i][i]) = 0 (If no self loop are given)
	  So, If we get vertex-vertex(dist[i][i]) = -ve => Their is -ve edge weight cycle in graph
	  Then, In Case of -ve edge weight cycle, The shortest distance can't be found
  
NOTE : Shortest Path from i to j (which may or may not include k)
		d[i][j] = min(d[i][j], d[i][k] + d[k][j])
	  
NOTE : Time - O(V^3), Space - O(V^2)


void floydWarshall(vector<vector<int>> graph)
{
    int n = graph.size();
    vector<vector<int>> dist(n, vector<int>(n));

	//Assign all values of graph to allPairs_SP
	for(int i=0;i<V;++i)
		for(int j=0;j<V;++j)
			dist[i][j] = graph[i][j];

	//Find all pairs shortest path by trying all possible paths
	for(int k=0;k<V;++k){	//Try all intermediate nodes
		for(int i=0;i<V;++i){	//Try for all possible starting position
			for(int j=0;j<V;++j){	//Try for all possible ending position
			  if(dist[i][k]==INT_MAX || dist[k][j]==INT_MAX)	//SKIP if K is unreachable from i or j is unreachable from k
				continue;
			  else if(dist[i][k]+dist[k][j] < dist[i][j])		//Check if new distance is shorter via vertex K
				dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

  
	//Check for negative edge weight cycle
	for(int i=0;i<V;++i){
		if(dist[i][i] < 0){
			cout<<"Negative edge weight cycle is present\n";
			return;
		}
	}

  
	//Print Shortest Path Graph
	//(Values printed as INT_MAX defines there is no path)
	for(int i=1;i<V;++i){
		for(int j=0;j<V;++j)
			cout<<i<<" to "<<j<<" distance is "<<dist[i][j]<<"\n";
		cout<<"=================================\n";
	}
}

int main()
{
	vector<vector<int>> graph = { {0, 1, 4, INT_MAX, INT_MAX, INT_MAX},
                              {INT_MAX, 0, 4, 2, 7, INT_MAX},
                              {INT_MAX, INT_MAX, 0, 3, 4, INT_MAX},
                              {INT_MAX, INT_MAX, INT_MAX, 0, INT_MAX, 4},
                              {INT_MAX, INT_MAX, INT_MAX, 3, 0, INT_MAX},
                              {INT_MAX, INT_MAX, INT_MAX, INT_MAX, 5, 0} };

	floydWarshall(graph);
	return 0;
}
