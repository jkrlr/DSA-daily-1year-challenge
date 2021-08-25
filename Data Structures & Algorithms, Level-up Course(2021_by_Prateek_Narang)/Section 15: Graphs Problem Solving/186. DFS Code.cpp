// BFS is an iterative algorithm
// DFS is a recursive algorithm

// BFS and DFS both are linear traversals => Time = O(V+E)

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

    void addEdge(int i, int j, bool undir=true){
        adjList[i].push_back(j);
        if(undir){
            adjList[j].push_back(i);
        }
    }

    void dfsHelper(int node, bool *visited){
        visited[node] = true;
        cout << node << ", ";

        for(int nbr :adjList[node]){
            if(visited[nbr]==false){
                dfsHelper(nbr,visited);
            }
        }
    }

    void dfs(int source){
        bool *visited = new bool[V]{false};
        
        // Why Wrappar function is used? - because we can create the visited array once.
        dfsHelper(source, visited);
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

    g.dfs(1);

    return 0;
}