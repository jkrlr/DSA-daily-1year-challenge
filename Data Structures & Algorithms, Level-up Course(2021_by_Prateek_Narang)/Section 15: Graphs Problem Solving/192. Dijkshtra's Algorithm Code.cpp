// Time = O(V+E), Space = O(V+E)
// SSSP in weighted undirected graph
 
#include<bits/stdc++.h>
using namespace std;
 
class Graph{
	int V;
	list<pair<int,int>> *adjList;
public:
	Graph(int v){
		V = v;
		adjList = new list<pair<int,int>>[V];
	}
 
	void addEdge(int u, int v, int wt, bool undir = true){
		adjList[u].push_back({wt,v});
 
		if(undir){
			adjList[v].push_back({wt,u});
		}
	}
	
	int dijkshtra(int src, int dest){
		// Data Structures
		vector<int> dist(V,INT_MAX);	// It solves two purpose - store distance and tells if node is not visited => dist = INT_MAX
		set<pair<int,int>> s;	// comparison for sorting based upon first value of pair
		
		// Initialization
		dist[src] = 0;
		s.insert({dist[src], src});
		
		while(!s.empty()){
			auto it = s.begin();
			int node = it->second;
			int distTillNow = it->first;
			s.erase(it);	// Pop
 
			// Iterate over the nbrs of node	
			for(auto nbrPair : adjList[node]){
				int nbr = nbrPair.second;
				int edgeDist = nbrPair.first;
				
				if(distTillNow + edgeDist < dist[nbr]){
					// If this nbr is already in set, Remove it
					auto found = s.find({dist[nbr], nbr});
					if(found != s.end()){
						s.erase(found);
					}
 
					// Update distance
					dist[nbr] = distTillNow + edgeDist;
					s.insert({dist[nbr],nbr});
				}
			}
		}
		
		// single soure shortest path to all other nodes
		for(int i=0;i<V;i++){
			cout<<"Distance of node "<<i<<" is "<<dist[i]<<endl;
		}
 
		return dist[dest];
	}
};
 
int main(){
	Graph g(5);
	
	g.addEdge(0,1,1);
	g.addEdge(0,2,4);
	g.addEdge(0,3,7);
	g.addEdge(1,2,1);
	g.addEdge(2,3,2);
	g.addEdge(3,4,3);
 
	cout<<g.dijkshtra(0,4)<<endl;
 
	return 0;
}
