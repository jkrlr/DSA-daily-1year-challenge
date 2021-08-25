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
		adjList = new list<int>[V];
	}
 
	void addEdge(int u, int v, bool undir = true){
		adjList[u].push_back(v);
		
		if(undir){
			adjList[v].push_back(u);
		}
	}
	
	void bfs(int source, int dest=-1){
		queue<int> q;
		bool *visited = new bool[V]{0};
		vector<int> dist(V), parent(V);
 
		q.push(source);
		visited[source] = true;
		dist[source] = 0;
		parent[source] = -1;
 
		while(!q.empty()){
			int curr = q.front();
            q.pop();

            for(int child : adjList[curr]){
                if(!visited[child]){
                    visited[child] = true;
                    dist[child] = dist[curr] + 1;
                    parent[child] = curr;
                    
                    q.push(child);
                }
            } 
		}
	
		for(int i=0;i<V;i++){
			cout<<"Shortest distance to "<<i<<" is "<<dist[i]<<endl;
		}
	
		if(dest!=-1){
			int temp = dest;
			while(temp!=source){
				cout<<temp<<" <-- ";
				temp = parent[temp];
			}
			cout<<source<<endl;
		}
	}
};

int main(){
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.addEdge(5, 6);
    g.addEdge(4, 5);
    g.addEdge(0, 4);
    g.addEdge(3, 4);

    g.bfs(1, 6);

    return 0;
}