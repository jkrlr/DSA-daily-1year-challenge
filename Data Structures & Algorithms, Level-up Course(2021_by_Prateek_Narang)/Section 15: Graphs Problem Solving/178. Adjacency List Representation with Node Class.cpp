#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;

// This Node class can be a complex object
class Node{
public:
    string name;
    list<string> nbrs;

    Node(string name){
        this->name = name;
    }
};

// Easy to deal with functions within class
class Graph{
    // All nodes
    // Hashmap (string, Node*)
    unordered_map<string, Node*> nodes;

public:
    Graph(vector<string> cities){
        for (auto city : cities){
            nodes[city] = new Node(city);
        }
    }

    void AddEdge(string cityX, string cityY, bool undir=false){
        nodes[cityX]->nbrs.push_back(cityY);

        if(undir){
            nodes[cityY]->nbrs.push_back(cityX);
        }
    }

    void PrintEdgeList(){
        for(auto cityPair : nodes){
            string city = cityPair.first;
            Node *node = cityPair.second;

            cout << city << "-->";
            for(auto nbr: node->nbrs){
                cout << nbr << ", ";
            }
            cout<<endl;
        }
    }
};

int main(){

    vector<string> cities = {"Delhi", "London", "Paris", "New York"};
    Graph g(cities);

    g.AddEdge("Delhi", "London");
    g.AddEdge("New York", "London");
    g.AddEdge("Delhi", "Paris");
    g.AddEdge("Paris", "New York");

    g.PrintEdgeList();

    return 0;
}