// https://leetcode.com/problems/snakes-and-ladders/

// Identify this is a graph problem - directed graph , unweighted graph - because each edge cost = 1 dice throw
// you can reduce it to graph problem - 2D matrix not given graph directly

// Due to Unweighted graph - BFS Single Source Shortest Path Algoritm can be used 
// to find the min. no. of edges/dice throws needed to reach the last

// But the only challenge is how do we create the graph?
// Insert Edges in the Graph(Adj List) + BFS Shortest Path Algo

// n+1 because indexing is 1 based
// we don't need to add edges from 36 onwards

// Time = O(V+E) = (6*n) = O(n) , Space = O(V+E) = (6*n + n + n) = O(n)
#include<iostream>
#include<list>
#include<queue>
using namespace std;
 
class Graph{
	int V;
	list<int> *adjList;
public:
	Graph(int v){
		V = v;
		adjList = new list<int>[V+1];
	}
 
	void addEdge(int u, int v, bool undir = false){
		adjList[u].push_back(v);
		
		if(undir){
			adjList[v].push_back(u);
		}
	}
	
	int minCost(int src, int dest){
		queue<int> q;
		vector<bool> visited(V,false);
		vector<int> dist(V,0);
 
		q.push(src);
		visited[src] = true;
		dist[src] = 0;
 
		while(!q.empty()){
			int curr = q.front();
            q.pop();
            for(int child : adjList[curr]){
                if(!visited[child]){
                    visited[child] = true;
                    dist[child] = dist[curr] + 1;	
                    q.push(child);
                }
            } 
		}
		return dist[dest];
	}
};
 
int min_dice_throws(int n,vector<pair<int,int> > snakes, vector<pair<int,int> > ladders){
  
    vector<int> board(n+1, 0);
    
    for(auto sp : snakes){
        int start = sp.first;
        int end = sp.second;
        board[start] = end - start;		// -ve
    }
    
    for(auto lp : ladders){
        int start = lp.first;
        int end = lp.second;
        board[start] = end - start;		// +ve
    }
  
	// Graph
	Graph g(n+1);		// n+1 because indexing is 1 based

	// we don't need to add edges from 36(i.e. n) onwards
	for(int u=1; u<n;u++){
		for(int dice=1; dice<=6;dice++){
			int v = u + dice;
            // If snake or ladder comes at vertex v
            v += board[v];
        
            // add edge
            if(v<=n){
                g.addEdge(u, v);
            }
		}
	}
 
	return g.minCost(1,n);
}
