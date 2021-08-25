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

    void bfs(int source){
        queue<int> q;
        bool *visited = new bool[V]{0};

        q.push(source);
        visited[source] = true;

        while(!q.empty()){
            int front = q.front();
            cout << front << endl;
            q.pop();

            for(auto nbr : adjList[front]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
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

    g.bfs(1);

    return 0;
}