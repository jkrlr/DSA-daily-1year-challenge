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
 
	void addEdge(int u, int v, bool undir = false){
		adjList[u].push_back(v);
		
		if(undir){
			adjList[v].push_back(u);
		}
	}
 
   // return true if backedge is found, else false
   bool containsCycle(int node, vector<bool> &inStack, vector<bool> &visited){
       /* 1. Arrive at node */
       // mark the node visited and put it into current stack
       visited[node] = true;
	   inStack[node] = true;
 
       /* 2. Do some work */
       for(int nbr : adjList[node]){
 
           if(visited[nbr]==false){
               bool nbrFoundCycle = containsCycle(nbr,inStack,visited);
               if(nbrFoundCycle){
                   return true;
               }
           }
 
           // nbr is visited and it is present in current callstack  
           else if(inStack[nbr]==true){
                   return true;
           }
       }

       /* 3. Going back */
	   // remove the current node from current stack
	   inStack[node] = false;
 
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
	vector<bool> visited(V,false);
	vector<bool> inStack(V,false);
	int node = 0;
 
	// assumed here graph has multiple components
	for(int i=0;i<V;i++){
		if(visited[i]==false){
			bool res = g.containsCycle(node,inStack,visited);
			if(res==true){
				return true;
			}
		}
	}
	return false;
}
 
