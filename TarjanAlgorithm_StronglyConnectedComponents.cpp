#include<bits/stdc++.h>
using namespace std;

/* Tajan's Algorithm : https://youtu.be/trvJsdNCEVA

Cross Edges do not contribute to the strongly connected component whereas Back Edge contribute to the strongly connected component

Low time will always be lesser than equal to the discovery time of a node
dis time - discovery time of current node
low time - minimum discovery time node from the given node

If the current element that we're discovering is already discovered than
the current edge will be either Back Edge or Cross Edge.

One strongly component will have only one low value

USE DFS
1. Process a Node
2. Process it Neighbors
u->v Edge Decision : If node is visited already : Back Edge => if v is in the stack - low[u] = min(low[u], dis[v])
                                            Cross Edge(It is possible only, if the graph is directed) => if v is not in stack - Then do nothing                   
                     Else Do DFS from neighbor and While return from neighbor => low[u] = min(low[u], low[v]) 

In one strongly connected component , Only one Node is Head node and for Head node : dis[Head] == low[Head]

No. of strongly connected components in Graph == The No. of nodes whose dis[node]==low[node] */

//Tarjan's Algorithm - Works for both Directed as well as Undirected Graph | Time: O(V+E) , Space - O(V+E)
void DFS(int u, vector<vector<int>>& graph, vector<int>& disc, vector<int>& low, stack<int>& stk, vector<bool>& presentInStack, int& time){
  // Process a Node
	disc[u] = low[u] = time;
	time+=1;
	mystack.push(u);
	presentInStack[u] = true;

  // Iterate the Neighbors of Node
	for(int v: adj[u]){
		if(disc[v]==-1){	//If v is not visited
			DFS(v, graph, disc, low, stk, presentInStack, time);
			low[u] = min(low[u],low[v]);  // while return from the neighbor - update low[u]
		}
		//Differentiate back-edge and cross-edge
		else if(presentInStack[v])	//Back-edge case - update low[u]
			low[u] = min(low[u],disc[v]);
	}

	if (low[u] == disc[u]) { // Check if dis[u] is same as low[u] => u is head node of SCC
	  cout << "SCC is: ";

	  // Pop Until we didn't get the u from the stk
	  // and the nodes from u_____v in stk are part of same strongly connected component
	  while (stk.top() != u) {
	    int node = stk.top();
	    stk.pop();

	    cout << node << " ";
	    presentInStack[node] = false;
	  }
	  cout << stk.top() << "\n";
	  presentInStack[stk.top()] = false;
	  stk.pop();
	}
}

void findSCCs_Tarjan(int n, vector<vector<int>>& edges){
	vector<int> disc(n,-1),low(n,-1);
	vector<bool> presentInStack(n,false);	//Avoids cross-edge
	stack<int> stk;

  // Build the graph
  vector<vector<int>> graph(n);
  for(auto& edge: edges){
    graph[edge[0]].push_back(edge[1]);
  }
  
  // If the graph contains the multiple components
	for(int i=0;i<n;++i)
		if(disc[i]==-1)
			DFS(i,graph,disc,low,mystack,presentInStack, 0);
}
