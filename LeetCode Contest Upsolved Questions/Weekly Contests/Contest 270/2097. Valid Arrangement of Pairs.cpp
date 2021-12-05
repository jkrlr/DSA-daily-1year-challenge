// https://leetcode.com/problems/valid-arrangement-of-pairs/

// Hard

// Tags - Eulerian Path, Hierholzer's Algorithm, Graph

// What this problem wants to teach me?
// What is Eulerian Graph and how to use it?
// Learn quick and fast, don't spend whole day on a single hard problem, first do all the medium types problems
// Avoid typos as much as you can, otherwise it's hard to debug the large codebase mistakes
// Always pass maximum no. of variables by reference to a function as much as you can => It'll save from TLE

/* Eulerian Graph:
    Conditions:
    1) start == end
    2) Every Edge must be visited exactly once (Vertex can be repeated but any edge shouldn't be repeated)
        i) We can combine 1&2 and say => All vertices should have even degree
    3) All the edges in a graph must be present in a single component.
    4) All other component shouldn't have any edge and hence should be of size 1-vertex only
        ii) We can combine 3&4 and say => All vertices with non-zero degree connected in a component.
                                          Rest all vertices must have 0-degree

    => Visiting a node requires 2 edges to be visited to form a cycle.
    => Graph with No edge is an Euler Graph*/
/* Euler Path : Semi-Eulerian Graph
    Euler Path is a Path that visits every edge exactly once. 
    => Euler Circuit is a euler path that starts and ends at same vertex.

    Semi-Eulerian Graph Conditions:
    1) start != end
    2) Every Edge must be visited exactly once    
        We can combine 1&2 and say => i) Exactly two vertices must have odd degree(start and end vertex)
                                        All other vertices are middle nodes and we need to Enter and Exit => They have even degree
                                     ii) All vertices with non-zero degree are connected.
 */

/* Algorithmic Steps:

    1) Connectivity Check: check if all the edges are present in 1-component only
        Find a node with degree>0:
            If 
                No node found => Euler Graph 
            Else 
                Do DFS and mark all nodes in component.
                Check if any node with degree >0 was unvisited:
                    If true => Not Euler Graph  
    2) Count odd degree nodes: use Adjacency List
        count == 0 => Eulerian Graph 
        count == 2 => Semi-Eulerian Graph 
        count > 2 => Not-Eulerian Graph  */


/* Idea
    if we view each start_i and end_i as nodes in a graph, 
        elements in pairs as (directed) edges in the graph, then the problem is asking us to find a path in the corresponding directed graph.
    the problem ask us to use up all edges, so we are basically asked to find a Eulerian Path, 
        which is a path that walks through each edge exactly once */

/* Some Properties of Eulerian Path
    I will use in[i] (and out[i]) to denote the in (and out) degree of a node i.
    
    Existence:
        A graph has an Eulerian Path if and only if
        we have out[i] == in[i] for each node i. Or
        we have out[i] == in[i] for all nodes i except exactly two nodes x and y, with out[x] = in[x] + 1, out[y] = in[y] - 1.
            this problem guarantees that an Eulerian Path exists. So we don't need to check for its existence here.
    In the first case (out[i] == in[i] for each node i), all Eulerian Paths are also Eulerian Circuits (Eulerian Path with starting point == ending point).
    a node with out[i] == in[i] + 1 must be the starting point of an Eulerian Path (if there exists one).

    Algorithm
        find the starting point of an Eulerian Path.
        if we have out[i] == in[i] for any i, we can start at an arbitrary node.
        perform postorder DFS on the graph, as we "walk" through an edge, we erase (or mark it visited) the walked edge.
        we may reach the same node many times, but we have to pass each edge exactly once.
        We can use vector or stack for erasing edges. */

#include <bits/stdc++.h>
using namespace std;

// Eulerian Path | Time = O(V+E), Space = O(V+E)
class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        int m = pairs.size();
        
        // Eulerian Path
        unordered_map<int, vector<int>> adjList;
        unordered_map<int,int> indegree;
        unordered_map<int,int> outdegree;
        
        // reserve spaces for unordered_map may help in runtime.
        adjList.reserve(m);
        indegree.reserve(m);
        outdegree.reserve(m);
        
        // Build Graph(AdjList)
        for(auto& p: pairs){
            int from = p[0], to = p[1];
            
            adjList[from].push_back(to);
            outdegree[from]++;
            indegree[to]++;
        }
        
        // find starting node
        int start = -1;
        for(auto& [src, nbrs]: adjList){
            if(outdegree[src]-indegree[src]==1)
                start = src;
        }
        
        if(start==-1){ // graph is Eulerian circuit, we can start with any node
            start = adjList.begin()->first;
        }
        
        // Find the Eulerian Path
        vector<vector<int>> ans;
        
        eulerianPath(adjList,ans,start);
        
        // Above ans is in reversed form, so now reverse it to achieve correct output
        reverse(begin(ans), end(ans));
        
        return ans;
    }

private:
    void eulerianPath(unordered_map<int, vector<int>>& adjList, vector<vector<int>>& ans, int src){
        auto& nbrs = adjList[src];
        
        while(!nbrs.empty()){
            int nbr = nbrs.back();
            nbrs.pop_back();
            
            //PostOrder Traversal
            eulerianPath(adjList, ans, nbr);
            
            ans.push_back({src,nbr});
        }
    }
};