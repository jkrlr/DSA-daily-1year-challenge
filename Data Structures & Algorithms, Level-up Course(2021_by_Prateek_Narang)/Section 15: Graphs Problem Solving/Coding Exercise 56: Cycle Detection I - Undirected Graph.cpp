// Time = O(V+E), Space = O(V+E)

#include<bits/stdc++.h>
using namespace std;
 
class Graph{
	int V;
	list<int> *adjList;
public:
	Graph(int v){
		V = v;
		adjList = new list<int>[V];
	}
 
	void addEdge(int u, int v, bool undir = true){
		adjList[u].push_back(v);
		
		if(undir){
			adjList[v].push_back(u);
		}
	}
 
	bool containsCycle(int node, int parent, bool *visited){
		// mark the node visited
		visited[node] = true;
 
		for(int nbr : adjList[node]){

			if(visited[nbr]==false){
				bool nbrFoundCycle = containsCycle(nbr,node,visited);
				if(nbrFoundCycle){
					return true;
				}
			}

			// nbr is visited and its not the parent of current node in the current dfs call
			else if(nbr!= parent){
					return true;
			}
		}
		return false;
	}
};
 
 
 
bool contains_cycle(int V, vector<pair<int,int> > edges){    
   	// Graph
	Graph g(V);
	for(int i=0;i<edges.size();i++){
		int u = edges[i].first;
		int v = edges[i].second;
		g.addEdge(u,v);
	}
 
	// Cycle
	bool *visited = new bool[V]{false};
	int node = 0;
	int parent = -1;
 
	// assumed here graph has multiple components
	for(int i=0;i<V;i++){
		if(visited[i]==false){
			bool res = g.containsCycle(node,parent,visited);
			if(res==true){
				return true;
			}
		}
	}
	return false;
}
 
